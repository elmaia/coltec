----------------------------------------------------------------------------------
-- Company: 
-- Engineer:       (c) Jeppe Madsen
-- 
-- Create Date:    12:37:35 12/04/2007 
-- Design Name: 
-- Module Name:    Divisor_nBits - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Revision 0.02 - Signals' names translated to Portuguese-Brazil.
-- Additional Comments: This module was created by Jeppe Madsen, but the words were written
--                      in German, so I changed them to Portuguese in order to make them
--                      understandable to my students. (Leandro Maia)
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Divisor_nBits is
    generic(N: integer := 5);                               -- Número de bits do divisor
    Port ( Dividendo : in std_logic_vector(N-1 downto 0);   -- Dividendo de N bits
           Divisor   : in std_logic_vector(N-1 downto 0);   -- Divisor de N bits
           Start     : in std_logic;                        -- Sinal que espera um pulso positivo para começar a divisão
           Clk       : in std_logic;                        -- Clock para divisão sequencial
           Quociente : out std_logic_vector(N-1 downto 0);  -- Quociente de N bits
           Resto     : out std_logic_vector(N-1 downto 0);  -- Resto de N bits
           Done      : out std_logic);                      -- Sinal que indica que a divisão terminou (Nível lógico alto)
end Divisor_nBits;

architecture Behavioral of Divisor_nBits is
   signal Q:     std_logic_vector(N*2-1 downto 0);
   signal Diff:  std_logic_vector(N     downto 0);
  signal Count: integer range 0 to N+1;
begin
   Diff <= ('0'&Q(N*2-2 downto N-1)) - ('0'&Divisor);
   
  process( Clk, Start)
  begin
      if Start = '0' then
       Q <= conv_std_logic_vector(0,N) & Dividendo;
    elsif Rising_edge( Clk) then
       if Count<N then
          if Diff(N)='1' then
               Q <= Q(N*2-2 downto 0) & '0';
         else
            Q <= Diff(N-1 downto 0) & Q(N-2 downto 0) & '1';
        end if;
      end if;
    end if;
  end process;

  process(Clk)
  begin
     if Start = '0' then
       Count <= 0;
    elsif Rising_edge( Clk) then
       if Count<N then
         Count <= Count+1;
      end if;
    end if;
  end process;

   Quociente <= Q(  N-1 downto 0);
  Resto   <= Q(N*2-1 downto N);
  
  Done <= '1' when Count=N else '0';
end Behavioral;