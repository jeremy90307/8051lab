#include <regx51.h>

void main()
{
	IT0 = 0;  // enable a low-level signal on externalinterrupt
	EX0 = 1;  // enable INT0
	EA = 1;   // enable interrupt
	P3_4 = 0; // WR=0,clean the data
	P3_4 = 1; // WR=1,analog convert to digital
	while(1);
}

void int_0(void)interrupt 0 // INT0 interrupt function
{
	P3_5 = 0; // RD=0,read the digital data
	if(P1 > 256 * 8 / 9)
	{
		P2 = 255;
	}
	else if(P1 > 256 * 7 / 9)
	{
		P2 = 127;
	}
	else if(P1 > 256 * 6 / 9)
	{
		P2 = 63;
	}
	else if(P1 > 256 * 5 / 9)
	{
		P2 = 31;
	}
	else if(P1 > 256 * 4 / 9)
	{
		P2 = 15;
	}
	else if(P1 > 256 * 3 / 9)
	{
		P2 = 7;
	}
	else if(P1 > 256 * 2 / 9)
	{
		P2 = 3;
	}
	else if(P1 > 256 * 1 / 9)
	{
		P2 = 1;
	}
	else
	{
		P2 = 0; // LED off
	}
	P3_5 = 1; // RD = 1
	P3_4 = 0;
	P3_4 = 1;
}