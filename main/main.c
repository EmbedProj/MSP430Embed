#include <msp430.h>
#include <inc/blinkdriver.h>


/**
 * main.c
 */

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;         // stop watchdog timer
	
	SetDirLED(65, 42);                // it set direction of Port1 and Port2

	while(1)
	{
	    ToogleTwoLED();               //LED Pattern
//	    PlayWithRGBLED();             //LED Pattern
//	    ToogleTwoLEDUsingSwitch();    //LED Pattern
//	    LEDBehaviourUsingSwitch();    //LED Pattern
	}
	return 0;
}
