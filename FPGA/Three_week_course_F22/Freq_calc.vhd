library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Clock_select is
    Port (
			  Freq : in  STD_LOGIC_VECTOR (7 downto 0);
			  Clk : in STD_LOGIC;
			  Reset : in STD_LOGIC;
           Ampl : in  STD_LOGIC_VECTOR (7 downto 0);
			  Shape : in STD_LOGIC_VECTOR (7 downto 0);
           TimeDiv : out  integer);
end Clock_select;

architecture Behavioral of Clock_select is

--Interne signaler der holder styr på Integer konverteringer
Signal Freq_int : integer:=1;
Signal Ampl_int : integer:=1;
Signal PulseWidth : integer;
Signal Trek : integer;
--Konstante værdier
Signal two_fifty_five : STD_LOGIC_VECTOR(7 downto 0);

--Funktion til at dividere to tal med størrelsen 8 bit
Function division(taeller: STD_LOGIC_VECTOR; naevner: STD_LOGIC_VECTOR) return STD_LOGIC_VECTOR is
	Variable Dend, Dsor: STD_LOGIC_VECTOR(15 downto 0);
	Variable RES: STD_LOGIC_VECTOR(7 downto 0);
	Variable ResLsb: STD_LOGIC;
	Variable Index: integer range 0 to 9;
begin
	Res := "00000000";
	Dend:= "00000000" & taeller;
	Dsor :=  naevner & "00000000";    
	Index := 0;
	ResLsb := '0';
	 
	while Index < 9 loop      
		if Dend >= Dsor then
			ResLsb := '1';
			Dend := Dend - Dsor;
		else
			ResLsb := '0';
		end if;
		Res := Res(6 downto 0) & ResLsb;
		Dsor := '0' & Dsor(15 downto 1);
		Index := Index + 1;
	end loop;
	return Res;
end function;	
	

begin
Calc: process(Reset, Clk)
begin
	if reset = '1' then
		TimeDiv <= 1;
	elsif Clk'event and Clk = '1' then
		--Freq og Ampl bliver lavet til integers og konstanter opdateres
		if Freq = X"00" or Ampl = X"00" then
			Freq_int <= 1;
			Ampl_int <= 1;
		else
			Freq_int <= to_integer(unsigned(Freq));
			Ampl_int <= to_integer(unsigned(Ampl));
		end if;
		two_fifty_five <= X"FF";
		
		if Shape = X"01" then -- Sine wave
			TimeDiv <= 101-Freq_int;
			
		elsif Shape = X"02" then -- Triangle wave
			if Freq_int /= 1 or Ampl_int /= 1 then
				--For at holde en konstant pulsbredde bliver denne division lavet
				PulseWidth <= to_integer(unsigned(division(two_fifty_five,Ampl)));
				--PulseWidth 
				--Frekvens justering
				Trek <= 101-Freq_int;
			end if;
			--Checker om Pulsewidth eller Ampl er forskellig for en,
			--Og checker derefter om enten Pulsewidth eller Trek er = 0
			if PulseWidth /= 1 or Ampl_int /= 1 then
				if PulseWidth = 0 or Trek = 0 then
					TimeDiv <= 1;
				else
					TimeDiv <= PulseWidth * Trek * 2;
				end if;
			end if;
			
		elsif Shape = X"03" then -- Square wave
			TimeDiv <= 101-Freq_int;
		end if;
	end if;
end process;			 

end Behavioral;

