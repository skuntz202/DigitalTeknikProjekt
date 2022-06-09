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

Signal Freq_int : integer:=1;
Signal Ampl_int : integer:=1;
Signal PulseWidth : integer:=1;
Signal Trek : integer:=1;
Signal Timed : integer := 1;
Signal two_fifty_five : STD_LOGIC_VECTOR(7 downto 0);
Signal ninety_seven : STD_LOGIC_VECTOR(7 downto 0);
Signal fifty_k : STD_LOGIC_VECTOR(15 downto 0);

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

Function big_division(taeller: STD_LOGIC_VECTOR; naevner: STD_LOGIC_VECTOR) return STD_LOGIC_VECTOR is
	Variable Dend, Dsor: STD_LOGIC_VECTOR(15 downto 0);
	Variable RES: STD_LOGIC_VECTOR(7 downto 0);
	Variable ResLsb: STD_LOGIC;
	Variable Index: integer range 0 to 9;
begin
	Res := "00000000";
	Dend:= taeller;
	Dsor := naevner & X"00";    
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
		Freq_int <= to_integer(unsigned(Freq));
		Ampl_int <= to_integer(unsigned(Ampl));
		two_fifty_five <= X"FF";
		ninety_seven <= X"61";
		fifty_k <= X"C350";
		
		if Shape = X"01" then -- Sine wave
			TimeDiv <= 1;
			
		elsif Shape = X"02" then -- Triangle wave
			if Freq_int /= 1 or Ampl_int /= 1 then
				--PulseWidth <= 256/Ampl_int;
				--Trek <= 1024/Freq_int ;
				PulseWidth <= to_integer(unsigned(division(two_fifty_five,Ampl)))*2;
	
				if Freq_int >= 97 then
					Trek <= 1;
				else 
					Trek <= to_integer(unsigned(division(Ninety_seven,Freq)));
				end if;
				
			end if;
			if PulseWidth /= 1 or Ampl_int /= 1 then
				if PulseWidth = 0 or Trek = 0 then
					TimeDiv <= 1;
				else
					TimeDiv <= PulseWidth * Trek;
				end if;
			end if;
			
		elsif Shape = X"03" then -- Square wave
			if Freq_int /= 1 then
				Timed <= to_integer(unsigned(big_division(fifty_k,Freq)));
				if Timed = 0 then
					TimeDiv <= 1;
				else 
					TimeDiv <= Timed;
				end if;
			end if;
		end if;
	end if;
end process;			 

end Behavioral;

