#ifndef _UART_H
#define _UART_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "stm32f4xx_usart.h"
#include "misc.h"
#include "gpio.h"

class UART
{

	private:
	USART_TypeDef* USART;
	GPIO* TX;
	GPIO* RX;
	uint32_t rcc;
	uint8_t rcc_line;
	uint8_t AF;
	uint16_t IRQ;
	void (*listener)(const uint8_t byte);

	public:
	UART(USART_TypeDef* USART, GPIO* TX, GPIO* RX, uint32_t rcc, uint8_t rcc_line, uint8_t AF, uint16_t IRQ);
	void init(uint32_t BaudRate);
	void interrupt(void (*callback)(const uint8_t byte));
	void tx_byte(uint8_t byte);
	void tx(const char* data, ...);

};

#endif
