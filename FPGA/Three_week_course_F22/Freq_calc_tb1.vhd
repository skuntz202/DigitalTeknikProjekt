--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   16:00:02 06/07/2022
-- Design Name:   
-- Module Name:   C:/Users/tniel/OneDrive/Dokumenter/GitHub/DigitalTeknikProjekt/FPGA/Three_week_course_F22/Freq_calc_tb1.vhd
-- Project Name:  Three_week_course_F22
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Freq_calc
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
 
ENTITY Freq_calc_tb1 IS
END Freq_calc_tb1;
 
ARCHITECTURE behavior OF Freq_calc_tb1 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Freq_calc
    PORT(
         Freq : IN  std_logic_vector(7 downto 0);
         Clk : IN  std_logic;
         Reset : IN  std_logic;
         Ampl : IN  std_logic_vector(7 downto 0);
         TimeDiv : OUT  integer
        );
    END COMPONENT;
    

   --Inputs
   signal Freq : std_logic_vector(7 downto 0) := (others => '0');
   signal Clk : std_logic := '0';
   signal Reset : std_logic := '0';
   signal Ampl : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
   signal TimeDiv : integer;

   -- Clock period definitions
   constant Clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Freq_calc PORT MAP (
          Freq => Freq,
          Clk => Clk,
          Reset => Reset,
          Ampl => Ampl,
          TimeDiv => TimeDiv
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
		Freq <= X"FF";
		Ampl <= X"01";
      Reset <= '1';
		wait for Clk_period*2;
		Reset <= '0';
		wait for Clk_period;
		
		wait for Clk_period*10;

      

      wait;
   end process;

END;
