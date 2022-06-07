library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Freq_calc is
    Port (
			  Freq : in  STD_LOGIC_VECTOR (7 downto 0);
			  Clk : in STD_LOGIC;
			  Reset : in STD_LOGIC;
           Ampl : in  STD_LOGIC_VECTOR (7 downto 0);
           TimeDiv : out  integer);
end Freq_calc;

architecture Behavioral of Freq_calc is

Signal Freq_int : integer:=1;
Signal Ampl_int : integer:=1;
Signal PulseWidth : integer:=1;
Signal Trek : integer:=1;

begin
Calc: process(Reset, Clk)
begin
	if reset = '1' then
		TimeDiv <= 1;
	elsif Clk'event and Clk = '1' then
		Freq_int <= to_integer(unsigned(Freq));
		Ampl_int <= to_integer(unsigned(Ampl))*2;
		
		if Freq_int /= 1 or Ampl_int /= 1 then
			PulseWidth <= 512/Ampl_int;
			Trek <= 1024/Freq_int ;
		end if;
		if PulseWidth /= 1 or Ampl_int /= 1 then
			TimeDiv <= PulseWidth * Trek;
		end if;
	end if;
end process;

end Behavioral;

