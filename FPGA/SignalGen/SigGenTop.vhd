library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity SigGenTop is
  Port ( BTN3   : in std_logic;	
         Clk    : in std_logic;
			SCK 	 : in STD_LOGIC;
         BTN0   : in std_logic;
         BTN1   : in std_logic;
         BTN2   : in std_logic;
			SS_not : in std_logic;
			Mosi	 : in STD_LOGIC;
         SW     : in std_logic_vector(7 downto 0);
			An     : out std_logic_vector(3 downto 0);
			Cat    : out std_logic_vector(7 downto 0);
			Paritet: out STD_LOGIC;
			LD		 : out std_logic;
         PWMOut : inout std_logic);
end SigGenTop;

architecture Behavioral of SigGenTop is

signal Mclk, DispClk, SigEn: std_logic;
signal Disp: std_logic_vector(19 downto 0); 
signal Ampl, Freq, Shape, SPIdat_sig: std_logic_vector(7 downto 0);


begin

U0: entity WORK.DivClk 
    port map(Reset => BTN3, Clk => Clk, TimeP => 4, Clk1 => Mclk);

U4: entity WORK.DivClk 
    port map(Reset => BTN3, Clk => Clk, TimeP => 50e3, Clk1 => DispClk);

--U1: entity WORK.SigGenControl 
--    port map(Reset => BTN3, Clk => Mclk, BTN0 => BTN0, BTN1 => BTN1, BTN2 => BTN2, SW => SW, 
--	 Disp => Disp, Shape => Shape, Ampl => Ampl, Freq => Freq, SigEN=> SigEN);


U2: entity WORK.SigGenDataPath generic map (PWMinc => "0000001") 
    port map(Reset => BTN3, Clk => Mclk, Shape => Shape, Ampl => Ampl, Freq => Freq, SigEN=> SigEN, PWMOut => PWMOut);

U3: entity WORK.SevenSeg5 
    port map(Reset => BTN3, Clk => DispClk, Data => Disp, An => An, Cat => Cat);  

U5: LD <= PWMOut;

U6: entity WORK.ShiftReg
	port map(Clk => SCK, D => Mosi, Reset => BTN3, Q => SPIdat_sig, SS_not => SS_not);

U7: entity WORK.Protokol
	port map(Clk => Clk, Reset => BTN3, SPIdat => SpiDat_sig, Shape => Shape, Ampl => Ampl, Freq => Freq,
	SigEN => SigEN, Disp => Disp, SS_not => SS_not, Paritet => Paritet);


end Behavioral;
