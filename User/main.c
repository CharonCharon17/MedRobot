#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
#include "menu.h"
#include "yaokong.h"
#include "LED.h"  
#include "Avoid.h"  
#include "Pathfinding.h" 
#include "PWM.h" 
#include "Motor.h" 
void usart1()
{
	if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE))
	USART_ReceiveData(USART1);
}
int8_t speed=50;
int main(void)
{
	uint8_t flag=0,Key=0,fx=0;
	OLED_Init();
	voice_init();
	LED_Init ();
	Avoid_Init();
	Pathfinding_Init();
	Motor1_Init();
	Motor2_Init();
	Serial_Init();
	Key_Init();
	uint8_t f[10]={0};//判断是否选中
	//char* f1[10]={"布洛芬胶囊           ","感冒灵               ","连花清瘟             ","止咳糖浆             ","头孢拉定              ","六味地黄丸            ","阿司匹林              ","红霉素软膏            ","退热贴              ","碘伏                "};

//	play(13);
//	Delay_ms(1000);
//	play(1);
//	Delay_ms(1000);
//	play(12);
//	Delay_ms(1000);
//	play(14);
	
	
	while (1)
	{
		usart1(); // 蓝牙遥控
		char data = USART_ReceiveData(USART1); 
		if (data == 'g') 
		{ 
			OLED_Clear ();
			OLED_ShowString(0, 0,"    遥控模式       ",OLED_8X16);
			OLED_Update();
			Delay_ms(500);
			data = USART_ReceiveData(USART1); 
			while(data!= 'g')
			{
				data = USART_ReceiveData(USART1); 
				switch (data) 
				{
				case 'h': 
					Delay_ms(30);Motor_Forward(speed);break;
				case 'i': 
					Delay_ms(30);Motor_Backward(speed);break;
				case 'j': 
					Delay_ms(30);Motor_TurnLeft(speed,8);break;
				case 'k': 
					Delay_ms(30);Motor_TurnRight(speed,8);break;
				case 'x': 
					Delay_ms(30);Motor_Stop();break;
				default: 
					//KeyNum = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
					break;
				}
			}
			Delay_ms(500);
		
		}
		OLED_Clear ();
		OLED_ShowString(0, 0,"   请选择房间      ",OLED_8X16);
		OLED_Update();

		Key = Key_GetNum();
		if(Key == 4)//按下1按钮,led1亮
		{
			OLED_ShowString(0, 0,"   请添加药品      ",OLED_8X16);
			OLED_Update();
			Delay_ms(2000);
			LED8_ON();
			fx=1;
			while(fx==1)
			{
				flag = menu();//得到所选药品编号
				Delay_ms(50);
				Key = Key_GetNum();
				if(Key == 4)//选定药品，出发
				{
					xuanze();
					GetRoom1();//出发
					fx=0;
					LED8_OFF();
					menuClear();
				}

			}
		}
		if(Key==5)//按下2按钮,led2亮
		{
			OLED_ShowString(0, 0,"   请添加药品      ",OLED_8X16);
			OLED_Update();
			Delay_ms(2000);
			LED11_ON();
			fx=1;
			while(fx==1)
			{
				flag = menu();//得到所选药品编号
				Delay_ms(50);
				Key = Key_GetNum();
				if(Key == 5)//选定药品，出发
				{
					xuanze();
					GetRoom2();//出发
					fx=0;
					LED11_OFF();
					menuClear();
				}

			}
		}  
		if(Key==6)//按下3按钮,led3亮
		{
			OLED_ShowString(0, 0,"   请添加药品      ",OLED_8X16);
			OLED_Update();
			Delay_ms(2000);
			LED12_ON();
			fx=1;
			while(fx==1)
			{
				flag = menu();//得到所选药品编号
				Delay_ms(50);
				Key = Key_GetNum();
				if(Key == 6)//选定药品，出发
				{
					xuanze();
					GetRoom3();//出发
					fx=0;
					LED12_OFF();
					menuClear();
				}

			}
		}  
	}
			
}

