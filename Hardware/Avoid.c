#include "stm32f10x.h" 
#include "Motor.h"
#include "OLED.h"
#include "menu.h"
void Avoid_Init(void)
{
	// 1. 初始化必要的时钟和备份域访问
    #if defined(STM32F10X)
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);    // 使能PWR时钟
    PWR_BackupAccessCmd(ENABLE);                           // 允许访问备份域
    #endif

    // 2. 关闭LSE振荡器（如果PC14/PC15连接了晶振且需释放引脚）
    RCC_LSEConfig(RCC_LSE_OFF);                            // 关闭LSE

    // 3. 配置GPIOC的PC13和PC14为浮空输入
    GPIO_InitTypeDef GPIO_InitStruct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);  // 使能GPIOC时钟
    
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;  // 选择PC13和PC14
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;     // 浮空输入模式
    GPIO_Init(GPIOC, &GPIO_InitStruct);
	void voice_init();
}
void Avoid_Detection(void)//如果有障碍，停车直到障碍被移除
{
	uint8_t Num = 0;
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14) == 0)//有障碍
	{
		Num = 1;
	}
	while(Num == 1)//障碍未移除
	{

		Motor_Stop();//停车
		play(11);
//		OLED_Clear();
//		OLED_ShowString(1,1,"Obstacle!");
		if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14) == 1)//无障碍
		{
			play(14);
			Num = 0;
			
		}
	}                                                                                                                                                                                                                                                       
}
