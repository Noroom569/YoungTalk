/*********************************************************************************************
模板制作：  杜洋工作室/洋桃电子
程序名：	LED呼吸灯程序
编写人：	杜洋	
编写时间：	2017年12月25日
硬件支持：	STM32F103C8   外部晶振8MHz RCC函数设置主频72MHz　  

修改日志：　　
1-	
	
							
说明：
 # 本模板加载了STM32F103内部的RCC时钟设置，并加入了利用滴答定时器的延时函数。
 # 可根据自己的需要增加或删减。

*********************************************************************************************/
#include "stm32f10x.h" //STM32头文件
#include "sys.h"
#include "delay.h"
#include "led.h"


int main (void){//主程序
	//定义需要的变量
	u8 MENU;
	u16 t,i;
	//初始化程序
	RCC_Configuration(); //时钟设置
	LED_Init();
	//设置变量的初始值
	MENU = 0;
	t = 1;
	//主循环
	while(1){
		//菜单0
		if(MENU == 0){ //由暗到亮循环
			for(i = 0; i < 5; i++){
				GPIO_WriteBit(LEDPORT,LED1,(BitAction)(1)); //LED1接口输出高电平1
				delay_us(t); //延时
				GPIO_WriteBit(LEDPORT,LED1,(BitAction)(0)); //LED1接口输出低电平0
				delay_us(301-t); //延时
			}
			t++;
			if(t==300){
				MENU = 1;
			}
		}
		//菜单1
		if(MENU == 1){ //由亮变暗循环
			for(i = 0; i < 5; i++){
				GPIO_WriteBit(LEDPORT,LED1,(BitAction)(1)); //LED1接口输出高电平1
				delay_us(t); //延时
				GPIO_WriteBit(LEDPORT,LED1,(BitAction)(0)); //LED1接口输出低电平0
				delay_us(301-t); //延时
			}
			t--;
			if(t==1){
				MENU = 0;
			}
		}		
	}
}


/*********************************************************************************************
 * 杜洋工作室 www.DoYoung.net
 * 洋桃电子 www.DoYoung.net/YT 
*********************************************************************************************/
/*

【变量定义】
u32     a; //定义32位无符号变量a       最常用 定义无符号变量它们的值是存放在SRAM中的，可以在程序当中不断变化的
u16     a; //定义16位无符号变量a
u8     a; //定义8位无符号变量a
vu32     a; //定义易变的32位无符号变量a 易变主要用在 中断处理当中
vu16     a; //定义易变的 16位无符号变量a
vu8     a; //定义易变的 8位无符号变量a
uc32     a; //定义只读的32位无符号变量a  只能读不能写，内容存放在flash中，一般作为固定的参数
uc16     a; //定义只读 的16位无符号变量a
uc8     a; //定义只读 的8位无符号变量a

#define ONE  1   //宏定义

delay_us(1); //延时1微秒
delay_ms(1); //延时1毫秒
delay_s(1); //延时1秒

*/



