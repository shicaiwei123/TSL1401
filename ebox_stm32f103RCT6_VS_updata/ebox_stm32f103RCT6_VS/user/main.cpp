/**
  ******************************************************************************
  * @file   : *.cpp
  * @author : shentq
  * @version: V1.2
  * @date   : 2016/08/14

  * @brief   ebox application example .
  *
  * Copyright 2016 shentq. All Rights Reserved.         
  ******************************************************************************
 */

#include "ebox.h"
#include "tsl1401.h"
int main()
{
	u16 *CCD_AD;
	TSL1401 T1(&PA3, &PB1, &PB2);
	T1.begin();
	while (true)
	{
		T1.capture(10);
		CCD_AD = T1.getData();
	}
	return 1;
}





/*
#include "ebox.h" 
TIM timer2(TIM2);//创建一个定时器中断对象，使用 TIM2。 
uint32_t count;
void t2_event()//定时器溢出中断事件 
{     count++;   
if(count == 1000)   
{         count = 0;      
PB8.toggle();     
uart1.printf("\r\ntimer2 is triggered 1000 times !");     
}
} 
void setup() 
{     ebox_init();
uart1.begin(115200); 
timer2.begin(1000);//初始化定时中断频率:1KHz    
timer2.attach_interrupt(t2_event);//绑定中断事件  
timer2.interrupt(ENABLE);//使能中断   
timer2.start();//启动定时器    
PB8.mode(OUTPUT_PP);
} 
*/