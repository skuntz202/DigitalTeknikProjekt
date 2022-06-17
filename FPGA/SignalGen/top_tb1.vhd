--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   09:29:43 06/17/2022
-- Design Name:   
-- Module Name:   C:/Users/tniel/OneDrive - Danmarks Tekniske Universitet/Dokumenter/GitHub/DigitalTeknikProjekt/FPGA/SignalGen/top_tb1.vhd
-- Project Name:  SignalGen
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: SigGenTop
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
 
    COMPONENT SigGenTop
    PORT(
         BTN3 : IN  std_logic;
         Clk : IN  std_logic;
         SCK : IN  std_logic;
         BTN0 : IN  std_logic;
         BTN1 : IN  std_logic;
         BTN2 : IN  std_logic;
         SS_not : IN  std_logic;
         Mosi : IN  std_logic;
         SW : IN  std_logic_vector(7 downto 0);
         An : OUT  std_logic_vector(3 downto 0);
         Cat : OUT  std_logic_vector(7 downto 0);
         Paritet : OUT  std_logic;
         LD : OUT  std_logic;
         PWMOut : INOUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal BTN3 : std_logic := '0';
   signal Clk : std_logic := '0';
   signal SCK : std_logic := '0';
   signal BTN0 : std_logic := '0';
   signal BTN1 : std_logic := '0';
   signal BTN2 : std_logic := '0';
   signal SS_not : std_logic := '0';
   signal Mosi : std_logic := '0';
   signal SW : std_logic_vector(7 downto 0) := (others => '0');

	--BiDirs
   signal PWMOut : std_logic;

 	--Outputs
   signal An : std_logic_vector(3 downto 0);
   signal Cat : std_logic_vector(7 downto 0);
   signal Paritet : std_logic;
   signal LD : std_logic;

   -- Clock period definitions
   constant Clk_period : time := 10 ps;
	constant SCK_period : time := 10 ps;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: SigGenTop PORT MAP (
          BTN3 => BTN3,
          Clk => Clk,
          SCK => SCK,
          BTN0 => BTN0,
          BTN1 => BTN1,
          BTN2 => BTN2,
          SS_not => SS_not,
          Mosi => Mosi,
          SW => SW,
          An => An,
          Cat => Cat,
          Paritet => Paritet,
          LD => LD,
          PWMOut => PWMOut
        );

   -- Clock process definitions
   Clk_process :process
   begin
		Clk <= '0';
		wait for Clk_period/2;
		Clk <= '1';
		wait for Clk_period/2;
   end process;
	
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
       wait for Clk_period*10;
		BTN3 <= '1';
		wait for CLK_period;
		BTN3 <= '0';
		wait for CLK_period*10;
		
		wait for Clk_period*10;
		SS_not <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		SS_not <= '1';
		
		-- Sender Data til Shape: Savtak sender X"02"
		wait for Clk_period*1;
		SS_not <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		SS_not <= '1';
		
		
		-- Sender CRC sender X"FC"
		wait for Clk_period*1;
		SS_not <= '0';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		SS_not <= '1';

		
		-- Sender ACK sender X"01"
		wait for Clk_period*1;
		SS_not <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		SS_not <= '1';
		
		
		-- Anden omgang
		
		--Addresse Ampl X"02"
		wait for Clk_period*1;
		SS_not <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		SS_not <= '1';
		
		--Data Ampl X"10"
		wait for Clk_period*1;
		SS_not <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		SS_not <= '1';

		
		--CRC Ampl X"00"
		wait for Clk_period*1;
		SS_not <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		SS_not <= '1';
		
		--ACK Ampl X"F0"
		wait for Clk_period*1;
		SS_not <= '0';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		SS_not <= '1';
		
		--Tredje omgang
		
		--Addr Freq X"03"
		wait for Clk_period*1;
		SS_not <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		SS_not <= '1';
		
		--Data Freq X"10"
		wait for Clk_period*1;
		SS_not <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		SS_not <= '1';
		
		--CRC Freq "EF"
		wait for Clk_period*1;
		SS_not <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		SS_not <= '1';
		
		--ACK Freq X"01"
		wait for Clk_period;
		SS_not <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '0';
		wait for Clk_period;
		MOSI <= '1';
		wait for Clk_period;
		SS_not <= '1';
		
		wait for Clk_period*10;

      wait;
   end process;

END;
