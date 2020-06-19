#include "stm32f4xx.h"                  // Device header

void USART2_init(void);

int main(void)
{
	USART2_init();
	
	return 0;
}

void USART2_init(void)
{
	RCC->AHB1ENR |= 1;	// Enable clock access for USART2 pin (PA2)
	RCC->APB1ENR |= 0x20000;	//Enable USART2 pin
	
	GPIOA->AFR[0] = 0x0700;
	GPIOA->MODER |= 0x0020; // Set PA2 to alternate function
	
	USART2->BRR = 0x0683;		// 9600 @ 16MHz
	USART2->CR1 = 0x0008;		// Enable TX
	USART2->CR1 |= 0x20000;		// Enable USART module
}
