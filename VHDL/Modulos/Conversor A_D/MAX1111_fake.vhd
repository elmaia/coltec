LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY MAX1111_Fake IS
  PORT(
    SysCLK    :   IN  STD_LOGIC;
    Dados     :   IN STD_LOGIC_VECTOR(7 DOWNTO 0);

    ADC_CSN   : IN STD_LOGIC;
    ADC_CLK   : IN STD_LOGIC;
    ADC_DIN   : IN STD_LOGIC;
    ADC_DOUT  : OUT STD_LOGIC;
    ADC_SSTRB : OUT STD_LOGIC;
    ADC_SHDN  : IN STD_LOGIC
  );
END MAX1111_Fake;

ARCHITECTURE arch OF MAX1111_Fake IS

  CONSTANT strobe : STD_LOGIC_VECTOR(0 TO 23) := "00000000" & "11" & "00000000000000";

  SIGNAL ADC_CLK_old : STD_LOGIC := '0';
  SIGNAL dout   : STD_LOGIC_VECTOR(0 TO 23) := (OTHERS => '0');

BEGIN

  dout <= "00000000" & "00" & Dados & "000000";


  PROCESS(SysClk) 
    VARIABLE contador : NATURAL := 0;
    VARIABLE startB   : BOOLEAN := false;
  BEGIN

    IF (RISING_EDGE(SysCLK)) THEN
      ADC_CLK_old <= ADC_CLK;
      
      -- Se der shutdown, volta ao início
      -- Só opera se o chip estiver selecionado (CS)
      IF (ADC_SHDN = '0' OR ADC_CSN = '1') THEN
        contador := 0;
        startB := false;
      ELSE
      
        -- Faço amonstragem na borda de subida
        IF (ADC_CLK = '1' AND ADC_CLK_old = '0') THEN
          IF (startB = false AND ADC_DIN = '1') THEN
            startB := true;
          END IF;
        END IF;
      
        -- Troco de estado na borda de descida
        IF (ADC_CLK = '0' AND ADC_CLK_old = '1') THEN
          IF (startB AND (CONTADOR < strobe'HIGH)) THEN
            contador := contador + 1;
          END IF;
        END IF;
      END IF;

      ADC_DOUT  <= dout(contador);
      ADC_SSTRB <= strobe(contador);
    END IF;


  END PROCESS;

END arch;