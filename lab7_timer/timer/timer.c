#include <regx51.h>

#define TH0_INIT 0x06
#define TL0_INIT 0x06
#define TIMER0_INT_EXE_TIME 2000

unsigned char led_state = 0x01;
unsigned int counter = 0;

void main() {
    TMOD = 0x0A;
		TCON = 0x10;
    TH0 = TH0_INIT;
    TL0 = TL0_INIT;
    IE = 0x82;
    P2 = ~led_state;
    P3_2 = 0;

    while (1) {
			
    }
}

void timer0_interrupt(void) interrupt 1 {
    counter++;
    if (counter == TIMER0_INT_EXE_TIME) {
        counter = 0;

        led_state = (led_state << 1);
        if (led_state == 0) {
            led_state = 0x01;
        }
        P2 = ~led_state;
    }
}
