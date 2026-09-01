#include "stm32f10x.h"                  // Device header


void vv(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure1);
  //GPIO_SetBits(GPIOA, GPIO_Pin_1);
	//GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}
	

void liangmie(void)
{
   if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)==0)
	 {GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	  GPIO_ResetBits(GPIOA, GPIO_Pin_5);}
   if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)==1)
	 {GPIO_SetBits(GPIOA, GPIO_Pin_4);
	  GPIO_SetBits(GPIOA, GPIO_Pin_5);
	 }
}
