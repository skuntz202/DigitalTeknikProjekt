--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:12:50 06/16/2022
-- Design Name:   
-- Module Name:   C:/Users/tniel/OneDrive/Dokumenter/GitHub/DigitalTeknikProjekt/FPGA/Three_week_course_F22/top_tb3.vhd
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
 
ENTITY top_tb3 IS
END top_tb3;
 
ARCHITECTURE behavior OF top_tb3 IS 
 
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
   constant MClk_period : time := 10 ns;
 
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
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for MClk_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
