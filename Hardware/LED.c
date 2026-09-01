#include "stm32f10x.h"                  // Device header


void LED_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8 | GPIO_Pin_11|GPIO_Pin_12 ;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_8 | GPIO_Pin_11 | GPIO_Pin_12 );
}

void LED8_ON(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
}

void LED8_OFF(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);
}


void LED11_ON(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_11);
}

void LED11_OFF(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);
}


void LED12_ON(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_12);
}

void LED12_OFF(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);
}

