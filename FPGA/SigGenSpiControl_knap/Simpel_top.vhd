library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;

entity SigGenSpiControl is
    Port ( MClk : in STD_LOGIC;
			  Reset : in STD_LOGIC;
			  BTN0 : in STD_LOGIC;
			  BTN1 : in STD_LOGIC;
			  BTN2 : in STD_LOGIC;
			  BTN3 : in STD_LOGIC;
			  SW : in STD_LOGIC_VECTOR(7 downto 0);
			  output : out STD_LOGIC;
			  An : out STD_LOGIC_VECTOR ( 3 downto 0);
			  Cat : out STD_LOGIC_VECTOR ( 7 downto 0);
			  LD : out STD_LOGIC;
			  Paritet : out STD_LOGIC);
end SigGenSpiControl;

architecture Behavioral of SigGenSpiControl is
--Interne signaler som forbinder forskellige moduler
Signal SPIdat_sig : STD_LOGIC_VECTOR(7 downto 0);
Signal Shape_sig : STD_LOGIC_VECTOR(7 downto 0);
Signal Ampl_sig : STD_LOGIC_VECTOR(7 downto 0);
Signal Freq_sig : STD_LOGIC_VECTOR(7 downto 0);
Signal Freq_Clk : STD_LOGIC;
Signal TimePP : Integer;
Signal Sig_SigEN : STD_LOGIC;
Signal Disp : STD_LOGIC_VECTOR(19 downto 0);
Signal BTN1d, BTN2d : STD_LOGIC;
Signal DispClk : STD_LOGIC;


--Skiftregister for at modtage sekventiel data, og konvertere det til Paralel data
--Aka at få 8 forskellige bits, og lave dem til en liste på 8 bits
Component putin is
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
end component;

--Data behandling som generer det ønskede signal type med korrekt, amplitude, frekvens og form
Component PWM is
    Port ( Clk : in  STD_LOGIC;
           Reset : in  STD_LOGIC;
           Shape : in  STD_LOGIC_VECTOR (7 downto 0);
           Ampl : in  STD_LOGIC_VECTOR (7 downto 0);
           Freq : in  STD_LOGIC_VECTOR (7 downto 0);
           SigEN : in  STD_LOGIC;
           PWMout : out  STD_LOGIC);
end component PWM;

--Modul til at gøre klokken langsommere end de 50MHz som er boardets default clock
component DivClk is
    port ( 
       Reset: in STD_LOGIC;     -- Global Reset (BTN1)
       Clk: in STD_LOGIC;     -- Master Clock (50 MHz)
       TimeP: in integer;     -- Time periode of the divided clock 
       Clk1: out STD_LOGIC);   -- Divided clock1 
	end component DivClk;

--Her vælger vi clocken afhængigt af hvilket signal vi får, frekvensen og i tilfælde også amplituden
--Dette sendes så til DivClk modulet hvor klokken justeres.
component Clock_select is
    Port (
			  Freq : in  STD_LOGIC_VECTOR (7 downto 0);
			  Clk : in STD_LOGIC;
			  Reset : in STD_LOGIC;
			  SigEN : in STD_LOGIC;
           Ampl : in  STD_LOGIC_VECTOR (7 downto 0);
			  Shape : in STD_LOGIC_VECTOR (7 downto 0);
           TimeDiv : out  integer); -- Værdi som ligges i TimeP
end component Clock_select;

-- Debounce er givet og soerger for at knappen ikke "bouncer" og giver flere flanker.
component Debounce is
	port (
		Reset : in  STD_LOGIC;
      Clk : in  STD_LOGIC;
      BTN : in  STD_LOGIC;
      BTNd : out  STD_LOGIC);
end component Debounce;

component SevenSeg5 is
	port ( 
	Reset, Clk : in STD_LOGIC;
	Data : in STD_LOGIC_VECTOR(19 downto 0);
	An : out STD_LOGIC_VECTOR ( 3 downto 0);
	Cat : out STD_LOGIC_VECTOR( 7 downto 0));
end component SevenSeg5;

begin

U1: Putin port map(Reset => BTN3, Clk => Mclk, BTN0 => BTN0, BTN1 => BTN1d, BTN2 => BTN2d, SW => SW, Disp => Disp, Shape => Shape_sig, Ampl => Ampl_sig, Freq => Freq_sig, SigEN=> Sig_SigEN);
U2: PWM PORT MAP(Clk => Freq_Clk, Reset => Reset, Shape => Shape_sig, Ampl => Ampl_sig, Freq => Freq_sig, SigEN => Sig_SigEN, PWMout => Output);
U3: DivClk PORT MAP(Reset => Reset, Clk => MClk, TimeP => TimePP, Clk1 => Freq_clk);
U4: Clock_select PORT MAP(Reset => Reset, Clk => MClk, Ampl => Ampl_sig, Freq => Freq_sig, Shape => Shape_sig, TimeDiv => TimePP, SigEN => Sig_sigEN);
U5: Debounce PORT MAP(Reset => BTN3, Clk => MClk, BTN => BTN2, BTNd => BTN2d);
U6: Debounce PORT MAP(Reset => BTN3, Clk => MClk, BTN => BTN1, BTNd => BTN1d);
U7: SevenSeg5 port map(Reset => BTN3, Clk => DispClk, Data => Disp, An => An, Cat => Cat); 
U8: DivClk PORT MAP(Reset => Reset, Clk => MClk, TimeP => 50e3, Clk1 => DispClk);
end Behavioral;

