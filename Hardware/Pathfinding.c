#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "PWM.h"
#include "Delay.h" 
#include "OLED.h"
#include "Avoid.h"
#include "Key.h"
#include "menu.h"
//  1右 2左 3中

//S B13 B14 A10


void Pathfinding_Init()
{

		GPIO_InitTypeDef GPIO_InitStructure;

	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_12 |GPIO_Pin_13 |GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);


}

uint8_t Pathfinding1_GetNum(void)
{
	uint8_t Num = 0;
	Num = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13);
//	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 1){
//		Delay_ms(20);
//		while((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)) == 0);
//		Delay_ms(20);
//		Num = 1;
//	
//	}
	return Num;
} 

uint8_t Pathfinding2_GetNum(void)
{
	uint8_t Num = 0;
	Num = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14);
	return Num;
} 

void Pathfind_Ctrl()
{
	int8_t Speed=43;
	float Angle=8;
	int8_t L,M,R,Flag=3;
	L=Pathfinding2_GetNum();
	R=Pathfinding1_GetNum();
	//M=Pathfinding3_GetNum();
	
	Avoid_Detection();//避障
	
		//  1R 2L 3M
	Motor_Forward(Speed);	
	
//	while(Pathfinding1_GetNum()==0 & Pathfinding3_GetNum()==0 & Pathfinding2_GetNum()==0)
//	{
//		Motor_Stop();
//	}
	if( (R==0 & M==0 & L==1))//(R==0 & M==1 & L==1) |
	{
//		while(!(R==0 & M==1 & L==0))
//		{
//			
//		}
//		Motor_Forward(Speed);
		Motor_TurnLeft(Speed,Angle);
		Delay_ms(20);
		Flag=2;
		
	}
	
	
	if( (R==1 & M==0 & L==0))//(R==1 & M==1 & L==0) |
	{	
//			while(!(R==0 & M==1 & L==0))
//			{
//				
//				
//			}
//			Motor_Forward(Speed);
		Motor_TurnRight(Speed,Angle); 
		Delay_ms(20);
		Flag=1;
	}
	if(R==0 & M==0 & L==0)
	{
		if(Flag==1)
		{
			Motor_TurnLeft(Speed,Angle);
		
		}
		if(Flag==2)
		{
			Motor_TurnRight(Speed,Angle);
		
		}
		Flag=3;
	
	}
	
}


void Pathfinding_GetNum(void)//白0 黑1
{
	Avoid_Init();
	
	
} 




