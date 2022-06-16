LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY Top_tb1 IS
END Top_tb1;
 
ARCHITECTURE behavior OF Top_tb1 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT SigGenSpiControl
    PORT(
         SCK : IN  std_logic;
         MClk : IN  std_logic;
         MOSI : IN  std_logic;
         SS_not : IN  std_logic;
         Reset : IN  std_logic;
         output : OUT  std_logic;
         An : OUT  std_logic_vector(3 downto 0);
         Cat : OUT  std_logic_vector(7 downto 0);
         Paritet : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal SCK : std_logic := '0';
   signal MClk : std_logic := '0';
   signal MOSI : std_logic := '0';
   signal SS_not : std_logic := '0';
   signal Reset : std_logic := '0';

 	--Outputs
   signal output : std_logic;
   signal An : std_logic_vector(3 downto 0);
   signal Cat : std_logic_vector(7 downto 0);
   signal Paritet : std_logic;

   -- Clock period definitions
   constant SCK_period : time := 100 ps;
	constant MCLK_period : time := 10 ps;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: SigGenSpiControl PORT MAP (
          SCK => SCK,
          MClk => MClk,
          MOSI => MOSI,
          SS_not => SS_not,
          Reset => Reset,
          output => output,
          An => An,
          Cat => Cat,
          Paritet => Paritet
        );

   -- Clock process definitions
   SCK_process :process
   begin
		SCK <= '0';
		wait for SCK_period/2;
		SCK <= '1';
		wait for SCK_period/2;
   end process;
	
	MClk_process :process
   begin
		MClk <= '0';
		wait for MClk_period/2;
		MClk <= '1';
		wait for MClk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      reset <= '1';
		wait for SCK_period;
		reset <= '0';
		
		-- Første
		
		-- Sender til Addrese: Shape sender X"01"
		wait for SCK_period*10;
		SS_not <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		SS_not <= '1';
		
		-- Sender Data til Shape: Firkant sender X"03"
		wait for SCK_period*1;
		SS_not <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		SS_not <= '1';
		
		
		-- Sender CRC sender X"FC"
		wait for SCK_period*1;
		SS_not <= '0';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		SS_not <= '1';

		
		-- Sender ACK sender X"01"
		wait for SCK_period*1;
		SS_not <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		SS_not <= '1';
		
		
		-- Anden omgang
		
		--Addresse Ampl X"02"
		wait for SCK_period*1;
		SS_not <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		SS_not <= '1';
		
		--Data Ampl X"10"
		wait for SCK_period*1;
		SS_not <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		SS_not <= '1';

		
		--CRC Ampl X"00"
		wait for SCK_period*1;
		SS_not <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		SS_not <= '1';
		
		--ACK Ampl X"F0"
		wait for SCK_period*1;
		SS_not <= '0';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		SS_not <= '1';
		
		--Tredje omgang
		
		--Addr Freq X"03"
		wait for SCK_period*1;
		SS_not <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		SS_not <= '1';
		
		--Data Freq X"10"
		wait for SCK_period*1;
		SS_not <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		SS_not <= '1';
		
		--CRC Freq "EF"
		wait for SCK_period*1;
		SS_not <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		SS_not <= '1';
		
		--ACK Freq X"01"
		wait for SCK_period;
		SS_not <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '0';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		SS_not <= '1';
		
		wait for SCK_period*10;
		
      wait;
   end process;

END;
