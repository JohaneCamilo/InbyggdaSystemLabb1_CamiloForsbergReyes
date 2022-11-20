#ifndef SERIAL_H_
#define SERIAL_H_
#define FOSC 16000000 // Set clock speed
#define BAUD 38400 // Set baud rate
#define MYUBRR ((FOSC/(16*BAUD))-1)

void USART_Init();

char uart_getchar(void);

void uart_putchar(unsigned char);

void uart_putstr(char *str);

void uart_echo(void);

#endif
