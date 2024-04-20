#ifndef _led_H
#define _led_H // prevent redefinition when including .h files

#include "stm32f10x.h"
#define LED1_PORT_RCC			    RCC_APB2Periph_GPIOB
#define LED1_PORT					GPIOB
#define LED1_PIN					GPIO_Pin_5

#define LED2_PORT_RCC			    RCC_APB2Periph_GPIOE
#define LED2_PORT					GPIOE
#define LED2_PIN					GPIO_Pin_5

void LED_init(void);

#endif