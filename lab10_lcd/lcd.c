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
	write(0x40, 0); // row1
	write(0x00, 1);
	write(0x41, 0);	// row2
	write(0x0A, 1);
	write(0x42, 0);	// row3
	write(0x0A, 1);
	write(0x43, 0);	// row4
	write(0x00, 1);
	write(0x44, 0);	// row5
	write(0x11, 1);
	write(0x45, 0);	// row6
	write(0x0E, 1);
	write(0x46, 0);	// row7
	write(0x00, 1);
	write(0x80 | 0x40, 0); // cursor init position => 0x80|0x40
	write(0x00, 1);
	
	write(0x48, 0); // row1
	write(0x00, 1);
	write(0x49, 0);	// row2
	write(0x0A, 1);
	write(0x4A, 0);	// row3
	write(0x1F, 1);
	write(0x4B, 0);	// row4
	write(0x1F, 1);
	write(0x4C, 0);	// row5
	write(0x0E, 1);
	write(0x4D, 0);	// row6
	write(0x04, 1);
	write(0x4E, 0);	// row7
	write(0x00, 1);
	write(0x80 | 0x41, 0); // cursor init position => 0x80|0x40
	write(0x00, 1);
	
	while(1);
}

void print_msg(char *msg)
{
	for(; *msg !=  '\0'; msg++)
		write(*msg, 1);
}

void write(char cmd, int rs_value)
{
	P1 = cmd;
	P3_7 = rs_value;
	P3_6 = 1;
	delay(100);
	P3_6 = 0;
}

void delay(unsigned int i)
{
	while(i--);
}
