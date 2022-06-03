library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ShiftReg is
    Port ( Clk : in  STD_LOGIC;
           D : in  STD_LOGIC;
           Reset : in  STD_LOGIC;
			  SS_not : in STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (7 downto 0));
end ShiftReg;

architecture Behavioral of ShiftReg is
	Signal Reg_val : STD_LOGIC_VECTOR(7 downto 0);
begin

	Shift_reg: process(Clk, Reset)
	begin

		if reset = '1' then
			Reg_val <= X"00";
		elsif clk'event and clk = '1' then
			if SS_not = '0' then
				Reg_val <= Reg_val(6 downto 0) & D;
			end if;
		end if;
	end process;
	
	Q <= Reg_val;

end Behavioral;

