#ifndef UART_H
#define UART_H




void UART_Init(unsigned int baudrate);
void UART_Transmit(char data);
char UART_Receive(void);



#endif // UART_H
