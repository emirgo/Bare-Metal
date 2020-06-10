#include "stm32f4xx.h"                  // Device header

void delayMs(int ms);

int main(void)
{
	// Enable AHB1 clock
	RCC->AHB1ENR |= 0x1;
	
	// GPIOA Mode
	GPIOA->MODER |= 0x400;
	
	while(1)
	{
		// Data direction enable
		GPIOA->ODR |= 0x20;
		delayMs(100);
		// Data direction disable
		GPIOA->ODR &=~ 0x20;
		delayMs(1000);
	}
	
	return 0;
}

void delayMs(int ms)
{
	for(; ms > 0; ms--)
	{
		for(int j = 0; j < 3195; j++);
	}
}