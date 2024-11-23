#include <regx51.h>

void init_uart();
char value;

void main()
{
	init_uart();
	while(1);
}

void init_uart(void)
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xe6;
	TR1 = 1;
	IE = 0x90;
}

void init_uart_ISR(void) interrupt 4
{
	while(RI == 0);
	RI = 0;
	value = SBUF;
	P2 = ~value;
	if(value == 'q')
	{
		SBUF = value;
		while(TI == 0);
		TI = 0;
	}
}