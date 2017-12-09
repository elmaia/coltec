LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY Multiplicador16b IS
  GENERIC(
    NIVEL_ATIVACAO_START: STD_LOGIC := '0';
    NIVEL_ATIVACAO_DONE : STD_LOGIC := '1'
  );
  PORT(
    Clock        : IN  STD_LOGIC;
    Multiplicando: IN  STD_LOGIC_VECTOR(15 DOWNTO 0);
    Multiplicador: IN  STD_LOGIC_VECTOR(15 DOWNTO 0);
    Produto      : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    Start        : IN  STD_LOGIC;
    Done         : OUT STD_LOGIC  
  );
END Multiplicador16b;

ARCHITECTURE arch OF Multiplicador16b IS

  SIGNAL resultado : UNSIGNED(31 DOWNTO 0) := (OTHERS => '0');
  SIGNAL bAtual    : STD_LOGIC;
  SIGNAL b16B      : STD_LOGIC_VECTOR(15 DOWNTO 0) := (OTHERS => '0');
  SIGNAL B         : STD_LOGIC_VECTOR(15 DOWNTO 0) := (OTHERS => '0');
  
  CONSTANT N_BITS  : INTEGER := 16;

BEGIN


  PROCESS(Start,Multiplicador,Clock) 
    VARIABLE i   : NATURAL RANGE 0 TO 18 := 0;
  BEGIN
  
  
    -- Então estiver ativo, reinicia o processo
    IF (Start = NIVEL_ATIVACAO_START) THEN
    
      resultado <= (OTHERS => '0');
      Done <= NOT(NIVEL_ATIVACAO_DONE);
      i    := 0;
      B    <= multiplicador;
      
    ELSE
      -- Se não estiver ativo, então começa a multiplicação
      IF (RISING_EDGE(Clock)) THEN
      
        IF (i /= (N_BITS + 1)) THEN
          i := i + 1;
          DONE <= '0';
          Produto <= std_logic_vector(resultado);
        ELSE
          DONE <= '1';
        END IF;
        
        -- Registrador de deslocamento
        B(15 DOWNTO 1) <= B(14 DOWNTO 0);
        B(0) <= '0';
    
        -- Bit atual do multiplicador
        -- b16B   <= (multiplicador'RANGE => B(15)) AND multiplicando;
        resultado <= (resultado(30 DOWNTO 0) & '0') + UNSIGNED((multiplicador'RANGE => B(15)) AND multiplicando); --(UNSIGNED(Multiplicando AND b16B));
      END IF;
    END IF;
  END PROCESS;


END arch;