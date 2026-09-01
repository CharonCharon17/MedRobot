#include "stm32f10x.h"                  // Device header
#include "Key.h"
#include "OLED.h"
#include "Delay.h"

uint8_t KeyNum;//用于存储键码值

/**       
  * @brief  菜单函数
  * @param  无
  * @retval 返回当前选中是第几种药品 
  */
uint8_t f[10]={0};
char* f1[10]={"布洛芬胶囊           ",
			  "感冒灵               ",
			  "连花清瘟             ",
              "止咳糖浆             ",
              "头孢拉定              ",
              "六味地黄丸            ",
			  "阿司匹林              ",
			  "红霉素软膏            ",
			  "退热贴              ",
			  "碘伏                "};
void menuClear()//标记复位
{
	for (int i = 0; i < sizeof(f)/sizeof(f[0]); i++) f[i]=0;

}
int menu(void)
{
	uint8_t flag=1;
	uint8_t num=0;
	
	/*初始显示*/
	OLED_ShowString(0, 0,f1[0],OLED_8X16);
	OLED_ShowString(0,16,f1[1],OLED_8X16);
	OLED_ShowString(0,32,f1[2],OLED_8X16);
	OLED_ShowString(0,48,f1[3],OLED_8X16);
	for (int i = 0; i < 4; i++)
		{
			if (f[i] == 1) OLED_ShowString(110,i%4*16,"!",OLED_8X16);
		}
	OLED_Update();
		
	while(1)
	{
		KeyNum = Key_GetNum();
		if(KeyNum == 1)//上一项
		{
			flag--;
			if(flag == 0){flag = 10;}
		}
		if(KeyNum == 2)//下一项
		{
			flag++;
			if(flag == 11){flag = 1;}
		}
		if(KeyNum == 3)//确认；
		{
			num = (flag%4-1)*16;
			f[flag-1]=1;
			//OLED_Clear();
			//OLED_Update();
			return flag;
		}
		if(KeyNum == 4)break;
		if(KeyNum == 5)break;
		if(KeyNum == 6)break;//

		switch(flag)
		{
			case 1:
			{
				//再次显示,解决乱码和闪烁问题(确保反相前是亮的状态)
				OLED_ShowString(0, 0,"布洛芬胶囊           ",OLED_8X16);
				OLED_ShowString(0,16,"感冒灵               ",OLED_8X16);
				OLED_ShowString(0,32,"连花清瘟             ",OLED_8X16);
				OLED_ShowString(0,48,"止咳糖浆             ",OLED_8X16);
				for (int i = 0; i < 4; i++)
				{
					if(f[i]==1)OLED_ShowString(110,i%4*16,"!",OLED_8X16);
				}
				OLED_ReverseArea(0,0,128,16);
				OLED_Update();
				break;
			}
			case 2:
			{
				//再次显示,解决乱码和闪烁问题(确保反相前是亮的状态)
				OLED_ShowString(0, 0,"布洛芬胶囊           ",OLED_8X16);
				OLED_ShowString(0,16,"感冒灵               ",OLED_8X16);
				OLED_ShowString(0,32,"连花清瘟             ",OLED_8X16);
				OLED_ShowString(0,48,"止咳糖浆             ",OLED_8X16);				
				for (int i = 0; i < 4; i++)
				{
					if(f[i]==1)OLED_ShowString(110,i%4*16,"!",OLED_8X16);
				}
				OLED_ReverseArea(0,16,128,16);
				OLED_Update();
				break;
				
			}
			case 3:
			{
				//再次显示,解决乱码和闪烁问题(确保反相前是亮的状态)
				OLED_ShowString(0, 0,"布洛芬胶囊           ",OLED_8X16);
				OLED_ShowString(0,16,"感冒灵               ",OLED_8X16);
				OLED_ShowString(0,32,"连花清瘟             ",OLED_8X16);
				OLED_ShowString(0,48,"止咳糖浆             ",OLED_8X16);
				for (int i = 0; i < 4; i++)
				{
					if(f[i]==1)OLED_ShowString(110,i%4*16,"!",OLED_8X16);
				}
				OLED_ReverseArea(0,32,128,16);
				OLED_Update();
				break;
			}
			case 4:
			{
				//再次显示,解决乱码和闪烁问题(确保反相前是亮的状态)
				OLED_ShowString(0, 0,"布洛芬胶囊           ",OLED_8X16);
				OLED_ShowString(0,16,"感冒灵               ",OLED_8X16);
				OLED_ShowString(0,32,"连花清瘟             ",OLED_8X16);
				OLED_ShowString(0,48,"止咳糖浆             ",OLED_8X16);
				for (int i = 0; i < 4; i++)
				{
					if(f[i]==1)OLED_ShowString(110,i%4*16,"!",OLED_8X16);
				}
				OLED_ReverseArea(0,48,128,16);
				OLED_Update();
				break;
			}
			case 5:
			{
				//再次显示,解决乱码和闪烁问题(确保反相前是亮的状态)
				OLED_ShowString(0, 0,"头孢拉定              ",OLED_8X16);
				OLED_ShowString(0,16,"六味地黄丸            ",OLED_8X16);
				OLED_ShowString(0,32,"阿司匹林              ",OLED_8X16);
				OLED_ShowString(0,48,"红霉素软膏            ",OLED_8X16);
				for (int i = 4; i < 8; i++)
				{
					if(f[i]==1)OLED_ShowString(110,i%4*16,"!",OLED_8X16);
				}
				OLED_ReverseArea(0,0,128,16);
				OLED_Update();
				break;
			}
			case 6:
			{
				//再次显示,解决乱码和闪烁问题(确保反相前是亮的状态)
				OLED_ShowString(0, 0,"头孢拉定              ",OLED_8X16);
				OLED_ShowString(0,16,"六味地黄丸            ",OLED_8X16);
				OLED_ShowString(0,32,"阿司匹林              ",OLED_8X16);
				OLED_ShowString(0,48,"红霉素软膏            ",OLED_8X16);
				for (int i = 4; i < 8; i++)
				{
					if(f[i]==1)OLED_ShowString(110,i%4*16,"!",OLED_8X16);
				}
				OLED_ReverseArea(0,16,128,16);
				OLED_Update();
				break;
			}
			case 7:
			{
				//再次显示,解决乱码和闪烁问题(确保反相前是亮的状态)
				OLED_ShowString(0, 0,"头孢拉定              ",OLED_8X16);
				OLED_ShowString(0,16,"六味地黄丸            ",OLED_8X16);
				OLED_ShowString(0,32,"阿司匹林              ",OLED_8X16);
				OLED_ShowString(0,48,"红霉素软膏            ",OLED_8X16);
				for (int i = 4; i < 8; i++)
				{
					if(f[i]==1)OLED_ShowString(110,i%4*16,"!",OLED_8X16);
				}
				OLED_ReverseArea(0,32,128,16);
				OLED_Update();
				break;
			}
			case 8:
			{
				//再次显示,解决乱码和闪烁问题(确保反相前是亮的状态)
				OLED_ShowString(0, 0,"头孢拉定              ",OLED_8X16);
				OLED_ShowString(0,16,"六味地黄丸            ",OLED_8X16);
				OLED_ShowString(0,32,"阿司匹林              ",OLED_8X16);
				OLED_ShowString(0,48,"红霉素软膏            ",OLED_8X16);
				for (int i = 4; i < 8; i++)
				{
					if(f[i]==1)OLED_ShowString(110,i%4*16,"!",OLED_8X16);
				}
				OLED_ReverseArea(0,48,128,16);
				OLED_Update();
				break;
			}
			case 9:
			{
				OLED_Clear();
				//再次显示,解决乱码和闪烁问题(确保反相前是亮的状态)
				OLED_ShowString(0, 0,"退热贴              ",OLED_8X16);
				OLED_ShowString(0,16,"碘伏                ",OLED_8X16);
				for (int i = 8; i < 10; i++)
				{
					if(f[i]==1)OLED_ShowString(110,i%4*16,"!",OLED_8X16);
				}
				OLED_ReverseArea(0,0,128,16);
				OLED_Update();
				break;
			}
			case 10:
			{
				OLED_Clear();
				//再次显示,解决乱码和闪烁问题(确保反相前是亮的状态)
				OLED_ShowString(0, 0,"退热贴              ",OLED_8X16);
				OLED_ShowString(0,16,"碘伏                ",OLED_8X16);
				for (int i = 8; i < 10; i++)
				{
					if(f[i]==1)OLED_ShowString(110,i%4*16,"!",OLED_8X16);
				}
				OLED_ReverseArea(0,16,128,16);
				OLED_Update();
				break;
			}
		}
	}
}

