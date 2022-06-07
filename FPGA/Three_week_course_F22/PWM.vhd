library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity PWM is
    Port ( Clk : in  STD_LOGIC;
			  TreClk : in STD_LOGIC;
           Reset : in  STD_LOGIC;
           Shape : in  STD_LOGIC_VECTOR (7 downto 0);
           Ampl : in  STD_LOGIC_VECTOR (7 downto 0);
           Freq : in  STD_LOGIC_VECTOR (7 downto 0);
           SigEN : in  STD_LOGIC;
           PWMout : out  STD_LOGIC);
end PWM;

architecture Behavioral of PWM is

Signal PWMCnt : STD_LOGIC_VECTOR(7 downto 0);
Signal Ampl_sig : STD_LOGIC_VECTOR(7 downto 0):=X"00";
Signal up : STD_LOGIC:='0';

begin
signal_gen: process (clk, reset, sigEN, PWMcnt)
begin

	if reset = '1' then
		PWMout <= '0';
		
	elsif Clk'event and CLK = '1' and SigEN = '1' then
		if Shape = X"01" then -- Firkant
			if Ampl >= PWMCnt then
				PWMout <= '1';
			else 
				PWMout <= '0';
			end if;
			
		elsif Shape = X"02" then -- Trekant
			if Ampl_sig >= PWMCnt then
				PWMOut <= '1';
			else 
				PWMOut <= '0';
			end if;
			
			if PWMCnt = X"FF" then
				if up = '1' then
					Ampl_sig <= Ampl_sig + 1;
					if Ampl_sig = Ampl then
						up <= '0';
					end if;
				elsif up = '0' then
					Ampl_sig <= Ampl_sig - 1;
					if Ampl_sig = X"00" then
						up <= '1';
					end if;
				end if;
			end if;
			
		elsif Shape = X"03" then -- Sinus
			PWMout <= '1';
			
		else
			PWMout <= '0';
		end if;
	end if;
	
end process;

PWMCount: process(Reset,Clk)
begin
	if reset = '1' then
		PWMCnt <= X"00";
	elsif Clk'event and Clk = '1' then
		PWMCnt <= PWMCnt + 1;
	end if;
end process;

end Behavioral;

