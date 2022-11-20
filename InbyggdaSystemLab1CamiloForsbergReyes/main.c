#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"

int main (void)
{
    DDRB |= (1<<PB3); 
    USART_Init();

    while(1)
    {
        PORTB |= (1<<PB3);
        _delay_ms(500);

        PORTB &= ~(1<<PB3);
        _delay_ms(500);

        //uart_putchar;

        //uart_putstr("Camilo\n");

        uart_echo();
    }
}
