//路线
#include "Route.h"

//主功能
#include "WalkLine.h"
#include "led.h"
#include "hzcode.h"

//学长旧方案
#include "function.h"
#include "move.h"
#include <easy_run.h>
#include "read_RFID.h"

//下面这几个头文件感觉没啥用
#include "sys.h"
#include "stdio.h"
#include  "string.h"

int main()
{	
	delay_init();
	QTI_INIT();
	LED_GPIO_Init();
	motor_Init();
//	OLED_Init();			//初始化OLED  
//	OLED_Clear();  
	voice_Init();
	KEY_Init();
	//MY_USART1_INIT();

//while(1)
//{	 

	//F1
		int flag;  //主要方案为真  备用方案为假
		flag = 1;  //改这里选方案
		if (flag)
		{
			Route1();
		}
		else
		{
			//从南京到南昌
			Behind_RightTurn();
			delay_ms(100);
			Backjudge();
			delay_ms(100);
			Voice_Broadcast();
			delay_ms(100);
			//从南昌到南京
			WalkLine_ForWard_Major(0);
			delay_ms(100);
			//从南京到连云港
			Step_RightGo(10);
			delay_ms(100);
			Front_LeftTurn();
			delay_ms(100);
			Forjudge();
			delay_ms(100);
			Voice_Broadcast();
			delay_ms(100);
			//从连云港到青岛 
			Front_RightTurn();
			delay_ms(100);
			WalkLine_ForWard_Major(0);
			delay_ms(100);
			Voice_Broadcast();
			delay_ms(100);
			//从青岛到连云港
			Step_RightGo(10);
			delay_ms(100);
			Step_ForGo(5);
			delay_ms(100);
			Behind_LeftTurn();
			delay_ms(100);
			Backjudge();
			delay_ms(100);
			//从连云港到南京
			Behind_LeftTurn();
			delay_ms(100);
			Backjudge();
			delay_ms(100);
			//从南京到杭州
			Step_LeftGo(10);
			delay_ms(100);
			Behind_LeftTurn();
			delay_ms(100);
			Backjudge();
			delay_ms(100);
			Voice_Broadcast();
			delay_ms(100);
			//从杭州到南昌
			Behind_RightTurn();
			delay_ms(100);
			Backjudge();
			delay_ms(100);
		}

	
	

//	while(1)
//	{
//    unsigned int sec = 0;
//		unsigned int flag = 4 ;
//		
//		switch(flag)
//		{
//			case 1:
//				if (Left1_state() == 0)
//					for(sec = 0; sec < 50; sec++)
//					{
//						Forgo();
//					}
//				break;
//			
//			case 2:
//				if (Left2_state() == 0)
//					for(sec = 0; sec < 50; sec++)
//					{
//						Forgo();
//					}
//				break;
//				
//			case 3:
//				if (Right2_state() == 0)
//					for(sec = 0; sec < 50; sec++)
//					{
//						Forgo();
//					}
//				break;
//					
//			case 4:
//				if (Right1_state() == 0)
//					for(sec = 0; sec < 50; sec++)
//					{
//						Forgo();
//					}
//				break;
//					
//			case 5:
//				if (BACKLeft_state() == 0)
//					for(sec = 0; sec < 50; sec++)
//					{
//						Forgo();
//					}	
//				break;
//					
//			case 6:
//				if (MiddleLeft_state() == 0)
//					for(sec = 0; sec < 50; sec++)
//					{
//						Forgo();
//					}
//				break;
//					
//			case 7:
//				if (MiddleRight_state() == 0)
//					for(sec = 0; sec < 50; sec++)
//					{
//						Forgo();
//					}
//				break;
//					
//			case 8:
//				if (BACKRight_state() == 0)
//					for(sec = 0; sec < 50; sec++)
//					{
//						Forgo();
//					}
//				break;
//					
//			default:
//				break;
//		}
//	}

	while(1);
}	


	//FOSHANtoTIANJIN();
	

	
//    TIANJINtoJINAN();
//   JINANtoFOSHAN();





//	 

//Rightjudge();

//if(Left1_state()==1)
//{     Forgo();         }	

		
		
		
		
//	Forjudge(); 
//Backjudge();
		
		//Four_Qti_Run1();                // 前进寻线
	// Four_Qti_Run2();                // 倒退巡线
		
  //Forgo();                        // 正常前进
  // Backgo();                       // 正常倒退
		
	//	step1();delay_ms(3000);         // 到了白点的前进
	//step2();delay_ms(3000);         // 后方QTI到白点的后退
  //  step3();delay_ms(3000);         // 白点转弯的后退
		
    //Rightgo1();                     // 前进巡线的右转
  //  Leftgo1();                      // 前进巡线的左转
		
  //  Rightgo1();delay_ms(3000);      // 倒车巡线的右转
  //  Leftgo2();delay_ms(3000);       // 倒车巡线的左转
		
  //  leftturn1();delay_ms(3000);     // 白点的左转
	//  Rightturn1();delay_ms(3000);    // 白点的右转
	
  //  leftturn2();delay_ms(3000);     // 左转45度
	//  Rightturn2();delay_ms(3000);    // 右转45度
	
  //  leftturn3();delay_ms(3000);     // 左转15度
	 // Rightturn3();delay_ms(3000);    // 右转15度		
//}

	
