#ifndef _UART_H
#define _UART_H

#include "stm32f4xx_usart.h"
#include "gpio.h"

class UART
{
	USART_TypeDef* USART;
	GPIO* tx;
	GPIO* rx;
	uint32_t rcc;
	uint8_t rcc_line;
	uint8_t af;
	uint16_t irq;
}

#endif
