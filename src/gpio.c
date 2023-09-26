/*
 * gpio.c
 *
 *  Created on: 07-Sep-2023
 *      Author: RajSid
 */

#include <msp430.h>


int i = 0;
int counter =0;

void SetDirLED(int p1bit, int p2bit)
{
    P1DIR |=p1bit;  //it take int as a hex,Ex- 65=0x41(01000001)//set direction the Pin1.0->LED1 & Pin1.6 ->LED2
    P2DIR |=p2bit;  //42=0x2A (00101010) set direction the RGB light at Port2.1,Port2.3,Port2.5
    P1OUT = 0X00;   // bydafault it is low
    P2OUT = 0X00;   // bydafault it is low

}

void ToogleTwoLED()
{
    P1OUT = BIT0;              //Set high at port1.0 so,LED1 can glow
    for(i=0; i<30000; i++);    //Delay
    P1OUT = 0x40;              //Set high at port1.6 so,LED2 can glow
    for(i=0; i<30000; i++);    //Delay
}

void PlayWithRGBLED()
{
    P2OUT = 0x02;              //Set high at port2.1 so,LED3(red) can glow
    for(i=0; i<30000; i++);    //Delay
    P2OUT = 0x08;              //Set high at port2.3 so,LED3(green) can glow
    for(i=0; i<30000; i++);    //Delay
    P2OUT = 0x20;              //Set high at port2.5 so,LED3(blue) can glow
    for(i=0; i<30000; i++);    //Delay
}

void ToogleTwoLEDUsingSwitch()
{
    volatile int Switch = P1IN & BIT3; // already pullup resistor have joined to this push button->see schemtic

    if(Switch)
    {
        P1OUT = BIT0;
        for(i=0; i<30000; i++);    //Delay
    }
    else{
        P1OUT = BIT6;
        for(i=0; i<30000; i++);    //Delay
    }
   // P1IN = BIT3;
}

void LEDBehaviourUsingSwitch()
{
   switch(counter){
         case 1:
             P2OUT = 0x00;              //Off the RGB LED3
             ToogleTwoLED();
             for(i=0; i<30000; i++);    //Delay
             break;
         case 2:
             P1OUT = 0x00;
             PlayWithRGBLED();
             for(i=0; i<30000; i++);    //Delay
             break;
         case 3:
             P2OUT = 0X00;              //Off the RGB LED3
             P1OUT = BIT0;              //Set high at port1.0 so,only LED1 can glow
             for(i=0; i<30000; i++);    //Delay
             break;
         case 4:
             P2OUT = 0X00;              //Off the RGB LED3
             P1OUT = BIT6;              //Set high at port1.6 so,LED2 can glow
             for(i=0; i<30000; i++);    //Delay
             break;
         default:
             P2OUT = 0X00;              //Off the RGB LED3
             P1OUT = BIT0 | BIT6;
             for(i=0; i<30000; i++);    //Delay
             break;
   }
   volatile int Switch = P1IN & BIT3;
   if(Switch)
       counter= counter;
   else{
       counter+= 1;
       P1IN = BIT3;
   }
   if(counter>4)
       counter = 0;
}





