/**********************Increment counter 0 to 255 and dislay in seven segment display**********************/

#include<stdio.h>
#include<reg51.h>
#include"stdint.h"

sbit Seg0 = P2^0; // Port2 pin0 connected to Seg0 enable pin
sbit Seg1 = P2^1; // Port2 pin1 connected to Seg1 enable pin
sbit Seg2 = P2^2; // Port2 pin2 connected to Seg2 enable pin
sbit Seg3 = P2^3; // Port2 pin3 connected to Seg3 enable pin


void Seg_num_0(void);
void Seg_num_1(void);
void Seg_num_2(void);
void Seg_num_3(void);

void Delay_ms(uint16_t);

void main()
{
    P2 = 0x00; // Port2 assigned as output
    P1 = 0x00; // Port1 assigned as output
    while(1)
    {
        P2 |= 0x0F;
        Seg_num_0();
        //Seg_num_1();
        //Seg_num_2();
        //Seg_num_3();
        Delay_ms(1000);
    }
} 


void Seg_num_0(void)
{
    
    P1 |= 0x3F;
    Delay_ms(1000);
    P1 = (P1&0)|(0x06);
    Delay_ms(1000);
    P1 = (P1&0)|0x5B;
    Delay_ms(1000);
    P1 = (P1&0)|0x4F;
    Delay_ms(1000);
    P1 = (P1&0)|0x66;
    Delay_ms(1000);
    P1 = (P1&0)|0x6D;
    Delay_ms(1000);
    P1 = (P1&0)|0x7D;
    Delay_ms(1000);
    P1 = (P1&0)|0x07;
    Delay_ms(1000);
    P1 = (P1&0)|0x7F;
    Delay_ms(1000);
    P1 = (P1&0)|0x67;
    Delay_ms(1000);

}
void Seg_num_1(void)
{
    P2 |= 0x0;
    P1 |= 0x3F;

}
void Seg_num_2(void)
{
    P2 |= 0x03;
    P1 |= 0x3F;

}
void Seg_num_3(void)
{
    P2 |= 0x04;
    P1 |= 0x3F;

}

void Delay_ms(uint16_t ms)
{
    uint16_t i,j;

    for(i=0; i<ms; i++)
    {
        for(j=0;j<114;j++)
        {
        //nothing to do
        }
    }
}


