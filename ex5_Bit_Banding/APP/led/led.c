#include "led.h"

/**
 * @brief Init Led encapsulation
 * 
 */
void LED_init(void) 
{
		// enable clock at GPIO port B so that config is in effect
    RCC_APB2PeriphClockCmd(LED1_PORT_RCC, ENABLE);
	
    // configure GPIO initialization structure
    GPIO_InitTypeDef GPIO_InitStruct;
    
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStruct.GPIO_Pin = LED1_PIN;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
    GPIO_Init(LED1_PORT, &GPIO_InitStruct);
		// Set default input high
		GPIO_SetBits(LED1_PORT, LED1_PIN);
	
		// enable clock at GPIO port B so that config is in effect
    RCC_APB2PeriphClockCmd(LED2_PORT_RCC, ENABLE);
	
    
		GPIO_InitStruct.GPIO_Pin = LED1_PIN;
	
    GPIO_Init(LED2_PORT, &GPIO_InitStruct);
		// Set default input high
		GPIO_SetBits(LED2_PORT, LED2_PIN);
}