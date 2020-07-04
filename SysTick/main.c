#include "stm32f4xx.h"                  // Device header

void init_led(void);

int main(void)
{
	init_led();
	
	// Configure SysTick
	// 16Mhz / value given
	SysTick->LOAD = 1600000 - 1;
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
	
	while(1)
	{
		// Check if count flag is set
		if(SysTick->CTRL & 0x10000)
		{
			GPIOA->ODR ^= 0x20;
		}
	}
	
	return 0;
}

void init_led(void)
{
	// Enable AHB1 bus
	RCC->AHB1ENR |= 1;
	// GPIOA PA5 Output mode
	GPIOA->MODER |= 0x400;
}