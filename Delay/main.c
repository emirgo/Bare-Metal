#include "stm32f4xx.h"                  // Device header

void delayMs(int milliseconds);

int main(void)
{
	// Enable AHB1 for LED
	RCC->AHB1ENR |= 1;
	// Output mode for PA5
	GPIOA->MODER |= 0x400;
	
	while(1)
	{
		delayMs(100);
		GPIOA->ODR ^= 0x20;
	}
	
	return 0;
}

void delayMs(int milliseconds)
{
	// Configure systick per ms
	SysTick->LOAD = 16000;
	// Set value of the counter
	SysTick->VAL = 0;
	// Begin counter
	SysTick->CTRL = 5;
	
	int i = 0;
	for(; i < milliseconds; i++)
	{
		// Wait a millisecond
		while(!(SysTick->CTRL & 0x10000)) {}
	}
	
	// Stop counter
	SysTick->CTRL = 0;
}