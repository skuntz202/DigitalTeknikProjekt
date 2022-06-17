library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Protokol is
    Port ( Clk : in  STD_LOGIC;
           Reset : in  STD_LOGIC;
			  SS_not : in STD_LOGIC;
           SPIdat : in  STD_LOGIC_VECTOR (7 downto 0);
           Shape : inout  STD_LOGIC_VECTOR (7 downto 0);
           Ampl : inout  STD_LOGIC_VECTOR (7 downto 0);
           Freq : inout  STD_LOGIC_VECTOR (7 downto 0);
			  Disp : out STD_LOGIC_VECTOR (19 downto 0);
           Paritet : out  STD_LOGIC;
			  SigEN : out STD_LOGIC);
end Protokol;

architecture Behavioral of Protokol is

--Interne signaler, bland andet forskellige states
type StateType is (Shape_state, Ampl_state, Freq_state, Reset_state, Sync_state, Run_state, Choose_state);
signal State: StateType;
signal DispSel : STD_LOGIC_VECTOR(2 downto 0);
signal temp_Shape, temp_Ampl, temp_freq, ACK, CRC_temp, prev_SPIdat : STD_LOGIC_VECTOR(7 downto 0):=X"00";
--Signaler til at sikre os SpiDat bliver lagt i rigtig rækkefølge.
signal Adr, Data, Crc, Final: STD_LOGIC := '0';

begin
	StateReg: process(Reset, Clk)

	begin
		--Hvis Reset er høj kører vi igennem et reset_state som sætter alle værdier til 0 og går derefter i choose_state
		if Reset = '1' then 
			Paritet <= '0';
			State <= Reset_state;
		elsif clk'event and clk = '1' then
			--Alle værdier opdateres til deres "temp" værdier hver clock
			Shape <= temp_shape;
			Ampl <= temp_ampl;
			Freq <= temp_freq;
			--Prev_SPIdat bruges til at få en tidsforskudt SPIdat, så det er muligt at se hvornår SPIDat ændres.
			Prev_SPIdat <= SPIdat;
			
			if temp_shape /= X"00" and temp_ampl /= X"00" and temp_freq /= X"00" then
				State <= Run_state;
			end if;
			
			if Dispsel = "001" then
				Disp <= X"450" & Shape;
			elsif Dispsel = "010" then
				Disp <= X"4A0" & Ampl;
			elsif Dispsel = "011" then
				Disp <= X"4F0" & Freq;
			elsif Dispsel = "100" then
				Disp <= X"4D000";
			elsif Dispsel = "101" then
				Disp <= X"4C0CC";
			elsif DispSel = "111" then
				Disp <= X"F1230";
			else
				Disp <= X"4FFFF";
			end if;
			
			case State is
				when Reset_state =>
					temp_shape <= X"00";
					temp_ampl <= X"00";
					temp_freq <= X"00";
					Adr <= '0';
					Data <= '0';
					CRC <= '0';
					Final <= '0';
					crc_temp <= X"00";
					ack <= X"00";
					Paritet <= '0';
					DispSel <= "000";
					State <= choose_state;
				
				--Her vælges hvilken værdi skal opdateres henholdsvis, Shape, Ampl, eller Freq afhængigt af den givne adresse.
				when choose_State =>
					DispSel <= "101";
					Adr <= '1';
					Data <= '0';
					CRC <= '0';
					Final <= '0';
					
					if SPIdat = X"01" then	
						State <= Shape_state;
					elsif SPIdat = X"02" then
						State <= Ampl_state;			
					elsif SPIdat = X"03" then
						State <= Freq_state;
					elsif SPIdat = X"04" then
						State <= Sync_state;
					else 
						Paritet <= '0';
					end if;
					
				
				--Her opdateres Shape, og sammenlignes med CRC for at checke paritet
				when Shape_state =>
					Dispsel <= "001";
					if SPIdat /= prev_SPIdat and Adr = '1' then
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
						CRC <= '0';
						Final <= '1';
						if CRC_temp + temp_shape = X"FF" then
							Paritet <= '1';
						end if;
					end if;
					if SPIdat /= Prev_SPIDat and Final = '1' then
						state <= choose_state;
					end if;
					
					
				--Her opdateres Ampl, og sammenlignes med CRC for at checke paritet
				when Ampl_state =>
					DispSel <= "010";
					if SPIdat /= prev_SPIdat and Adr = '1' then
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
						CRC <= '0';
						Final <= '1';
						if CRC_temp + temp_ampl = X"FF" then
							Paritet <= '1';
						end if;
					end if;
					if SPIdat /= Prev_SPIDat and Final = '1' then
						state <= choose_state;
					end if;
						
				
				--Her opdateres Freq, og sammenlignes med CRC for at checke paritet
				when Freq_state =>
					DispSel <= "011";
					if SPIdat /= Prev_spidat and Adr = '1' then
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
						CRC <= '0';
						Final <= '1';
						if CRC_temp + temp_freq = X"FF" then
							Paritet <= '1';
						end if;
					end if;
					if SPIdat /= Prev_SPIDat and Final = '1' then
						state <= choose_state;
					end if;
					
				when Sync_state =>
					DispSel <= "100";
					if SPIdat /= Prev_SPIdat and Adr = '1' then
						if SPIdat = "10101010" then
							Paritet <= '1';
						else 
							Paritet <= '0';
						end if;
						State <= choose_state;
					end if;
				
				when Run_state =>
					DispSel <= "111";
					SigEN <= '1';
					
				end case;	
		end if;
	end process;

--DispMux: Disp <= X"F1230" when DispSel = "111" else
--				  X"4F0" & Freq when DispSel = "011" else
--				  X"4A0" & Ampl when DispSel = "010" else
--				  X"450" & Shape when Dispsel = "001" else
--				  X"4D000" when DispSel = "100" else
--				  X"4C0CC" when DispSel = "101" else
--				  X"FFFFF";
				  


end Behavioral;

