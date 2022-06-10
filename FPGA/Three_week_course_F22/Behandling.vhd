library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Behandling is
    Port ( Clk : in  STD_LOGIC;
           Reset : in  STD_LOGIC;
           Shape : in  STD_LOGIC_VECTOR (7 downto 0);
           Ampl : in  STD_LOGIC_VECTOR (7 downto 0);
           Freq : in  STD_LOGIC_VECTOR (7 downto 0);
           CRC : in  STD_LOGIC_VECTOR (7 downto 0);
           Ack : in  STD_LOGIC_VECTOR (7 downto 0);
           SigOut : out  STD_LOGIC_VECTOR(7 downto 0));
end Behandling;

architecture Behavioral of Behandling is

begin

	Res := "00000000";
	Dend:= "00000000" & In1;
	Dsor := In2 & "00000000";    
	Index := 0;
	 ResLsb := '0';
	 
	 while Index < 9 loop      
		  if Dend >= Dsor then
				ResLsb := '1';
				Dend := Dend - Dsor;
		  else
				ResLsb := '0';
		  end if;
		  Res := Res(6 downto 0) & ResLsb;
		  Dsor := '0' & Dsor(15 downto 1);
		  Index := Index + 1;
	 end loop;
	 CalcVal_2_hold <= "00000000" & Res;
	 CalcVal_2 <= "00000000" & Res;


end Behavioral;

