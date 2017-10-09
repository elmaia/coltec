-- *************************************************************************************************
-- * Module: Debounce                                                                              *
-- * Description: Module that performs the debounce of a signal coming from a button in order to   *
-- *              compensate the noise caused by the bounce of the same.                           *
-- *                                                                                               *
-- * Author: Leandro Maia Silva                                                                    *
-- * Created Date  : 2017-10-09                                                                    *
-- *                                                                                               *
-- * Revision:                                                                                     *
-- * Revision 0.01 - File created.                                                                 *
-- *                                                                                               *
-- *************************************************************************************************

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY Debounce IS
  GENERIC (
    INITIAL_VALUE: STD_LOGIC := '1';
    CICLOS_ENTRE_AMOSTRAGENS : INTEGER := 3333000;
    NUMERO_AMOSTRAGENS : INTEGER RANGE 2 TO INTEGER'HIGH := 8
  );
  PORT(
    clk     : IN  STD_LOGIC; -- System clock
    bnt     : IN  STD_LOGIC; -- Button signal (which bounces)
    bnt_filt: OUT STD_LOGIC  -- Button signal after debouncing process
  );
END ENTITY;

ARCHITECTURE arch OF Debounce IS

  TYPE estados IS (Amostrar, NaoAmostrar);
  SIGNAL regDesl : STD_LOGIC_VECTOR((NUMERO_AMOSTRAGENS-1) DOWNTO 0) := (OTHERS => '0');
  SIGNAL filtro : STD_LOGIC := INITIAL_VALUE;
  
  CONSTANT TUDO_1 : STD_LOGIC_VECTOR((NUMERO_AMOSTRAGENS-1) DOWNTO 0) := (OTHERS => '1');
  CONSTANT TUDO_0 : STD_LOGIC_VECTOR((NUMERO_AMOSTRAGENS-1) DOWNTO 0) := (OTHERS => '0');

BEGIN

  PROCESS(clk)  IS
    VARIABLE estado : estados := Amostrar;
    VARIABLE count : INTEGER := 0;
  BEGIN
  
    IF (RISING_EDGE(clk)) THEN
      CASE estado IS
    
        WHEN Amostrar =>
        
            -- Registrador de deslocamento
            regDesl((NUMERO_AMOSTRAGENS-2) DOWNTO 0) <= regDesl((NUMERO_AMOSTRAGENS-1) DOWNTO 1);
            regDesl((NUMERO_AMOSTRAGENS-1)) <= bnt;
          
            -- Verifica se o sinal está estável
            IF (regDesl = TUDO_1) THEN
              filtro <= '1';
            ELSIF (regDesl = TUDO_0) THEN
              filtro <= '0';
            ELSE
              NULL;
            END IF;

            -- Altera o estado para Não Amostrar
            estado := NaoAmostrar;
    
        WHEN NaoAmostrar =>
        
          -- Basta contar o tempo        
          IF (count = CICLOS_ENTRE_AMOSTRAGENS) THEN
            count := 0;
            estado := Amostrar;
          ELSE
            count := count + 1;
            estado := NaoAmostrar;
          END IF;
        
      END CASE;
      
    END IF;

  END PROCESS;
  
  bnt_filt <= filtro;
  
END;