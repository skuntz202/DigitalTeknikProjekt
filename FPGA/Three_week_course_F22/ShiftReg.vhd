library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ShiftReg is
    Port ( Clk : in  STD_LOGIC;
           D : in  STD_LOGIC;
           Reset : in  STD_LOGIC;
			  SS_not : in STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (7 downto 0));
end ShiftReg;

--Register der skifter mod venstre, altså fylder op bagfra
architecture Behavioral of ShiftReg is
	Signal Reg_val : STD_LOGIC_VECTOR(7 downto 0);
begin

	Shift_reg: process(Clk, Reset)
	begin

		if reset = '1' then
			Reg_val <= X"00";
		elsif clk'event and clk = '1' then
			--SS_not skal være lav får vi opdatere registeret
			if SS_not = '0' then
				Reg_val <= Reg_val(6 downto 0) & D;
			end if;
			--Når SS_not ikke længere er lav opdatere vi værdien af Q
			if SS_not = '1' then
				Q <= Reg_val;
			end if;
		end if;
	end process;
	
	
end Behavioral;

