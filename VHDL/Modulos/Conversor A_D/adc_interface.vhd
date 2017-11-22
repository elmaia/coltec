LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;

ENTITY ADC_INTERFACE IS
	PORT 	(
			RESET             : IN STD_LOGIC;                       -- Reset
			SYSCLK            : IN STD_LOGIC;                       -- Clock do sistema
			CLK_260KHZ		    : IN STD_LOGIC;                       -- Clock externo para o ADC
			MOD_ENABLE		    : IN STD_LOGIC;	                      -- Module Enable
			ADC_CSN           : OUT STD_LOGIC;                      -- NOT Chip Select (Sempre em 0 para manter o chip sempre habilitado)
			ADC_CNTRL_DATA    : OUT STD_LOGIC;                      -- DIN signal to ADC (Entrada de comando do ADC)
			ADC_DATA          : IN STD_LOGIC;                       -- DOUT signal from ADC (Saida de dados do ADC)
			ADC_SSTRB         : IN STD_LOGIC;                       -- Strobe output from ADC (avisa que iniciou e terminou a conversão)
			ADC_SHDN          : OUT STD_LOGIC;                      -- Three level Shutdown for ADC (Sempre em 1 para manter o chip sempre ligado)
			DATA              : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)    -- Data (Resultado da conversão)
			);
END ADC_INTERFACE;

ARCHITECTURE ADC_CONT OF ADC_INTERFACE IS

  SIGNAL ADC_RESET      : STD_LOGIC;							                            -- Reset ADC state after each conversion
  SIGNAL START, SEL2, SEL1, SEL0, UNI_BIP, SGL_DIF, PD1, PD0 : STD_LOGIC;	    -- ADC Control characters
  SIGNAL ADC_STATE	    : STD_LOGIC_VECTOR(3 DOWNTO 0);		                    -- State signal used in statemachine to create ADC control writes
  SIGNAL DIG_RESULT	    : STD_LOGIC_VECTOR(7 DOWNTO 0);		                    -- shift register to catch input data from ADC
  SIGNAL SR_CAPTURE	    : STD_LOGIC_VECTOR(9 DOWNTO 0);	                      -- Used to locate the first 8 bits after the falling edge of ADC_SSTRB
  SIGNAL CLK_260KHZ_OLD : STD_LOGIC := '0';                                   -- Usado para controlar o clock de 260KHz

BEGIN

  ADC_SHDN  <= '1';   -- SHUTDOWN' = Nunca desliga o chip

  --Control signals:
  START	  <= '1';		--start conversion
  SEL2	  <= '1';		--
  SEL1	  <= '0';		--Sel2 and not sel1 selects channel 1
  SEL0	  <= '0';		--Dont care
  UNI_BIP	<= '1';		--select unipolar conversion
  SGL_DIF	<= '1';		--select single ended signal
  PD1		  <= '1';		--Fully operational
  PD0		  <= '1';		--External clock mode


  ADC_RESET <= RESET AND MOD_ENABLE;							--Either reset is active or Single LCD write has completed

  --Increment states to generate ADC control characters
  PROCESS(SYSCLK, ADC_RESET)
  BEGIN
    IF ADC_RESET = '0' THEN									--Reset counter to begin write sequesnce
      ADC_STATE <= (OTHERS=>'0');
    ELSE
      IF (RISING_EDGE(SYSCLK)) THEN
      
        -- Monitora o clock de 260KHz
        CLK_260KHZ_OLD <= CLK_260KHZ;
    
        -- Borda de subida no clock de 260KHz
        IF CLK_260KHZ_OLD = '0' AND CLK_260KHZ = '1' THEN
          IF ADC_STATE <= "1000" THEN					--Count up to 8 then stop
            ADC_STATE <= ADC_STATE + 1;
          ELSE
            ADC_STATE <= "1001";
          END IF;
        ELSE
          NULL;
        END IF;
      END IF;
    END IF;
  END PROCESS;


  --ADC controller statemachine
  PROCESS(SYSCLK, RESET)
  BEGIN
    IF RESET = '0' THEN
      DIG_RESULT <= (OTHERS=>'0');
      SR_CAPTURE <= (OTHERS=>'0');
      ADC_CNTRL_DATA <= '0';
      ADC_CSN		     <= '1';
    ELSE
    
      ADC_CSN		     <= '0';
      IF (RISING_EDGE(SYSCLK)) THEN
    
        -- Borda de subida no clock de 260KHz
        IF CLK_260KHZ_OLD = '0' AND CLK_260KHZ = '1' THEN

          -- Registrador de deslocamento que recebe os dados do ADC
          DIG_RESULT(7 DOWNTO 1) <= DIG_RESULT(6 DOWNTO 0);
          DIG_RESULT(0) <= ADC_DATA;
      
          CASE ADC_STATE IS						--Create ADC control signals
            WHEN "0000" =>
              ADC_CNTRL_DATA <= '0';      -- Antes de iniciar, começa com 0
            WHEN "0001" =>
              ADC_CNTRL_DATA <= START;		--'1' start conversion
            WHEN "0010" =>
              ADC_CNTRL_DATA <= SEL2;			--Sel2 and not sel1 selects channel 1
            WHEN "0011" =>
              ADC_CNTRL_DATA <= SEL1;			--Sel2 and not sel1 selects channel 1
            WHEN "0100" =>
              ADC_CNTRL_DATA <= SEL0;			--Dont care
            WHEN "0101" =>
              ADC_CNTRL_DATA <= UNI_BIP;		--select unipolar conversion
            WHEN "0110" =>
              ADC_CNTRL_DATA <= SGL_DIF;		--select single ended signal
            WHEN "0111" =>
              ADC_CNTRL_DATA <= PD1;			--Fully operational
            WHEN "1000" =>
              ADC_CNTRL_DATA <= PD0;			--External clock mode
            WHEN "1001" =>
              ADC_CNTRL_DATA <= '0';			--Reset to Zero
            WHEN OTHERS =>
              NULL;
          END CASE;
        
          -- Borda de descida do SSTRB indica que o dado começou a sair do ADC
          SR_CAPTURE(0) <= ADC_SSTRB;
          SR_CAPTURE(1) <= SR_CAPTURE(0) AND ADC_SSTRB;

          -- Registrador de deslocamento
          -- Quando o bit 9 foi 1, então o dado está no DIG_RESULT
          SR_CAPTURE(9 DOWNTO 2) <= SR_CAPTURE(8 DOWNTO 1);
          
          --Carrega o dado na saída depois que tiver lido os 8 bits
          IF SR_CAPTURE(9) = '1' THEN				
            DATA <= DIG_RESULT;
          ELSE
            NULL;
          END IF;
        ELSE
          NULL;
        END IF;
      
      END IF; -- RISING_EDGE(SYSCLK)
      
    END IF;
  END PROCESS;

END ADC_CONT;