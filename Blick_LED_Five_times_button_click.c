/*************************************Blink LED 5 times after press button*******************************************/

#include<reg51.h>
#include<stdio.h>
#include"stdint.h"

sbit swt = P2^0;     // Switch connected to Port2^0 pin
sbit led = P0^0;     // LED connected to Port0^0 pin

void delay_ms(uint16_t );

void main()
{
    uint8_t Led_time = 5,i;
    P2 = 0xFF;    //Port2 assigned as Input
    P0 = 0x00;    //Port0 assigned as Output

    while(1)
    {
       if(swt == 0x00)
       {
         for(i=0;i<Led_time;i++)
         {
            led = 0x00;
            delay_ms(1000);
            led = 0x01;
            delay_ms(1000);
         }
       }
       else
       {
            led = 0x00;
       }
    }

}


void delay_ms(uint16_t num)
{
    uint16_t i,j;
    for (i=0;i<num;i++)
    {
        for(j=0;j<114;j++);
    }
}



