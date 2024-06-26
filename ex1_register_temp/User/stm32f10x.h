#define PERIPH_BASE      ((unsigned int)0x40000000)
	
#define APB2PERIPH_BASE  (PERIPH_BASE + 0x00010000)

#define GPIOB_BASE       (APB2PERIPH_BASE + 0x0C00)

#define GPIOB_CRL 	 	 *(unsigned int*)(GPIOB_BASE+0x00)
#define GPIOB_CRH 	 	 *(unsigned int*)(GPIOB_BASE+0x04)
#define GPIOB_IDR 	 	 *(unsigned int*)(GPIOB_BASE+0x08)
#define GPIOB_ODR 	 	 *(unsigned int*)(GPIOB_BASE+0x0C)
#define GPIOB_BSRR 	 	 *(unsigned int*)(GPIOB_BASE+0x10)
#define GPIOB_BRR 	 	 *(unsigned int*)(GPIOB_BASE+0x14)
#define GPIOB_LCKR 	 	 *(unsigned int*)(GPIOB_BASE+0x18)


#define AHBPERIPH_BASE   (PERIPH_BASE + 0x20000)

#define RCC_BASE 		 (AHBPERIPH_BASE + 0x1000) // clock address
#define RCC_APB2ENR 	 *(unsigned int*)(RCC_BASE+0x18) // APB2 peripheral clock enable resgister offset is 0x18
// forward declarations
void SystemInit(void);
int main();