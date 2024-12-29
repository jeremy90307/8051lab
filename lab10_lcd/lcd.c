#include <regx51.h>

void print_msg(char *);
void write(char, int);
void delay(unsigned int);

void main()
{
	write(0x38, 0);	
	write(0x0F, 0);
	write(0x06, 0);
	write(0x01, 0);
	write(0x80, 0);
	print_msg("N16121638");
	
	/* heart */
	write(0x40, 0); // CGRAM addr -> the first custom character
	write(0x00, 1);
	write(0x0A, 1);
	write(0x0A, 1);
	write(0x00, 1);
	write(0x11, 1);
	write(0x0E, 1);
	write(0x00, 1);
	write(0x80 | 0x40, 0); // cursor init position => 0x80|0x40
	write(0x00, 1);
	
	/* heart */
	write(0x48, 0); // CGRAM addr -> the second custom character
	write(0x00, 1);
	write(0x0A, 1);
	write(0x1F, 1);
	write(0x1F, 1);
	write(0x0E, 1);
	write(0x04, 1);
	write(0x00, 1);
	write(0x80 | 0x41, 0); // cursor init position => 0x80|0x40
	write(0x01, 1);
	
	while(1);
}

void print_msg(char *msg)
{
	for(; *msg !=  '\0'; msg++)
		write(*msg, 1);
}

void write(char cmd, int rs_value)
{
	P2 = cmd;
	P3_4 = rs_value;
	P3_5 = 1;
	delay(100);
	P3_5 = 0;
}

void delay(unsigned int i)
{
	while(i--);
}
