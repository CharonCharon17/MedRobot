#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//打开GPIOA时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;				//定义结构体变量

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;		//上拉输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_3| GPIO_Pin_7;//配置 PA1、PA3、PA7
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   
	GPIO_Init(GPIOA,&GPIO_InitStructure);				//GPIOA初始化
	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);// 禁用 JTAG，保留 SWD
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15;// PA15
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;// PB3, PB4
    GPIO_Init(GPIOB, &GPIO_InitStruct);
}

/**
  * @brief 获取按键值
  * @param  无
  * @retval KeyNum,要读取的按键值
  */
void usart()
	{
	if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE))
	USART_ReceiveData(USART1);
	}
uint8_t Key_GetNum(void)
{
	
	uint8_t KeyNum = 0;							//默认为0,没有按键按下返回0
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3) == 0)//读取B3口的输入,如果按下(0)
	{
		Delay_ms(20);							//按键消抖
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3) == 0);//直到松手往下走
		Delay_ms(20);							//按键消抖
		KeyNum = 1;								//返回键码1
	}
	
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4) == 0)//读取B3口的输入,如果按下(0)
	{
		Delay_ms(20);							//按键消抖
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4) == 0);//直到松手往下走
		Delay_ms(20);							//按键消抖
		KeyNum = 2;								//返回键码2
	}

	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15) == 0)//读取A15口的输入,如果按下(0)
	{
		Delay_ms(20);							//按键消抖
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15) == 0);//直到松手往下走
		Delay_ms(20);							//按键消抖
		KeyNum = 3;								//返回键码3
	}

	
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1) == 0)//读取A7口的输入,如果按下(0)
	{
		Delay_ms(20);							//按键消抖
		//while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1) == 0);//直到松手往下走
		Delay_ms(20);							//按键消抖
		KeyNum = 4;								//返回键码6
	}
	
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3) == 0)//读取A7口的输入,如果按下(0)
	{
		Delay_ms(20);							//按键消抖
		//while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3) == 0);//直到松手往下走
		Delay_ms(20);							//按键消抖
		KeyNum = 5;								//返回键码6
	}

	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7) == 0)//读取A7口的输入,如果按下(0)
	{
		Delay_ms(20);							//按键消抖
		//while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7) == 0);//直到松手往下走
		Delay_ms(20);							//按键消抖
		KeyNum = 6;								//返回键码6
	}
	usart(); // 蓝牙遥控
    char data = USART_ReceiveData(USART1); 
    switch (data) 
    {
        case 'a': 
			Delay_ms(80);KeyNum = 1;break;
        case 'b': 
			Delay_ms(80);KeyNum = 2;break;
        case 'c': 
			Delay_ms(80);KeyNum = 3;break;
        case 'd': 
			Delay_ms(80);KeyNum = 4;break;
        case 'e': 
			Delay_ms(80);KeyNum = 5;break;
        case 'f': 
			Delay_ms(80);KeyNum = 6;break;
//		case 'y': 
//			Delay_ms(80);KeyNum = 0;break;
		default: 
			//KeyNum = 0;
			break;
		
    }
	
	return KeyNum;
}
