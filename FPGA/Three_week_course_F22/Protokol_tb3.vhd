--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   12:04:37 06/07/2022
-- Design Name:   
-- Module Name:   C:/Users/tniel/OneDrive/Dokumenter/GitHub/DigitalTeknikProjekt/FPGA/Three_week_course_F22/Protokol_tb3.vhd
-- Project Name:  Three_week_course_F22
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Protokol
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
 
ENTITY Protokol_tb3 IS
END Protokol_tb3;
 
ARCHITECTURE behavior OF Protokol_tb3 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Protokol
    PORT(
         Clk : IN  std_logic;
         Reset : IN  std_logic;
         SPIdat : IN  std_logic_vector(7 downto 0);
         Shape : OUT  std_logic_vector(7 downto 0);
         Ampl : OUT  std_logic_vector(7 downto 0);
         Freq : OUT  std_logic_vector(7 downto 0);
         CRC_out : OUT  std_logic_vector(7 downto 0);
         ACK_out : OUT  std_logic_vector(7 downto 0);
         Paritet : OUT  std_logic
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
   signal CRC_out : std_logic_vector(7 downto 0);
   signal ACK_out : std_logic_vector(7 downto 0);
   signal Paritet : std_logic;

   -- Clock period definitions
   constant Clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Protokol PORT MAP (
          Clk => Clk,
          Reset => Reset,
          SPIdat => SPIdat,
          Shape => Shape,
          Ampl => Ampl,
          Freq => Freq,
          CRC_out => CRC_out,
          ACK_out => ACK_out,
          Paritet => Paritet
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
		SPIdat <= X"FF";
		wait for Clk_period*5;
		SPidat <= X"2F";
		wait for Clk_period*5;
		SPIdat <= X"10";
		wait for Clk_period*5;
		SPIdat <= X"02";
		wait for Clk_period*5;
		SPIdat <= X"0F";
		wait for Clk_period*5;
		SPIdat <= X"F0";
		wait for Clk_period*5;
		SPIdat <= X"04";
		wait for Clk_period*5;
		SPIdat <= X"05";
		wait for Clk_period*5;
		SPIdat <= X"03";
		wait for Clk_period*5;
		SPIdat <= X"02";
		wait for Clk_period*5;
		SPIdat <= X"04";
		wait for Clk_period*5;
		SPIdat <= X"00";
		wait for Clk_period*5;

      wait;
   end process;

END;
