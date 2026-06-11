/****************Control the LED by clicking the switch, and display the switch status on the serial port.****************************/ 

#include <reg51.h>
#include <stdio.h>
#include "stdint.h"          //standard intger file

sbit SWT = P2^0;    //switch as input 
sbit LED = P0^0;   //Led as output

void Delay(uint8_t );
void UART_Init();
void UART_Tx(unsigned char);
void UART_Txstr(uint8_t *);

void main()
{
    //uint8_t str[5],num=10,str1[10];
    P2 = 0xFF;     // set PORT2 as Input 
    P0 = 0x00;     // set PORT0 as Output
    UART_Init();   //Initthe uart
    while(1)
    {
        if(SWT == 0)
        {
            UART_Txstr("Switch status = Switch pressed LED ON\n");// send switch status to serial console
            LED = 0x01;
            Delay(1000000);
            
        }
        else
        {
            UART_Txstr("Switch status = Switch not pressed LED OFF\n");// send switch status to serial console
            LED = 0x00;
            Delay(1000000);
            
        }
    }
}

void UART_Init()
{
    TMOD = 0x20;   //Autoreload Barud rate
    SCON = 0x40;   //Timer 1 and recever bit enable
    TH1  = 0xFD;   //counting machine cycles for 9600 buard rate
    TR1  = 0x01;   //Enable Timer1

}

void UART_Tx(char ch)
{
    SBUF = ch;     //put data into Serial buffer
    while(TI ==0); //wait until transmit finish
    TI = 0;        //Transmit complete make Transmit interput to zero
}


void UART_Txstr(uint8_t *str)
{
    while(*str)
    {
        UART_Tx(*str++);
    }
    Delay(10000000);
}


/**** 1sec delay **************/

void Delay(uint8_t num)
{
    uint8_t i,j;
    for(i=0;i<num;i++)
    {
      for(j=0;j<114;j++)
      {
      }
    }
}
