library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity putin is
    Port ( Clk : in  STD_LOGIC;
           Reset : in  STD_LOGIC;
           BTN0 : in  STD_LOGIC;
           BTN1 : in  STD_LOGIC;
           BTN2 : in  STD_LOGIC;
           SW : in  STD_LOGIC_VECTOR (7 downto 0);
           Shape : inout  STD_LOGIC_VECTOR (7 downto 0);
           Ampl : inout  STD_LOGIC_VECTOR (7 downto 0);
           Freq : inout  STD_LOGIC_VECTOR (7 downto 0);
           Disp : out  STD_LOGIC_VECTOR (19 downto 0);
           SigEN : out  STD_LOGIC);
end putin;

architecture Behavioral of putin is
signal DispSel: std_logic_vector(1 downto 0);
type StateType is (ShapeS, AmplS, FreqS, RunS);
signal State: StateType; 

begin

StateReg: process(clk, reset)
begin
	if reset = '1' then
		State <= ShapeS;
	elsif Clk'event and Clk = '1' then
	 SigEN <= '0';
	 DispSel <= "00";
			
	Case state is 
		when Shapes =>
			DispSel <= "11";
			if BTN0 = '1' then
				Shape <= SW;
			elsif BTN1 = '1' then
				State <= Ampls;
			elsif BTN2 = '1' then
				State <= RunS;
			else 
				State <= ShapeS;
			end if;
			
		when AmplS =>
			DispSel <= "10";
			if BTN0 = '1' then
				Ampl <= SW;
			elsif BTN1 = '1' then
				State <= Freqs;
			elsif BTN2 = '1' then
				State <= RunS;
			else 
				State <= Ampls;
			end if;
			
		when FreqS =>
			DispSel <= "01";
			if BTN0 = '1' then
				Freq <= SW;
			elsif BTN1 = '1' then
				State <= ShapeS;
			elsif BTN2 = '1' then
				State <= RunS;	
			else 
				State <= FreqS;
			end if;
		
		when Runs =>
			DispSel <= "00";
			SigEN <= '1';
			if BTN1 = '1' then
				State <= ShapeS;
			end if;
		
		end case;
		

	end if;
end process;

DispMux: Disp <= X"F1230" when DispSel = "0" else
				  X"4F0" & Freq when DispSel = X"1" else
				  X"4A0" & Ampl when DispSel = X"2" else
				  X"450" & Shape;

end Behavioral;

