-- *************************************************************************************************
-- * Module: PWM                                                                                   *
-- * Description: Module that generates a PWM wave using the number of clocks especified in        *
-- *              period and duty parameters.                                                      *
-- *                                                                                               *
-- * Author: Leandro Maia Silva                                                                    *
-- * Created Date  : 2016-12-18                                                                    *
-- * Last change   : 2017-10-08                                                                    *
-- *                                                                                               *
-- * Revision:                                                                                     *
-- * Revision 0.01 - File created.                                                                 *
-- * Revision 0.02 - Initial PWM value                                                             *
-- *                                                                                               *
-- *************************************************************************************************

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY PWM IS
  GENERIC(
    PERIOD: INTEGER := 66660000;
    INITIAL_VALUE: STD_LOGIC := '1'
  );
  PORT(
    clk : IN  STD_LOGIC;
    duty: IN  INTEGER;
    pwm : OUT STD_LOGIC  
  );
END ENTITY;

ARCHITECTURE arch OF PWM IS

  SIGNAL saida : STD_LOGIC := INITIAL_VALUE;

BEGIN

  PROCESS(clk)
    VARIABLE count : INTEGER := 0;
  BEGIN
  
    IF (RISING_EDGE(clk)) THEN
    
      -- Se ainda não passou o duty cycle, então a saída é 1
      IF (count < duty) THEN
        saida <= INITIAL_VALUE;
      ELSE
        saida <= NOT(INITIAL_VALUE);
      END IF;  
      
      -- Se não chegou no perído, incrementa
      IF (count = (PERIOD-1)) THEN
        couNt := 0;
      ELSE
        count := count + 1;
      END IF;
  
    END IF;  
  
  END PROCESS;
  
  pwm <= saida;

END;