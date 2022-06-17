library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Clock_select is
    Port (
			  Freq : in  STD_LOGIC_VECTOR (7 downto 0);
			  Clk : in STD_LOGIC;
			  Reset : in STD_LOGIC;
			  sigEN : in STD_LOGIC;
           Ampl : in  STD_LOGIC_VECTOR (7 downto 0);
			  Shape : in STD_LOGIC_VECTOR (7 downto 0);
           TimeDiv : out  integer);
end Clock_select;

architecture Behavioral of Clock_select is

--Interne signaler der holder styr på Integer konverteringer
Signal Freq_int : integer:=1;
Signal Ampl_int : integer:=1;
Signal PulseWidth : integer:=1;
Signal Trek : integer:=1;
--Konstante værdier
--Signal two_fifty_five : STD_LOGIC_VECTOR(7 downto 0);


begin
Calc: process(Reset, Clk)
begin
	if reset = '1' then
		TimeDiv <= 1;
	elsif Clk'event and Clk = '1' then
		--Freq og Ampl bliver lavet til integers og konstanter opdateres
		
		if to_integer(unsigned(Freq)) > 100 or to_integer(unsigned(Freq)) = 0 then
				Freq_int <= 100;
		else
				Freq_int <= to_integer(unsigned(Freq));
		end if;
		
		if to_integer(unsigned(Ampl)) = 0 then	
			Ampl_int <= 255;
		else 
			Ampl_int <= to_integer(unsigned(Ampl));
		end if;
		
		--PulseWidth 
		--Frekvens justering
		PulseWidth <= 256-Ampl_int;
		Trek <= 101-Freq_int;
		

		
		if sigEN = '1' then
			if Shape = X"01" then -- Sine wave
				TimeDiv <= Trek;
				
			elsif Shape = X"02" then -- Triangle wave
				--TimeDiv <= PulseWidth * Trek;
				TimeDiv <= 1;
				
			elsif Shape = X"03" then -- Square wave
				TimeDiv <= Trek;
			end if;
		
		else
			TimeDiv <= 1;
		end if;
	end if;
		
end process;			 

end Behavioral;

