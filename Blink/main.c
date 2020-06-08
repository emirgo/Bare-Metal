//LD2 - PA5
//AHB1
//RCC->AHB1ENR


#include "stm32f4xx.h"                  // Device header

void delayMs(int delay);

int main(void)
{
	// Enable clock access to AHB1 bus
	RCC->AHB1ENR |= 1;
	
	GPIOA->MODER |= 0x400;
	
	while(1)
	{
		GPIOA->ODR |= 0x20;
		delayMs(100);
		GPIOA->ODR &=~ 0x20;
		delayMs(100);
	}
	
	return 0;
}

void delayMs(int delay)
{
	int i;
	for(; delay > 0; delay--)
	{
		for(i = 0; i < 3195; i++);
	}
}