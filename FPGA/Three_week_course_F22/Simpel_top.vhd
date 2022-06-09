library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;

entity SigGenSpiControl is
    Port ( SCK : in  STD_LOGIC;
           MOSI : in  STD_LOGIC;
			  SS_not : in STD_LOGIC;
			  Reset : in STD_LOGIC;
			  SigEN : in STD_LOGIC;
			  output : out STD_LOGIC;
			  Paritet : out STD_LOGIC);
end SigGenSpiControl;

architecture Behavioral of SigGenSpiControl is

Signal SPIdat_sig : STD_LOGIC_VECTOR(7 downto 0);
Signal Shape_sig : STD_LOGIC_VECTOR(7 downto 0);
Signal Ampl_sig : STD_LOGIC_VECTOR(7 downto 0);
Signal Freq_sig : STD_LOGIC_VECTOR(7 downto 0);
Signal Freq_Clk : STD_LOGIC;
Signal TimePP : Integer;



Component ShiftReg is
	port(
		Clk: in STD_LOGIC;
		D : in STD_LOGIC;
		Reset : in STD_LOGIC;
		SS_not : in STD_LOGIC;
		Q : out STD_LOGIC_VECTOR(7 downto 0));
end component ShiftReg;

Component Protokol is
    Port ( Clk : in  STD_LOGIC;
           Reset : in  STD_LOGIC;
           SPIdat : in  STD_LOGIC_VECTOR (7 downto 0);
           Shape : out  STD_LOGIC_VECTOR (7 downto 0);
           Ampl : out  STD_LOGIC_VECTOR (7 downto 0);
           Freq : out  STD_LOGIC_VECTOR (7 downto 0);
           Paritet : out  STD_LOGIC);
end component Protokol;

Component PWM is
    Port ( Clk : in  STD_LOGIC;
           Reset : in  STD_LOGIC;
           Shape : in  STD_LOGIC_VECTOR (7 downto 0);
           Ampl : in  STD_LOGIC_VECTOR (7 downto 0);
           Freq : in  STD_LOGIC_VECTOR (7 downto 0);
           SigEN : in  STD_LOGIC;
           PWMout : out  STD_LOGIC);
end component PWM;

component DivClk is
    port ( 
       Reset: in STD_LOGIC;     -- Global Reset (BTN1)
       Clk: in STD_LOGIC;     -- Master Clock (50 MHz)
       TimeP: in integer;     -- Time periode of the divided clock (50e3)
       Clk1: out STD_LOGIC);   -- Divided clock1 (1 kHz)
end component DivClk;

component Clock_select is
    Port (
			  Freq : in  STD_LOGIC_VECTOR (7 downto 0);
			  Clk : in STD_LOGIC;
			  Reset : in STD_LOGIC;
           Ampl : in  STD_LOGIC_VECTOR (7 downto 0);
			  Shape : in STD_LOGIC_VECTOR (7 downto 0);
           TimeDiv : out  integer);
end component Clock_select;

begin


U1: ShiftReg PORT MAP(Clk => SCK, D => Mosi, Reset => Reset, Q => SPIdat_sig, SS_not => SS_not);
U2: Protokol PORT MAP(Clk => SCK, Reset => Reset, SPIdat => SPIdat_sig, Shape => Shape_sig, Ampl => Ampl_sig, Freq => Freq_sig, Paritet => Paritet);
U3: PWM PORT MAP(Clk => Freq_Clk, Reset => Reset, Shape => Shape_sig, Ampl => Ampl_sig, Freq => Freq_sig, SigEN => SigEN, PWMout => Output);
U4: DivClk PORT MAP(Reset => Reset, Clk => SCK, TimeP => TimePP, Clk1 => Freq_clk);
U5: Clock_select PORT MAP(Reset => Reset, Clk => SCK, Ampl => Ampl_sig, Freq => Freq_sig, Shape => Shape_sig, TimeDiv => TimePP);

end Behavioral;

