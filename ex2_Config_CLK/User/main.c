/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */  

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "led.h"
void RCC_HSE_Config(u32 div,u32 pllm) // RCC configuration
{
	RCC_DeInit(); // reset RCC clock
	RCC_HSEConfig(RCC_HSE_ON);// Turn on high speed external clock
	if(RCC_WaitForHSEStartUp()==SUCCESS) // if RCC starts up successfully
	{
		RCC_HCLKConfig(RCC_SYSCLK_Div1);// Set AHB clock
		RCC_PCLK1Config(RCC_HCLK_Div2);// Set APB1 clock
		RCC_PCLK2Config(RCC_HCLK_Div1);// Set APB2 clock
		RCC_PLLConfig(div,pllm);// set the divider of pll as the given parameters
		RCC_PLLCmd(ENABLE); // PLL enable
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);// Wait for PLL to be ready
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);// Set the SYSCLK source as PLL CLK
		while(RCC_GetSYSCLKSource()!=0x08); // 
	}
}
/**
 * @brief pseudo delay
 * 
 * @param units 
 */
void delay(u32 units)
{
  while (--units);
}
/**
 * @brief main function
 * 
 * @return int 
 */
int main()
{
  LED_init();
	while (1) {
		// HSE is typically 8MHz in our system
    RCC_HSE_Config(RCC_PLLSource_HSE_Div2, RCC_PLLMul_9);
		GPIO_ResetBits(LED1_PORT, LED1_PIN);
    GPIO_SetBits(LED2_PORT, LED2_PIN);
    // light it up for a while 
    delay(6000000); // simulating delay
    GPIO_SetBits(LED1_PORT, LED1_PIN);
    GPIO_ResetBits(LED2_PORT, LED2_PIN);
		delay(6000000); 
	}
}