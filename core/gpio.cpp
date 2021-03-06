#include "gpio.h"

GPIO PA0(GPIOA, GPIO_Pin_0);
GPIO PA1(GPIOA, GPIO_Pin_1);
GPIO PA2(GPIOA, GPIO_Pin_2);
GPIO PA3(GPIOA, GPIO_Pin_3);
GPIO PA4(GPIOA, GPIO_Pin_4);
GPIO PA5(GPIOA, GPIO_Pin_5);
GPIO PA6(GPIOA, GPIO_Pin_6);
GPIO PA7(GPIOA, GPIO_Pin_7);
GPIO PA8(GPIOA, GPIO_Pin_8);
GPIO PA9(GPIOA, GPIO_Pin_9);
GPIO PA10(GPIOA, GPIO_Pin_10);
GPIO PA11(GPIOA, GPIO_Pin_11);
GPIO PA12(GPIOA, GPIO_Pin_12);
GPIO PA13(GPIOA, GPIO_Pin_13);
GPIO PA14(GPIOA, GPIO_Pin_14);
GPIO PA15(GPIOA, GPIO_Pin_15);
GPIO PB0(GPIOB, GPIO_Pin_0);
GPIO PB1(GPIOB, GPIO_Pin_1);
GPIO PB2(GPIOB, GPIO_Pin_2);
GPIO PB3(GPIOB, GPIO_Pin_3);
GPIO PB4(GPIOB, GPIO_Pin_4);
GPIO PB5(GPIOB, GPIO_Pin_5);
GPIO PB6(GPIOB, GPIO_Pin_6);
GPIO PB7(GPIOB, GPIO_Pin_7);
GPIO PB8(GPIOB, GPIO_Pin_8);
GPIO PB9(GPIOB, GPIO_Pin_9);
GPIO PB10(GPIOB, GPIO_Pin_10);
GPIO PB11(GPIOB, GPIO_Pin_11);
GPIO PB12(GPIOB, GPIO_Pin_12);
GPIO PB13(GPIOB, GPIO_Pin_13);
GPIO PB14(GPIOB, GPIO_Pin_14);
GPIO PB15(GPIOB, GPIO_Pin_15);
GPIO PC0(GPIOC, GPIO_Pin_0);
GPIO PC1(GPIOC, GPIO_Pin_1);
GPIO PC2(GPIOC, GPIO_Pin_2);
GPIO PC3(GPIOC, GPIO_Pin_3);
GPIO PC4(GPIOC, GPIO_Pin_4);
GPIO PC5(GPIOC, GPIO_Pin_5);
GPIO PC6(GPIOC, GPIO_Pin_6);
GPIO PC7(GPIOC, GPIO_Pin_7);
GPIO PC8(GPIOC, GPIO_Pin_8);
GPIO PC9(GPIOC, GPIO_Pin_9);
GPIO PC10(GPIOC, GPIO_Pin_10);
GPIO PC11(GPIOC, GPIO_Pin_11);
GPIO PC12(GPIOC, GPIO_Pin_12);
GPIO PC13(GPIOC, GPIO_Pin_13);
GPIO PC14(GPIOC, GPIO_Pin_14);
GPIO PC15(GPIOC, GPIO_Pin_15);
GPIO PD0(GPIOD, GPIO_Pin_0);
GPIO PD1(GPIOD, GPIO_Pin_1);
GPIO PD2(GPIOD, GPIO_Pin_2);
GPIO PD3(GPIOD, GPIO_Pin_3);
GPIO PD4(GPIOD, GPIO_Pin_4);
GPIO PD5(GPIOD, GPIO_Pin_5);
GPIO PD6(GPIOD, GPIO_Pin_6);
GPIO PD7(GPIOD, GPIO_Pin_7);
GPIO PD8(GPIOD, GPIO_Pin_8);
GPIO PD9(GPIOD, GPIO_Pin_9);
GPIO PD10(GPIOD, GPIO_Pin_10);
GPIO PD11(GPIOD, GPIO_Pin_11);
GPIO PD12(GPIOD, GPIO_Pin_12);
GPIO PD13(GPIOD, GPIO_Pin_13);
GPIO PD14(GPIOD, GPIO_Pin_14);
GPIO PD15(GPIOD, GPIO_Pin_15);
GPIO PE0(GPIOE, GPIO_Pin_0);
GPIO PE1(GPIOE, GPIO_Pin_1);
GPIO PE2(GPIOE, GPIO_Pin_2);
GPIO PE3(GPIOE, GPIO_Pin_3);
GPIO PE4(GPIOE, GPIO_Pin_4);
GPIO PE5(GPIOE, GPIO_Pin_5);
GPIO PE6(GPIOE, GPIO_Pin_6);
GPIO PE7(GPIOE, GPIO_Pin_7);
GPIO PE8(GPIOE, GPIO_Pin_8);
GPIO PE9(GPIOE, GPIO_Pin_9);
GPIO PE10(GPIOE, GPIO_Pin_10);
GPIO PE11(GPIOE, GPIO_Pin_11);
GPIO PE12(GPIOE, GPIO_Pin_12);
GPIO PE13(GPIOE, GPIO_Pin_13);
GPIO PE14(GPIOE, GPIO_Pin_14);
GPIO PE15(GPIOE, GPIO_Pin_15);
GPIO PF0(GPIOF, GPIO_Pin_0);
GPIO PF1(GPIOF, GPIO_Pin_1);
GPIO PF2(GPIOF, GPIO_Pin_2);
GPIO PF3(GPIOF, GPIO_Pin_3);
GPIO PF4(GPIOF, GPIO_Pin_4);
GPIO PF5(GPIOF, GPIO_Pin_5);
GPIO PF6(GPIOF, GPIO_Pin_6);
GPIO PF7(GPIOF, GPIO_Pin_7);
GPIO PF8(GPIOF, GPIO_Pin_8);
GPIO PF9(GPIOF, GPIO_Pin_9);
GPIO PF10(GPIOF, GPIO_Pin_10);
GPIO PF11(GPIOF, GPIO_Pin_11);
GPIO PF12(GPIOF, GPIO_Pin_12);
GPIO PF13(GPIOF, GPIO_Pin_13);
GPIO PF14(GPIOF, GPIO_Pin_14);
GPIO PF15(GPIOF, GPIO_Pin_15);
GPIO PG0(GPIOG, GPIO_Pin_0);
GPIO PG1(GPIOG, GPIO_Pin_1);
GPIO PG2(GPIOG, GPIO_Pin_2);
GPIO PG3(GPIOG, GPIO_Pin_3);
GPIO PG4(GPIOG, GPIO_Pin_4);
GPIO PG5(GPIOG, GPIO_Pin_5);
GPIO PG6(GPIOG, GPIO_Pin_6);
GPIO PG7(GPIOG, GPIO_Pin_7);
GPIO PG8(GPIOG, GPIO_Pin_8);
GPIO PG9(GPIOG, GPIO_Pin_9);
GPIO PG10(GPIOG, GPIO_Pin_10);
GPIO PG11(GPIOG, GPIO_Pin_11);
GPIO PG12(GPIOG, GPIO_Pin_12);
GPIO PG13(GPIOG, GPIO_Pin_13);
GPIO PG14(GPIOG, GPIO_Pin_14);
GPIO PG15(GPIOG, GPIO_Pin_15);

