library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity PWM is
    Port ( Clk : in  STD_LOGIC;
           Reset : in  STD_LOGIC;
           Shape : in  STD_LOGIC_VECTOR (7 downto 0);
           Ampl : in  STD_LOGIC_VECTOR (7 downto 0);
           Freq : in  STD_LOGIC_VECTOR (7 downto 0);
           SigEN : in  STD_LOGIC;
           PWMout : out  STD_LOGIC);
end PWM;

architecture Behavioral of PWM is

--Interne signaler
Signal PWMCnt : STD_LOGIC_VECTOR(7 downto 0);
Signal Ampl_sig : STD_LOGIC_VECTOR(7 downto 0):=X"00";
Signal up : STD_LOGIC:='1';

begin

--PWMCount får PWMCnt til at tælle på til 255 og derefter gå til 0
PWMCount: process(Reset,Clk)
begin
	if reset = '1' then
		PWMCnt <= X"00";
	elsif Clk'event and Clk = '1' and sigEN = '1' then
		PWMCnt <= PWMCnt + 1;
	end if;
end process;

signal_gen: process (PWMcnt)
begin

	if Shape = X"01" then -- Sinus
		PWMout <= '1';
	
	elsif Shape = X"02" then -- Trekant
		--Hvis Ampl_sig er større eller lig PWMCnt er PWMout = 1, ellers 0
		if Ampl_sig >= PWMCnt then
			PWMOut <= '1';
		else 
			PWMOut <= '0';
		end if;
		--Hvis PWMCnt er nået til 255 stiger Ampl_sig med 1, og generer altså en trekant
		if PWMCnt = X"FF" then
			if up = '1' then
				Ampl_sig <= Ampl_sig + 1;
				if Ampl_sig = Ampl then
					up <= '0';
				end if;
		--Når Ampl_sig har nået Ampl, altså max begynder den at tælle nedad
			elsif up = '0' then
				Ampl_sig <= Ampl_sig - 1;
				if Ampl_sig = X"00" then -- Og når den når nul tæller den op.
					up <= '1';
				end if;
			end if;
		end if;
		

	elsif Shape = X"03" then -- Firkant
		if Ampl >= PWMCnt then
			PWMout <= '1';
		else 
			PWMout <= '0';
		end if;
	end if;
end process;



end Behavioral;

