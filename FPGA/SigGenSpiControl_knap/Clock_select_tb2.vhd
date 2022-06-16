--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   00:17:14 06/16/2022
-- Design Name:   
-- Module Name:   C:/Users/tniel/OneDrive - Danmarks Tekniske Universitet/Dokumenter/GitHub/DigitalTeknikProjekt/FPGA/SigGenSpiControl_knap/Clock_select_tb2.vhd
-- Project Name:  SigGenSpiControl_knap
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Clock_select
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
 
ENTITY Clock_select_tb2 IS
END Clock_select_tb2;
 
ARCHITECTURE behavior OF Clock_select_tb2 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Clock_select
    PORT(
         Freq : IN  std_logic_vector(7 downto 0);
         Clk : IN  std_logic;
         Reset : IN  std_logic;
         sigEN : IN  std_logic;
         Ampl : IN  std_logic_vector(7 downto 0);
         Shape : IN  std_logic_vector(7 downto 0);
         TimeDiv : OUT  integer);
    END COMPONENT;
    

   --Inputs
   signal Freq : std_logic_vector(7 downto 0) := (others => '0');
   signal Clk : std_logic := '0';
   signal Reset : std_logic := '0';
   signal sigEN : std_logic := '0';
   signal Ampl : std_logic_vector(7 downto 0) := (others => '0');
   signal Shape : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
   signal TimeDiv : Integer;

   -- Clock period definitions
   constant Clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Clock_select PORT MAP (
          Freq => Freq,
          Clk => Clk,
          Reset => Reset,
          sigEN => sigEN,
          Ampl => Ampl,
          Shape => Shape,
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
      Reset <= '1';
		Wait for Clk_period;
		Reset <= '0';
		Wait for CLK_period;
		Shape <= X"02";
		Ampl <= X"0F";
		Freq <= X"0F";
		wait for CLK_period*2;
		SigEN <= '1';
		wait for CLK_period*10;
		SigEN <= '0';
		

      wait;
   end process;

END;
