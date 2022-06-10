--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   10:22:11 06/09/2022
-- Design Name:   
-- Module Name:   C:/Users/tniel/OneDrive - Danmarks Tekniske Universitet/Dokumenter/GitHub/DigitalTeknikProjekt/FPGA/Three_week_course_F22/Top_tb1.vhd
-- Project Name:  Three_week_course_F22
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: SigGenSpiControl
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
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
         MOSI : IN  std_logic;
         SS_not : IN  std_logic;
         Reset : IN  std_logic;
         SigEN : IN  std_logic;
         output : OUT  std_logic;
         Paritet : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal SCK : std_logic := '0';
   signal MOSI : std_logic := '0';
   signal SS_not : std_logic := '0';
   signal Reset : std_logic := '0';
   signal SigEN : std_logic := '0';

 	--Outputs
   signal output : std_logic;
   signal Paritet : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant SCK_period : time := 10 ps;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: SigGenSpiControl PORT MAP (
          SCK => SCK,
          MOSI => MOSI,
          SS_not => SS_not,
          Reset => Reset,
          SigEN => SigEN,
          output => output,
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
		
		--Data Freq X"FF"
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
		MOSI <= '1';
		wait for SCK_period;
		MOSI <= '1';
		wait for SCK_period;
		SS_not <= '1';
		
		--CRC Freq "F0"
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
		SigEN <= '1';
		
      wait;
   end process;

END;
