library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity putin is
    Port ( Clk : in  STD_LOGIC;
           Reset : in  STD_LOGIC;
           BTN0 : in  STD_LOGIC;
           BTN1 : in  STD_LOGIC;
           BTN2 : in  STD_LOGIC;
           SW : in  STD_LOGIC_VECTOR (7 downto 0);
           Shape : out  STD_LOGIC_VECTOR (1 downto 0);
           Ampl : out  STD_LOGIC_VECTOR (7 downto 0);
           Freq : out  STD_LOGIC_VECTOR (7 downto 0);
           Disp : out  STD_LOGIC_VECTOR (19 downto 0);
           SigEN : out  STD_LOGIC);
end putin;

architecture Behavioral of putin is

component BTNdb
  port( Reset, Clk: in std_logic;
        BTNin: in std_logic;
        BTNout: out std_logic);
end component;

signal BTN1db, BTN2db, ShapeEN, AmplEN, FreqEN: std_logic;
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
	  ShapeEN <= '0';
	  AmplEN <= '0';
	  FreqEN <= '0';
	  DispSel <= "00";
	  state <= ShapeS;
	  case state is
		 when ShapeS =>
			ShapeEN <= BTN0;
			DispSel <= "11";
			if BTN2db = '1' then
			  State <= RunS;
			elsif BTN1db =	'1' then
			  state <= AmplS;
			else
			  state <= ShapeS;
			end if;

		 when AmplS =>
			AmplEN <= BTN0;
			DispSel <= "10";
			if BTN2db = '1' then
			  State <= RunS;
			elsif BTN1db =	'1' then
			  State <= FreqS;
			else
			  State <= AmplS;
			end if;

		 when FreqS =>
			FreqEN <= BTN0;
			DispSel <= "01";
			if BTN2db = '1' then
			  State <= RunS;
			elsif BTN1db =	'1' then
			  State <= ShapeS;
			else
			  State <= FreqS;
			end if;

		 when RunS =>
			SigEN <= '1';
			DispSel <= "00";
			if BTN2db = '1' then
			  State <= ShapeS;
			else
			  State <= RunS;
			end if;
	end case;	
	end if;
	
end process;

Deb1: BTNdb port map (Reset => Reset, Clk => Clk, BTNin => BTN1, BTNout => BTN1db);

Deb2: BTNdb port map (Reset => Reset, Clk => Clk, BTNin => BTN2, BTNout => BTN2db);

end Behavioral;