GPIO::GPIO(GPIO_TypeDef* Port, uint16_t Pin)
{
	this->Port = Port;
	GPIO_StructInit(&(this->GPIO_InitStructure));
	this->GPIO_InitStructure.GPIO_Pin = Pin;
}

void GPIO::init(GPIOMode_TypeDef Mode, GPIOOType_TypeDef OType, GPIOPuPd_TypeDef PuPd, GPIOSpeed_TypeDef Speed)
{
	this->GPIO_InitStructure.GPIO_Mode = Mode;
	this->GPIO_InitStructure.GPIO_OType = OType;
	this->GPIO_InitStructure.GPIO_PuPd = PuPd;
	this->GPIO_InitStructure.GPIO_Speed = Speed;
	GPIO_Init(this->Port, &(this->GPIO_InitStructure));
}

void GPIO::init(GPIOPuPd_TypeDef PuPd)
{
	this->GPIO_InitStructure.GPIO_PuPd = PuPd;
	GPIO_Init(this->Port, &(this->GPIO_InitStructure));
}

void GPIO::init(GPIOOType_TypeDef OType, GPIOPuPd_TypeDef PuPd, GPIOSpeed_TypeDef Speed)
{
	this->GPIO_InitStructure.GPIO_OType = OType;
	this->GPIO_InitStructure.GPIO_PuPd = PuPd;
	this->GPIO_InitStructure.GPIO_Speed = Speed;
	GPIO_Init(this->Port, &(this->GPIO_InitStructure));
}

void GPIO::init(GPIOOType_TypeDef OType, GPIOPuPd_TypeDef PuPd, uint8_t AF)
{
	this->GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;
	this->GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	this->GPIO_InitStructure.GPIO_OType = OType;
	this->GPIO_InitStructure.GPIO_PuPd = PuPd;
	GPIO_PinAFConfig(this->Port, this->getPinSource(), AF);
	GPIO_Init(this->Port, &(this->GPIO_InitStructure));
}

void GPIO::rcc(FunctionalState state)
{
	if (this->Port == GPIOA)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, state);
	}
	else if (this->Port == GPIOB)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, state);
	}
	else if (this->Port == GPIOC)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, state);
	}
	else if (this->Port == GPIOD)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, state);
	}
	else if (this->Port == GPIOE)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, state);
	}
	else if (this->Port == GPIOF)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, state);
	}
	else if (this->Port == GPIOG)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, state);
	}
}

void GPIO::write(BitAction BitVal)
{
	GPIO_WriteBit(this->Port, this->GPIO_InitStructure.GPIO_Pin, BitVal);
}

uint8_t GPIO::read()
{
	return GPIO_ReadInputDataBit(this->Port, this->GPIO_InitStructure.GPIO_Pin);
}

uint16_t GPIO::getPinSource()
{
	switch(this->GPIO_InitStructure.GPIO_Pin)
	{
		case GPIO_Pin_0:
			return GPIO_PinSource0;
		case GPIO_Pin_1:
			return GPIO_PinSource1;
		case GPIO_Pin_2:
			return GPIO_PinSource2;
		case GPIO_Pin_3:
			return GPIO_PinSource3;
		case GPIO_Pin_4:
			return GPIO_PinSource4;
		case GPIO_Pin_5:
			return GPIO_PinSource5;
		case GPIO_Pin_6:
			return GPIO_PinSource6;
		case GPIO_Pin_7:
			return GPIO_PinSource7;
		case GPIO_Pin_8:
			return GPIO_PinSource8;
		case GPIO_Pin_9:
			return GPIO_PinSource9;
		case GPIO_Pin_10:
			return GPIO_PinSource10;
		case GPIO_Pin_11:
			return GPIO_PinSource11;
		case GPIO_Pin_12:
			return GPIO_PinSource12;
		case GPIO_Pin_13:
			return GPIO_PinSource13;
		case GPIO_Pin_14:
			return GPIO_PinSource14;
		case GPIO_Pin_15:
			return GPIO_PinSource15;
	}
	return 0;
}
