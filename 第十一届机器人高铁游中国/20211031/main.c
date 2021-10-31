//·��
#include "Route.h"

//������
#include "WalkLine.h"
#include "led.h"
#include "hzcode.h"

//ѧ���ɷ���
#include "function.h"
#include "move.h"
#include <easy_run.h>
#include "read_RFID.h"

//�����⼸��ͷ�ļ��о�ûɶ��
#include "sys.h"
#include "stdio.h"
#include  "string.h"

int main()
{	
	delay_init();
	QTI_INIT();
	LED_GPIO_Init();
	motor_Init();
//	OLED_Init();			//��ʼ��OLED  
//	OLED_Clear();  
	voice_Init();
	KEY_Init();
	//MY_USART1_INIT();

//while(1)
//{	 

	//F1
		int flag;  //��Ҫ����Ϊ��  ���÷���Ϊ��
		flag = 1;  //������ѡ����
		if (flag)
		{
			Route1();
		}
		else
		{
			//���Ͼ����ϲ�
			Behind_RightTurn();
			delay_ms(100);
			Backjudge();
			delay_ms(100);
			Voice_Broadcast();
			delay_ms(100);
			//���ϲ����Ͼ�
			WalkLine_ForWard_Major(0);
			delay_ms(100);
			//���Ͼ������Ƹ�
			Step_RightGo(10);
			delay_ms(100);
			Front_LeftTurn();
			delay_ms(100);
			Forjudge();
			delay_ms(100);
			Voice_Broadcast();
			delay_ms(100);
			//�����Ƹ۵��ൺ 
			Front_RightTurn();
			delay_ms(100);
			WalkLine_ForWard_Major(0);
			delay_ms(100);
			Voice_Broadcast();
			delay_ms(100);
			//���ൺ�����Ƹ�
			Step_RightGo(10);
			delay_ms(100);
			Step_ForGo(5);
			delay_ms(100);
			Behind_LeftTurn();
			delay_ms(100);
			Backjudge();
			delay_ms(100);
			//�����Ƹ۵��Ͼ�
			Behind_LeftTurn();
			delay_ms(100);
			Backjudge();
			delay_ms(100);
			//���Ͼ�������
			Step_LeftGo(10);
			delay_ms(100);
			Behind_LeftTurn();
			delay_ms(100);
			Backjudge();
			delay_ms(100);
			Voice_Broadcast();
			delay_ms(100);
			//�Ӻ��ݵ��ϲ�
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
		
		//Four_Qti_Run1();                // ǰ��Ѱ��
	// Four_Qti_Run2();                // ����Ѳ��
		
  //Forgo();                        // ����ǰ��
  // Backgo();                       // ��������
		
	//	step1();delay_ms(3000);         // ���˰׵��ǰ��
	//step2();delay_ms(3000);         // ��QTI���׵�ĺ���
  //  step3();delay_ms(3000);         // �׵�ת��ĺ���
		
    //Rightgo1();                     // ǰ��Ѳ�ߵ���ת
  //  Leftgo1();                      // ǰ��Ѳ�ߵ���ת
		
  //  Rightgo1();delay_ms(3000);      // ����Ѳ�ߵ���ת
  //  Leftgo2();delay_ms(3000);       // ����Ѳ�ߵ���ת
		
  //  leftturn1();delay_ms(3000);     // �׵����ת
	//  Rightturn1();delay_ms(3000);    // �׵����ת
	
  //  leftturn2();delay_ms(3000);     // ��ת45��
	//  Rightturn2();delay_ms(3000);    // ��ת45��
	
  //  leftturn3();delay_ms(3000);     // ��ת15��
	 // Rightturn3();delay_ms(3000);    // ��ת15��		
//}

	
