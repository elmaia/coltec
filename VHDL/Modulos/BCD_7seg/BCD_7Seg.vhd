-- *************************************************************************************************
-- * Module: BCD_7seg                                                                              *
-- * Description: Module that converts a single BCD digit into its representation in a 7 segments  *
-- *              display. When ANODO_COMUM is true, it means that the 7-segments are turned on    *
-- *              with 0-logical (GND), otherwise, 7-segments are turned on with 1-logical (VCC).  *
-- *                                                                                               *
-- * Author: Leandro Maia Silva                                                                    *
-- * Created Date  : 2016-12-18                                                                    *
-- *                                                                                               *
-- * Revision:                                                                                     *
-- * Revision 0.01 - File created.                                                                 *
-- *                                                                                               *
-- *************************************************************************************************

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY BCD_7seg IS
  GENERIC(ANODO_COMUM: BOOLEAN := true);
  PORT(
    BCD: IN  STD_LOGIC_VECTOR(3 DOWNTO 0);
    SEG: OUT STD_LOGIC_VECTOR(6 DOWNTO 0)
  );
END BCD_7seg;

ARCHITECTURE arch OF BCD_7seg IS

  SIGNAL saidaAnodoComum : STD_LOGIC_VECTOR(6 DOWNTO 0);

BEGIN

  WITH BCD select saidaAnodoComum <=
    "0000001" when "0000",
    "1001111" when "0001",
    "0010010" when "0010",
    "0000110" when "0011",
    "1001100" when "0100",
    "0100100" when "0101",
    "0100000" when "0110",
    "0001111" when "0111",
    "0000000" when "1000",
    "0000100" when "1001",
    "1111111" when others;
  
  SEG <= saidaAnodoComum WHEN ANODO_COMUM ELSE NOT(saidaAnodoComum);

END arch;