/*
		Author: Emirhan Gocturk
		Date: July 1, 2020
		Description: Transmit only UART on USART2 of stm32f446RET6
*/

#include "stm32f4xx.h"                  // Device header

void USART2_init(void);
void USART_write(char ch);

int main(void)
{
	USART2_init();
	
	while(1)
	{
		USART_write('H');
		USART_write('N');
		USART_write('E');
		USART_write('\n');
	}
	
	return 0;
}

void USART2_init(void)
{
	RCC->APB1ENR |= 0x20000;	//Enable USART2
	RCC->AHB1ENR |= 1;	// Enable clock access for USART2 pin (PA2)
	
	GPIOA->AFR[0] = 0x0700;
	GPIOA->MODER |= 0x0020; // Set PA2 to alternate function
	
	USART2->BRR = 0x0683;		// 9600 @ 16MHz
	USART2->CR1 = 0x0008;		// Enable TX
	USART2->CR1 |= 0x2000;		// Enable USART module
}

void USART_write(char ch)
{
	while(!(USART2->SR & 0x0080)){}	// Check transmit buffer via status register
	USART2->DR = (ch & 0xFF); // Put data into data register
}