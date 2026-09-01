#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Delay.h" 


void Motor1_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	PWM1_Init();
}

void Motor1_SetSpeed(int8_t Speed)//左
{
	if (Speed >= 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		PWM_SetCompare3(Speed);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		PWM_SetCompare3(-Speed);
	}
}

void Motor2_Init(void)//右
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	PWM2_Init();
}

void Motor2_SetSpeed(int8_t Speed)
{
	if (Speed >= 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_6);
		GPIO_ResetBits(GPIOB, GPIO_Pin_7);
		PWM_SetCompare1(Speed);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);
		GPIO_SetBits(GPIOB, GPIO_Pin_7);
		PWM_SetCompare1(-Speed);
	}
}
void Motor_Stop()
{
	Motor1_SetSpeed(0);
	Motor2_SetSpeed(0);
}

void Motor_Forward(uint8_t Speed)
{
	Motor1_SetSpeed(-Speed-3);
	Motor2_SetSpeed(Speed-0);

}  
void Motor_Backward(uint8_t Speed)
{
	Motor1_SetSpeed(Speed+3);
	Motor2_SetSpeed(-Speed+0);

}  
void Motor_TurnLeft(uint8_t Speed,float Angle)
{
	Motor1_SetSpeed(Speed+3);
	Motor2_SetSpeed(Speed-0);
	Delay_ms(Angle/90*250); 
	Motor_Stop();


}
void Motor_TurnRight(uint8_t Speed)
{
	Motor1_SetSpeed(-Speed-3);
	Motor2_SetSpeed(-Speed+0);


}  

