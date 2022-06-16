--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   23:27:59 06/15/2022
-- Design Name:   
-- Module Name:   C:/Users/tniel/OneDrive - Danmarks Tekniske Universitet/Dokumenter/GitHub/DigitalTeknikProjekt/FPGA/SigGenSpiControl_knap/top_tb1.vhd
-- Project Name:  SigGenSpiControl_knap
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
 
ENTITY top_tb1 IS
END top_tb1;
 
ARCHITECTURE behavior OF top_tb1 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT SigGenSpiControl
    PORT(
         MClk : IN  std_logic;
         Reset : IN  std_logic;
         BTN0 : IN  std_logic;
         BTN1 : IN  std_logic;
         BTN2 : IN  std_logic;
         BTN3 : IN  std_logic;
         SW : IN  std_logic_vector(7 downto 0);
         output : OUT  std_logic;
         An : OUT  std_logic_vector(3 downto 0);
         Cat : OUT  std_logic_vector(7 downto 0);
         LD : OUT  std_logic;
         Paritet : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal MClk : std_logic := '0';
   signal Reset : std_logic := '0';
   signal BTN0 : std_logic := '0';
   signal BTN1 : std_logic := '0';
   signal BTN2 : std_logic := '0';
   signal BTN3 : std_logic := '0';
   signal SW : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
   signal output : std_logic;
   signal An : std_logic_vector(3 downto 0);
   signal Cat : std_logic_vector(7 downto 0);
   signal LD : std_logic;
   signal Paritet : std_logic;

   -- Clock period definitions
   constant Mclk_period : time := 10 ps;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: SigGenSpiControl PORT MAP (
          MClk => MClk,
          Reset => Reset,
          BTN0 => BTN0,
          BTN1 => BTN1,
          BTN2 => BTN2,
          BTN3 => BTN3,
          SW => SW,
          output => output,
          An => An,
          Cat => Cat,
          LD => LD,
          Paritet => Paritet
        );

   -- Clock process definitions
   MClk_process :process
   begin
		MClk <= '0';
		wait for Mclk_period/2;
		MClk <= '1';
		wait for Mclk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      reset <= '1';
		wait for Mclk_period;
		reset <= '0';
		wait for Mclk_period;
		
		--Shape
		SW <= X"02";
		wait for Mclk_period;
		BTN0 <= '1';
		wait for Mclk_period;
		BTN0 <= '0';
		wait for Mclk_period;
		
		--Ampl
		SW <= X"F0";
		BTN1 <= '1';
		wait for Mclk_period;
		BTN1 <= '0';
		wait for Mclk_period;
		BTN0 <= '1';
		wait for Mclk_period;
		BTN0 <= '0';
		wait for Mclk_period;
		
		--Freq
		SW <= X"40";
		BTN1 <= '1';
		wait for Mclk_period;
		BTN1 <= '0';
		wait for Mclk_period;
		BTN0 <= '1';
		wait for Mclk_period;
		BTN0 <= '0';
		wait for Mclk_period;
		
		--Wait og SigEN.
		SW <= X"00";
		BTN1 <= '1';
		wait for Mclk_period;
		BTN1 <= '0';
		wait for Mclk_period;
		BTN2 <= '1';
		wait for Mclk_period;
		BTN2 <= '0';
		wait for Mclk_period;
		

      wait;
   end process;

END;
