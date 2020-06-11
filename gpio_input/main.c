#include "stm32f4xx.h"                  // Device header

int main(void)
{
	RCC->AHB1ENR |= 0x1; // Port A
	RCC->AHB1ENR |= 0x4; // Port C
	
	// Enable PA5 as output
	GPIOA->MODER |= 0x400;
	
	while(1)
	{
		// IF PC13 is high
		if(GPIOC->IDR & 0x2000)
		{
			GPIOA->BSRR |= 0x200000;	// Set PA5 high
		}
		else
		{
			GPIOA->BSRR |= 0x20;	// Set PA5 low
		}
	}
	
	return 0;
}