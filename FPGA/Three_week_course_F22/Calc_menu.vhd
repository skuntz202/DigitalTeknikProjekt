library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Calc_menu is
    Port ( Reset : in  STD_LOGIC;
           Clk : in  STD_LOGIC;
           Enter : in  STD_LOGIC;
           Operation : in  STD_LOGIC;
           Func : in  STD_LOGIC;
           DataIn : in  STD_LOGIC_VECTOR(7 downto 0);
           calcval_1 : in  STD_LOGIC_VECTOR(15 downto 0);
           DispData : out  STD_LOGIC_VECTOR(15 downto 0);
           Tilstand : out  STD_LOGIC_VECTOR(7 downto 0);
           Start : out  STD_LOGIC;
           Done : in  STD_LOGIC;
           OpCode : out  STD_LOGIC_VECTOR(2 downto 0);
           In1 : out  STD_LOGIC_VECTOR(7 downto 0);
           In2 : out  STD_LOGIC_VECTOR(7 downto 0));
end Calc_menu;

architecture Behavioral of Calc_menu is
-- Definetion af interne signaler og forskellige states.
type StateType is (A,B,C,Reset_state,Op_state);
signal State: StateType;
signal temp_in1, temp_in2: STD_LOGIC_VECTOR(7 downto 0) := "00000000";
signal temp_opcode : STD_LOGIC_VECTOR(2 downto 0) := "000";
signal func_hold, Start_hold: STD_LOGIC := '0';

begin
	StateReg: process(Reset,Clk)
	begin
-- Hvis vi klikker paa "reset" hopper vi i vores "Reset_state" som saetter alle vores vaerdier til 0,
-- Og gaar derefter i State "A", som ogsaa er vores initial state.
		if Reset = '1' then 
			state <= Reset_state;
			
		elsif clk'event and clk = '1' then
-- In1, In2 og Opcode saettes til en "temp" vaerdi, for at undgaa latches
		In1 <= temp_In1;
		In2 <= temp_In2;
		Opcode <= temp_Opcode;
		
-- Hvis der kliikes paa "Operation" saetter vi Start til 1, state til "Op_state" og "Start_hold" til 1,
-- hvilket soerger for at vi ikke faar sat "start" til 0 for tidligt.
		if Operation = '1' then
			Start <= '1';
			State <= Op_state;
			Start_hold <= '1';
		elsif Start_hold = '0' then 
			Start <= '0';
		else
			Start <= Start_hold;
		end if;
		
		case State is 
			when Reset_state =>
				In1 <= "00000000";
				In2 <= "00000000";
				OpCode <= "000";
				DispData <="0111111111111111";
				State <= A;
				temp_in1 <= "00000000";
				temp_in2 <= "00000000";
				temp_opCode <= "000";
				Tilstand <= "11111111";
				Start <= '0';
				func_hold <= '0';
				Start_hold <= '0';
				
			when A =>
-- Naar vi er i tilstand A, viser vi det ved at taende dioden laengst mod hoejre, og DisplayData, som styrer vores SevenSegmentdisplay,
-- saettes til at vaere "temp_in1" som til at starte med er 0
				Tilstand <= "00000001";
				DispData <= "00000000" & temp_in1;
				if enter = '1' then
-- Klikkes der nu paa "enter" opdateres In1 og temp_in1 til at vaere "data_in", som er givet af brugeren med de forskellige switches.
					temp_in1 <= DataIn;
					In1 <= DataIn;
					
				end if;
				if func = '1' then
-- Klikkes der paa "func" saettes tilstanden kort til at den diode laengst mod venstre lyser, og et signal "func_hold" saettes hoejt.
-- Dette er for at sikre os at vi foerst skifter state naar func knappen slippes, og vi skifter herefter til state B.
					Tilstand <= "10000000";
					func_hold <= '1';
				end if;
				if func_hold = '1' and func = '0' then
					State <= B;
					func_hold <= '0';
				end if;
				
			when B =>
-- Og samme procedure foregaar i State B.
				Tilstand <= "00000010";
				DispData <= "00000000" & temp_in2;
				if enter = '1' then
					In2 <= DataIn;
					temp_in2 <= DataIn;
					
				end if;
				if func = '1' then
					Tilstand <= "10000000";
					func_hold <= '1';
				end if;
				if func_hold = '1' and func = '0' then
					State <= C;
					func_hold <= '0';
				end if;
				
			when C =>
-- Og ligesaa i C.
				Tilstand <= "00000100";
				DispData <= "0000000000000" & temp_opcode;
				if enter = '1' then
					OpCode <= DataIn(2 downto 0);
					temp_opcode <= DataIn(2 downto 0);
					
				end if;
				if func = '1' then
					Tilstand <= "10000000";
					func_hold <= '1';
				end if;
				if func_hold = '1' and func = '0' then
					State <= A;
					func_hold <= '0';
				end if;
				
			when Op_state =>
-- I Op_state displayer vi vaerdien som vi faar fra "Calc_data" modulet og taender hver anden diode
				DispData <= calcval_1;
				Tilstand <= "10101010";
				if func = '1' and done = '1' then 
-- Naar vores udregning er faerdig og brugeren klikker paa "func" saetter vi det naeste state til at vaere reset_state, hvor at vi herefter gaar til state A.
					State <= reset_state;
				end if;
			end case;
		end if;
	end process;

		
		
				
				

end Behavioral;

