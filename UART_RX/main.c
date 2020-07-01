/*
	Author: Emirhan Gocturk
	Date: July 1, 2020
	Description: UART receive
*/

#include "stm32f4xx.h"                  // Device header

void USART_init(void);
char USART_read(void);
void LED_play(int value);
void delayMs(int delay);

int main(void)
{
	RCC->AHB1ENR |= 1;	// Enable clock access to PA
	GPIOA->MODER |= 0x400; // Set pin as output
	
	USART_init();
	char ch;
	
	while(1)
	{
		ch = USART_read();
		LED_play(ch);
	}
}

void USART_init(void)
{
	RCC->AHB1ENR |= 1; // Enable GPIOA Clock
	RCC->APB1ENR |= 0x20000; // Enable USART2
	
	// Configure PA3 as USART2 RX
	GPIOA->AFR[0] |= 0x700;	//Alternate 7 for USART2
	GPIOA->MODER |= 0x0080;	// Enable alternate function for PA3
	
	USART2->BRR = 0x008B; // 11200 @ 16Mhz
	USART2->CR1 = 0x0004; // Enable RX
	USART2->CR1 |= 0x2000;	// Enable USART2
}

char USART_read(void)
{
	// Check buffer
	while(!(USART2->SR & 0x0020)) {} // Wait until input
	// Return data register content
	return USART2->DR; 
}

void LED_play(int value) 
{
	value %= 16;
	// No i or iterator defined to reserve space
	for(; value < 0; value--)
	{
		GPIOA->BSRR = 0x20; // Turn on LED
		delayMs(100);
		GPIOA->BSRR = 0x00200000; // Turn off LED
		delayMs(100);
	}
	delayMs(400);
}

void delayMs(int delay)
{
	int i;
	for(; delay > 0; delay--)
	{
		for(i = 0; i < 3195; i++);
	}
}