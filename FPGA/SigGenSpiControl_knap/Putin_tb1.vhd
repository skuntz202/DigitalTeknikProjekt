--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   22:35:02 06/15/2022
-- Design Name:   
-- Module Name:   C:/Users/tniel/OneDrive - Danmarks Tekniske Universitet/Dokumenter/GitHub/DigitalTeknikProjekt/FPGA/SigGenSpiControl_knap/Putin_tb1.vhd
-- Project Name:  SigGenSpiControl_knap
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: putin
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
 
ENTITY Putin_tb1 IS
END Putin_tb1;
 
ARCHITECTURE behavior OF Putin_tb1 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT putin
    PORT(
         Clk : IN  std_logic;
         Reset : IN  std_logic;
         BTN0 : IN  std_logic;
         BTN1 : IN  std_logic;
         BTN2 : IN  std_logic;
         SW : IN  std_logic_vector(7 downto 0);
         Shape : OUT  std_logic_vector(7 downto 0);
         Ampl : OUT  std_logic_vector(7 downto 0);
         Freq : OUT  std_logic_vector(7 downto 0);
         Disp : OUT  std_logic_vector(19 downto 0);
         SigEN : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal Clk : std_logic := '0';
   signal Reset : std_logic := '0';
   signal BTN0 : std_logic := '0';
   signal BTN1 : std_logic := '0';
   signal BTN2 : std_logic := '0';
   signal SW : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
   signal Shape : std_logic_vector(7 downto 0);
   signal Ampl : std_logic_vector(7 downto 0);
   signal Freq : std_logic_vector(7 downto 0);
   signal Disp : std_logic_vector(19 downto 0);
   signal SigEN : std_logic;

   -- Clock period definitions
   constant Clk_period : time := 1 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: putin PORT MAP (
          Clk => Clk,
          Reset => Reset,
          BTN0 => BTN0,
          BTN1 => BTN1,
          BTN2 => BTN2,
          SW => SW,
          Shape => Shape,
          Ampl => Ampl,
          Freq => Freq,
          Disp => Disp,
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
      reset <= '1';
		wait for Clk_period;
		reset <= '0';
		wait for Clk_period;
		
		--Shape
		SW <= X"03";
		wait for Clk_period;
		BTN0 <= '1';
		wait for Clk_period;
		BTN0 <= '0';
		wait for Clk_period;
		
		--Ampl
		SW <= X"10";
		BTN1 <= '1';
		wait for Clk_period;
		BTN1 <= '0';
		wait for Clk_period;
		BTN0 <= '1';
		wait for Clk_period;
		BTN0 <= '0';
		wait for Clk_period;
		
		--Freq
		SW <= X"0F";
		BTN1 <= '1';
		wait for Clk_period;
		BTN1 <= '0';
		wait for Clk_period;
		BTN0 <= '1';
		wait for Clk_period;
		BTN0 <= '0';
		wait for Clk_period;
		
		--Wait og SigEN.
		SW <= X"00";
		BTN1 <= '1';
		wait for Clk_period;
		BTN1 <= '0';
		wait for Clk_period;
		BTN2 <= '1';
		wait for Clk_period;
		BTN2 <= '0';
		wait for Clk_period;
		
		
      wait;
   end process;

END;