void xuanze(void )
{ 
		int num=0;
		OLED_Clear ();
		for (int i = 0; i <10; i++)
		{
			if(f[i]==1)
			{
				OLED_ShowString(0,num,f1[i],OLED_8X16);
				num+=16;
			}
		}
		OLED_Update();
		
		//menuClear();

		//while(1);
}
void voice_init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//打开GPIOA时钟
	
	GPIO_InitTypeDef GPIO_InitStructure1;				//定义结构体变量
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_IPU;		//上拉输入
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_0;//配置 PA0
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;   
	GPIO_Init(GPIOA,&GPIO_InitStructure1);
}
void play(uint8_t num)	
{
	switch(num)//标记选中药品 
		{
			case 1:  
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_ResetBits(GPIOB,GPIO_Pin_11);
				Delay_ms(500);
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				break;
				break;
			case 2:  
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_ResetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				Delay_ms(500);
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				break;
			case 3:  
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_ResetBits(GPIOB,GPIO_Pin_10);
				GPIO_ResetBits(GPIOB,GPIO_Pin_11);
				Delay_ms(500);
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				break;
			case 4:  
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_ResetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				Delay_ms(500);
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				break;
			case 5:  
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_ResetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_ResetBits(GPIOB,GPIO_Pin_11);
				Delay_ms(500);
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				break;
			case 6:  
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_ResetBits(GPIOB,GPIO_Pin_1);
				GPIO_ResetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				Delay_ms(500);
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				break;
			case 7:  
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_ResetBits(GPIOB,GPIO_Pin_1);
				GPIO_ResetBits(GPIOB,GPIO_Pin_10);
				GPIO_ResetBits(GPIOB,GPIO_Pin_11);
				Delay_ms(500);
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				break;
			case 8:  
				GPIO_ResetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				Delay_ms(500);
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				break;
			case 9:  
				GPIO_ResetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_ResetBits(GPIOB,GPIO_Pin_11);
				Delay_ms(500);
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				break;
			case 10:  
				GPIO_ResetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_ResetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				Delay_ms(500);
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				break;
			case 11:  //避让
				GPIO_ResetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_ResetBits(GPIOB,GPIO_Pin_10);
				GPIO_ResetBits(GPIOB,GPIO_Pin_11);
				Delay_ms(50);
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				break;
			case 12:  //已送达
				GPIO_ResetBits(GPIOB,GPIO_Pin_0);
				GPIO_ResetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				Delay_ms(500);
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				break;
			case 13:  //药品
				GPIO_ResetBits(GPIOB,GPIO_Pin_0);
				GPIO_ResetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_ResetBits(GPIOB,GPIO_Pin_11);
				Delay_ms(500);
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				break;
			case 14:  //停
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_SetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_11);
				break;
		}
}
void voice_ctrl()
{
	int f2[10]={1,1,1,1,1,0,0,0,0,0};
	uint8_t num=0,j=0;
	play(13);
	while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 0);
	play(1);
	while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 0);
	if(f[0]==1)play(1);
	while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 0);//判断当前播放是否结束
	if(f[1]==1)play(2);
	while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 0);//判断当前播放是否结束
	if(f[2]==1)play(3);
	while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 0);//判断当前播放是否结束
	if(f[3]==1)play(4);
	while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 0);//判断当前播放是否结束
	if(f[4]==1)play(5);
	while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 0);//判断当前播放是否结束
	if(f[5]==1)play(6);
	while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 0);//判断当前播放是否结束
	if(f[6]==1)play(7);
	while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 0);//判断当前播放是否结束
	if(f[7]==1)play(8);
	while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 0);//判断当前播放是否结束
	if(f[8]==1)play(9);
	while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 0);//判断当前播放是否结束
	if(f[9]==1)play(10);
	while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 0);//判断当前播放是否结束
	
				
//	for (int i = 0; i <10; i++)
//		{
//			
//			if(f2[j]==1)
//				j+=1;
//			{
//			//num=j+1;
//			play(2);//播放num号药品
//			while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 0);//判断当前播放是否结束
//			
//			}
//	}
	play(12);
	
	menuClear();
}
