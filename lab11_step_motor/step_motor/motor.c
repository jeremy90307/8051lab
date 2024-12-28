#include <regx51.h>

void delay(int);
void turn();

code char one_phase[] = {0x01, 0x02, 0x04, 0x08};
code char two_phase[] = {0x0c, 0x06, 0x03, 0x09};
code char cw[] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09};
code char ccw[] = {0x09, 0x08, 0x0C, 0x04, 0x06, 0x02, 0x03, 0x01};

int dir, delay_time, speed_ctl;

void main()
{
	EA = 1;
	EX0 = 1;
	EX1 = 1;
	IT0 = 1;
	IT1 = 1;
	delay_time = 1000;

	dir = 1;
	while(1)
	{
		turn();
	}
}

void init_INT0(void) interrupt 0
{
	dir = ~dir;
}

void init_INIT1(void) interrupt 2
{
	if (delay_time == 1000)
		delay_time = 100;
	else
		delay_time = 1000;
}

void turn()
{
	int x;
	if(dir == 1)
	{
		for(x = 0; x < 8; x++)
		{
			P1 = cw[x];
			delay(delay_time);
		}
	}
	else
	{
		for(x = 0; x < 8; x++)
		{
			P1 = ccw[x];
			delay(delay_time);
		}
	}
}

void delay(int t)
{
	while(t--);
}