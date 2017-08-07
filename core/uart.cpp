#include "uart.h"

UART::UART(USART_TypeDef* USART, GPIO* TX, GPIO* RX, uint32_t rcc, uint8_t rcc_line, uint8_t AF, uint16_t IRQ)
{
	this->USART = USART;
	this->TX = TX;
	this->RX = RX;
	this->rcc = rcc;
	this->rcc_line = rcc_line;
	this->AF = AF;
	this->IRQ = IRQ;
	this->listener = 0;
}

void UART::init(uint32_t BaudRate)
{
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	this->TX->rcc(ENABLE);
	this->RX->rcc(ENABLE);
	switch(rcc_line)
	{
		case 1:
			RCC_APB1PeriphClockCmd(this->rcc, ENABLE);
			break;
		case 2:
			RCC_APB2PeriphClockCmd(this->rcc, ENABLE);
			break;
	}
	this->TX->init(GPIO_OType_PP, GPIO_PuPd_UP, this->AF);
	this->RX->init(GPIO_OType_PP, GPIO_PuPd_UP, this->AF);
	USART_InitStructure.USART_BaudRate = BaudRate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(this->USART, &USART_InitStructure);
	USART_Cmd(this->USART, ENABLE);
	NVIC_InitStructure.NVIC_IRQChannel = this->IRQ;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void UART::interrupt(void (*callback)(const uint8_t byte))
{
	this->listener = callback;
}

void UART::tx_byte(uint8_t byte)
{
	while (USART_GetFlagStatus(this->USART, USART_FLAG_TXE) == RESET);
	USART_SendData(this->USART, byte);
}

void UART::tx(const char* data, ...)
{
	va_list args;
	char buffer[256];
	char* ptr = buffer;
	va_start(args, data);
	vsprintf(buffer, data, args);
	va_end(args);
	while (ptr != NULL)
	{
		this->tx_byte(*ptr);
		ptr++;
	}
}
