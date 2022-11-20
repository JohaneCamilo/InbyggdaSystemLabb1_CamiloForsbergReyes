#include <avr/io.h>
#include <util/delay.h>
#include "stdint.h"
#include "serial.h"

void USART_Init()
{
//Set baud rate
UBRR0H = (unsigned char)(MYUBRR>>8);
UBRR0L = (unsigned char)MYUBRR;
//Enable receiver and transmitter 
UCSR0B = (1<<TXEN0)|(1<<RXEN0);
//UART_init, char size is 8 bits 
UCSR0B &= ~(1<<UCSZ02);
UCSR0C |= (1<<UCSZ00);
UCSR0C |= (1<<UCSZ01);
UCSR0C |= (1<<UPM01);
UCSR0C |= (1<<UPM00);
UCSR0C &= ~(1<<USBS0); //1 stop bit
}

char uart_getchar(void)
{
// Wait to recieve data
while (!(UCSR0A & (1<<RXC0)))
;
//Get and return received data from buffer
return UDR0;
}

void uart_putchar(unsigned char data)
{
// Waits for an empty transmit buffer
while (!(UCSR0A & (1<<UDRE0)));
//Puts data into the buffer then sends data
UDR0 = data;
    if (data == '\n')
    {
        uart_putchar('\r');

    }
    return UDR0;
}

void uart_putstr(char *str)
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if(str[i]=='\n')
        {
            uart_putchar('\r');
        }
        uart_putchar(str[i]);
    }
}

void uart_echo()
{
    uart_putchar(uart_getchar());
}
