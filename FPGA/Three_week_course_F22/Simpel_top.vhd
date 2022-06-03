library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity SigGenSpiControl is
    Port ( SCK : in  STD_LOGIC;
           MOSI : in  STD_LOGIC;
			  SS_not : in STD_LOGIC;
			  Reset : in STD_LOGIC;
			  Shape : out STD_LOGIC_VECTOR(7 downto 0);
			  Ampl : out STD_LOGIC_VECTOR(7 downto 0);
			  Freq : out STD_LOGIC_VECTOR(7 downto 0);
			  SigEN : out STD_LOGIC);
end SigGenSpiControl;

architecture Behavioral of SigGenSpiControl is

Signal SPIdat_sig : STD_LOGIC_VECTOR(7 downto 0);

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
           SigEN : out  STD_LOGIC);
end component Protokol;

begin
U1: ShiftReg PORT MAP(Clk => SCK, D => Mosi, Reset => Reset, Q => SPIdat_sig, SS_not => SS_not);
U2: Protokol PORT MAP(Clk => SCK, Reset => Reset, SPIdat => SPIdat_sig, Shape => Shape, Ampl => Ampl, Freq => Freq, SigEN => SigEN);

end Behavioral;

