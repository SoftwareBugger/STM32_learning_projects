#include "stm32f10x.h"

void SystemInit(void)
{
	
}

int main()
{
	RCC_APB2ENR |= 1 << 3; // enable clock
	GPIOB_CRL &= ~(0x0F << (4*5)); // clear PB 5
	GPIOB_CRL |= (0x03 << (4*5)); // write entire half byte to 0011 according to reference mannual to set pull n push mode
	// we use GPIO_BSRR to control gpio
	GPIOB_BSRR |= (1<<(16+5)); // we are driving active low led so write 1 to the bit 5 reset
	while(1)
	{
		
	}
}



