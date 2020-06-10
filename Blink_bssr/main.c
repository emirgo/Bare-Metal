#include "stm32f4xx.h"                  // Device header

void delayMs(int ms);

int main(void)
{
	// Enable AHB1 clock
	RCC->AHB1ENR |= 0x1;
	
	// Output mode for PA5
	GPIOA->MODER |= 0x400;
	
	while(1)
	{
		// Set PA5 high by utilizing enable bit
		GPIOA->BSRR |= 0x20;
		delayMs(100);
		
		// Set PA5 low by utilizing reset bit
		GPIOA->BSRR |= 0x200000;
		delayMs(1000);
	}
	
	return 0;
}

void delayMs(int ms)
{
	int i = 0;
	for(; ms > 0; ms--)
	{
		for(i = 0; i < 3195; i++);
	}
}