void GetRoom1(void)//去房间1
{
	Pathfinding_GetNum();
	uint8_t L,R;
//	int8_t Speed=43;
//	float Angle=10;
	uint8_t Flag = 0,f=0,Key;
	L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
	R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右	
	Delay_ms(1500);
	while(f == 0)
	{
		
			
//		Motor_Forward(Speed);
		
		Pathfind_Ctrl();
		L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
		R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右	
		if(L == 1 && Flag == 0)//到达药房 
		{
			Motor_Stop();
			Key = Key_GetNum();
			
			while(Key != 4)//直到按下房间1按钮
			{
				Key = Key_GetNum();
			}
			Flag=1;
			Delay_ms(1500);
			Key=0;
		}
		
		//Pathfind_Ctrl();
		L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
		R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右	
		
		if(R == 1 && Flag == 1)//判定到达房间1
		{	
			
			Motor_Stop();//停车
			voice_ctrl();//播报
			//Delay_s(2);//等
			
			
			Key = Key_GetNum();
			while(Key != 4)//直到按下房间1按钮
			{
				Key = Key_GetNum();
				
			}
			Delay_ms(1500);
			Flag=2;
			
		}
		//\Pathfind_Ctrl();
		L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
		R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右	
		//Key = Key_GetNum();
	
		if(L==1 && R==1 && Flag == 2)//判定为回到诊室
		{	
			
			Motor_Stop(); //停车         
			
			f = 1;//f置1，跳出函数循环
			Flag = 0;
		}
		
	}	

}
void GetRoom2(void)//去房间2
{
	Pathfinding_GetNum();
	uint8_t L,R;
	int8_t Speed=43;
//	float Angle=10;
	uint8_t Flag = 0,f=0,Key;
	L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
	R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右	
	Delay_ms(1500);
	while(f == 0)
	{
		
			
//		Motor_Forward(Speed);
		
		Pathfind_Ctrl();
		L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
		R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右	
		if(L == 1 && Flag == 0)//到达药房 
		{
			Motor_Stop();
			Key = Key_GetNum();
			
			while(Key != 5)//直到按下房间2按钮
			{
				Key = Key_GetNum();
			}
			Delay_ms(1500);
			Flag=1;
			Key=0;
		}
		
		//Pathfind_Ctrl();
		L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
		R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右	
		
		if(R == 1 && Flag == 1)//判定到达房间1
		{	
			Flag+=1;
			Key=0;
			Motor_Forward(Speed);
			Delay_ms(300);
		}
		L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
		R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右	
		if(R == 1 && Flag == 2)//判定到达房间2
		{	
			Motor_Stop();//停车
			voice_ctrl();//播报
			//Delay_s(2);//等
			
			
			Key = Key_GetNum();
			while(Key != 5)//直到按下房间2按钮
			{
				Key = Key_GetNum();
				
			}
			Delay_ms(1500);
			Flag=3;
			
		}
		//\Pathfind_Ctrl();
		L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
		R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右	
		//Key = Key_GetNum();
	
		if(L==1 && R==1 && Flag == 3)//判定为回到诊室
		{	
			
			Motor_Stop(); //停车         
			
			f = 1;//f置1，跳出函数循环
			Flag = 0;
		}
		
	}	

}
void GetRoom3(void)//去房间3
{
	Pathfinding_GetNum();
	uint8_t L,R;
	int8_t Speed=43;
	uint8_t Flag = 0,f=0,Key;
	L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
	R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右	
	Delay_ms(1500);
	while(f == 0)
	{
		Pathfind_Ctrl();
		L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
		R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右	
		if(L == 1 && Flag == 0)//到达药房 
		{
			Motor_Stop();
			Key = Key_GetNum();
			
			while(Key != 6)//直到按下房间3按钮
			{
				Key = Key_GetNum();
			}
			Delay_ms(1500);
			Flag=1;
			Key=0;
		}
		
		//Pathfind_Ctrl();
		L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
		R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右	
		
		if(R == 1 && Flag == 1)//判定到达房间1
		{	
			Flag+=1;
			Key=0;
			Motor_Forward(Speed);
			Delay_ms(300);
		}
		L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
		R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右	
		
		if(R == 1 && Flag == 2)//判定到达房间2
		{	
			Flag+=1;
			Key=0;
			Motor_Forward(Speed);
			Delay_ms(300);
		}
		L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
		R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右
		if(R == 1 && Flag == 3)//判定到达房间3
		{	
			Motor_Stop();//停车
			voice_ctrl();//播报
			//Delay_s(2);//等
			
			
			Key = Key_GetNum();
			while(Key != 6)//直到按下房间3按钮
			{
				Key = Key_GetNum();
				
			}
			Delay_ms(1500);
			Flag=4;
			
		}
		//\Pathfind_Ctrl();
		L=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);//PB15  1左
		R=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);//PB12  4右	
		//Key = Key_GetNum();
	
		if(L==1 && R==1 && Flag == 4)//判定为回到诊室
		{	
			
			Motor_Stop(); //停车         
			
			f = 1;//f置1，跳出函数循环
			Flag = 0;
		}
		
	}	

}
//void Pathfind_Debug()//  1右 2左 3中
//{
//	int8_t Speed=65;
//	float Angle=9;
//	
//	OLED_ShowString(2,1,"       ");	
//	OLED_ShowString(2,1,"Forward");;
//	while(Pathfinding1_GetNum()==0 & Pathfinding3_GetNum()==0 & Pathfinding2_GetNum()==0)
//	{
//		OLED_ShowString(2,1,"       ");
//		OLED_ShowString(2,1,"Stop");
//	}
//	if(Pathfinding1_GetNum()==1 & Pathfinding3_GetNum()==0 & Pathfinding2_GetNum()==0)
//	{
//		OLED_ShowString(2,1,"       ");
//		OLED_ShowString(2,1,"Right");
//		while(Pathfinding1_GetNum()==0)
//		{
//			OLED_ShowString(2,1,"       ");
//			OLED_ShowString(2,1,"Forward");
//		}
//		
//	}
//	
//	else
//	{
//		if(Pathfinding1_GetNum()==0 & Pathfinding3_GetNum()==0 & Pathfinding2_GetNum()==1)
//		{
//			OLED_ShowString(2,1,"       ");
//			OLED_ShowString(2,1,"Left");
//			while(Pathfinding2_GetNum()==0)
//			{
//				OLED_ShowString(2,1,"       ");
//				OLED_ShowString(2,1,"Forward");
//			}
//		}
//		else
//		{
//			OLED_ShowString(2,1,"       ");
//			OLED_ShowString(2,1,"Forward");
//		
//		
//		}
//	
//	
//	}





//}
