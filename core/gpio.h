#ifndef _GPIO_H
#define _GPIO_H

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

class GPIO
{

	private:
	GPIO_TypeDef* Port;
	GPIO_InitTypeDef GPIO_InitStructure;

	public:
	GPIO(GPIO_TypeDef* Port, uint16_t Pin);
	void init(GPIOMode_TypeDef Mode, GPIOOType_TypeDef OType, GPIOPuPd_TypeDef PuPd, GPIOSpeed_TypeDef Speed);
	void init(GPIOPuPd_TypeDef PuPd);
	void init(GPIOOType_TypeDef OType, GPIOPuPd_TypeDef PuPd, GPIOSpeed_TypeDef Speed = GPIO_High_Speed);
	void init(GPIOOType_TypeDef OType, GPIOPuPd_TypeDef PuPd, uint8_t AF);
	void rcc(FunctionalState state);
	void write(BitAction BitVal);
	uint8_t read();
	uint16_t getPinSource();

};

#endif
