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
			  CRC_out : out STD_LOGIC_VECTOR (7 downto 0);
           SigEN : out  STD_LOGIC);
end Protokol;

architecture Behavioral of Protokol is

type StateType is (Shape_state, Ampl_state, Freq_state, choose_state, Reset_state);
signal State: StateType;
signal temp_Shape, temp_Ampl, temp_freq, ACK, CRC_temp, prev_SPIdat : STD_LOGIC_VECTOR(7 downto 0);
signal Adr, Data, Crc : STD_LOGIC := '0';

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
			CRC_out <= CRC_temp;
			
			if ACK = X"00" then
				SigEN <= '1';
			end if;
			
			case State is
				when Reset_state =>
					temp_shape <= X"00";
					temp_ampl <= X"00";
					temp_freq <= X"00";
					Adr <= '0';
					Data <= '0';
					CRC <= '0';
					crc_temp <= X"00";
					ack <= X"00";
					sigEN <= '0';
					State <= choose_state;
				
				when choose_State =>
					Adr <= '1';
					Data <= '0';
					CRC <= '0';
					if SPIdat = X"01" then	
						State <= Shape_state;
					elsif SPIdat = X"02" then
						State <= Ampl_state;			
					elsif SPIdat = X"03" then
						State <= Freq_state;
					end if;
				
				when Shape_state =>
					if SPIdat /= X"01" and Adr = '1' then
						temp_Shape <= SPIdat;
						Data <= '1';
						Adr <= '0';
					end if;
					if SPIdat /= prev_SPIdat and Data = '1' then
						CRC_temp <= SPIdat;
						CRC <= '1';
						Data <= '0';
					end if;
					if SPIdat /= Prev_SPIdat and CRC = '1' then
						ACK <= SPIdat;
						state <= choose_state;
					end if;
					
					
				
				when Ampl_state =>
					if SPIdat /= X"02" and Adr = '1' then
						temp_Ampl <= SPIdat;
						Data <= '1';
						Adr <= '0';
					end if;
					if SPIdat /= prev_SPIdat and Data = '1' then
						CRC_temp <= SPIdat;
						CRC <= '1';
						Data <= '0';
					end if;
					if SPIdat /= Prev_SPIdat and CRC = '1' then
						ACK <= SPIdat;
						state <= choose_state;
					end if;
				
				when Freq_state =>
					if SPIdat /= X"03" and Adr = '1' then
						temp_Freq <= SPIdat;
						Data <= '1';
						Adr <= '0';
					end if;
					if SPIdat /= prev_SPIdat and Data = '1' then
						CRC_temp <= SPIdat;
						CRC <= '1';
						Data <= '0';
					end if;
					if SPIdat /= Prev_SPIdat and CRC = '1' then
						ACK <= SPIdat;
						state <= choose_state;
					end if;
					
				end case;	
		end if;
	end process;
	
	
	


end Behavioral;

