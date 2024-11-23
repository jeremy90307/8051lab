#include <regx51.h>
#include <string.h>
#include <stdlib.h>

void init_uart();
void send(unsigned char *s);

char value;
char number[9];
int count = 0;

void main(void)
{
	init_uart();
	while(1);
}

void send(unsigned char *s)
{
	while(*s)
	{
		SBUF = *s++;
		while(TI == 0);
		TI = 0;
	}
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
	number[count++] = value;

	if(count == 9)
	{
		count = 0;
		if(strncmp(number, "N16121638", 9) != 0)
		{
			send("\r\n");
			send("wrong\r\n");
		}
		else
		{
			send("\r\n");
			send("correct\r\n");
		}
	}
}