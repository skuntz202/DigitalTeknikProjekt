library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Protokol is
    Port ( Clk : in  STD_LOGIC;
           Reset : in  STD_LOGIC;
           SPIdat : in  STD_LOGIC_VECTOR (7 downto 0);
           Shape : out  STD_LOGIC_VECTOR (7 downto 0);
           Ampl : out  STD_LOGIC_VECTOR (7 downto 0);
           Freq : out  STD_LOGIC_VECTOR (7 downto 0);
           SigEN : out  STD_LOGIC);
end Protokol;

architecture Behavioral of Protokol is

type StateType is (Shape_state, Ampl_state, Freq_state, choose_state, Reset_state);
signal State: StateType;
signal temp_Shape, temp_Ampl, temp_freq, ACK, CRC, prev_SPIdat : STD_LOGIC_VECTOR(7 downto 0);
signal hold_up : STD_LOGIC;

begin
	StateReg: process(Reset, Clk)
	begin
		if Reset = '1' then 
			State <= Reset_state;
		elsif clk'event and clk = '1' then
			
			Shape <= temp_shape;
			Ampl <= temp_ampl;
			Freq <= temp_freq;
			Prev_SPIdat <= SPIdat;
			
			if ACK = X"00" then
				SigEN <= '1';
			end if;
			
			case State is
				when Reset_state =>
					temp_shape <= X"00";
					temp_ampl <= X"00";
					temp_freq <= X"00";
					hold_up <= '0';
					State <= choose_state;
				
				when choose_State =>
					if SPIdat = X"01" then	
						State <= Shape_state;
					elsif SPIdat = X"02" then
						State <= Ampl_state;			
					elsif SPIdat = X"03" then
						State <= Freq_state;
					end if;
				
				when Shape_state =>
					if SPIdat /= X"01" then
						temp_Shape <= prev_SPIdat;
						hold_up <= '1';
						if SPIdat /= temp_shape and hold_up = '1' then
							hold_up <= '0';
							CRC <= SPIdat;
							--wait for 10 ms;
							ACK <= X"00";
							state <= choose_state;
						end if;
					end if;
				
				when Ampl_state =>
					if SPIdat /= X"02" then
						temp_Ampl <= prev_SPIdat;
						hold_up <= '1';
						if SPIdat /= temp_Ampl and hold_up = '1' then
							hold_up <= '0';
							CRC <= SPIdat;
							--wait for 10 ms;
							ACK <= X"00";
							state <= choose_state;
						end if;
					end if;
				
				when Freq_state =>
					if SPIdat /= X"03" then
						temp_Freq <= SPIdat;
						hold_up <= '1';
						if SPIdat /= temp_Freq and hold_up = '1' then
							hold_up <= '0';
							CRC <= SPIdat;
							--wait for 10 ms;
							ACK <= X"00";
							state <= choose_state;
						end if;
					end if;
					
				end case;	
		end if;
	end process;
	
	
	


end Behavioral;

