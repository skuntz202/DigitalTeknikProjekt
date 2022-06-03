--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:24:23 06/03/2022
-- Design Name:   
-- Module Name:   C:/Users/tniel/Desktop/Skole arbejde/DTU/Digital techniques/Three_week_course_F22/test_protokol_tb1.vhd
-- Project Name:  Three_week_course_F22
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: test_Protokol
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
 
ENTITY test_protokol_tb1 IS
END test_protokol_tb1;
 
ARCHITECTURE behavior OF test_protokol_tb1 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT test_Protokol
    PORT(
         Clk : IN  std_logic;
         Reset : IN  std_logic;
         SPIdat : IN  std_logic_vector(7 downto 0);
         Shape : OUT  std_logic_vector(7 downto 0);
         Ampl : OUT  std_logic_vector(7 downto 0);
         Freq : OUT  std_logic_vector(7 downto 0);
         SigEN : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal Clk : std_logic := '0';
   signal Reset : std_logic := '0';
   signal SPIdat : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
   signal Shape : std_logic_vector(7 downto 0);
   signal Ampl : std_logic_vector(7 downto 0);
   signal Freq : std_logic_vector(7 downto 0);
   signal SigEN : std_logic;

   -- Clock period definitions
   constant Clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: test_Protokol PORT MAP (
          Clk => Clk,
          Reset => Reset,
          SPIdat => SPIdat,
          Shape => Shape,
          Ampl => Ampl,
          Freq => Freq,
          SigEN => SigEN
        );

   -- Clock process definitions
   Clk_process :process
   begin
		Clk <= '0';
		wait for Clk_period/2;
		Clk <= '1';
		wait for Clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      Reset <= '1';
      wait for Clk_period*2;	
		Reset <= '0';
      wait for Clk_period*5;
		SPIdat <= X"01";
		wait for Clk_period*5;
		SPIdat <= X"F2";
		wait for Clk_period*5;
		SPidat <= X"AB";
		wait for Clk_period*5;
		SPIdat <= X"00";

      wait;
   end process;

END;
