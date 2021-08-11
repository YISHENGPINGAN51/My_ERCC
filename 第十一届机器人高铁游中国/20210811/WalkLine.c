#include "WalkLine.h"

void ForGo(void)
{
	P1_0=1;
	delay_us(ForWard_LeftPower);  //����
	P1_0=0;	
	P1_1=1;
	delay_us(ForWard_RightPower);  //����
	P1_1=0;
	delay_ms(20);
}

void BackGo(void)
{
	P1_0=1;
	delay_us(BackWard_LeftPower);  //����
	P1_0=0;	
	P1_1=1;
	delay_us(BackWard_RightPower);  //����
	P1_1=0;
	delay_ms(20);
}

void RightGo(void)
{
	P1_0=1;
	delay_us(RightTurn_LeftPower);  //����
	P1_0=0;	
	P1_1=1;
	delay_us(RightTurn_RightPower);  //����
	P1_1=0;
	delay_ms(20);
}

void LeftGo(void)
{
	P1_0=1;
	delay_us(LeftTurn_LeftPower);  //����
	P1_0=0;	
	P1_1=1;
	delay_us(LeftTurn_RightPower);  //����
	P1_1=0;
	delay_ms(20);
}

void Stop(void)
{
	P1_0=1;
	delay_us(Stop_LeftPower);  //����
	P1_0=0;	
	P1_1=1;
	delay_us(Stop_RightPower);  //����
	P1_1=0;
	delay_ms(20);
}

void Front_LeftTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (Left2_state() && Right2_state())  //���ǰ���м������QTI�Ѿ��ҵ����ˣ��Ͳ�������ת��
		{
			Stop();
			break;
		}
		LeftGo();  //��ʼ��ת
	}	
}

void Front_RightTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (Right2_state() && Left2_state())  //���ǰ���м������QTI�Ѿ��ҵ����ˣ��Ͳ�������ת��
		{
			Stop();
			break;
		}
		RightGo();  //��ʼ��ת
	}	
}

void Behind_LeftTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (MiddleRight_state() && MiddleLeft_state())  //��������м������QTI�Ѿ��ҵ����ˣ��Ͳ�������ת��
		{
			Stop();
			break;
		}
		LeftGo();  //��ʼ��ת
	}		
}

void Behind_RightTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (MiddleLeft_state() && MiddleRight_state())  //��������м������QTI�Ѿ��ҵ����ˣ��Ͳ�������ת��
		{
			Stop();
			break;
		}
		RightGo();  //��ʼ��ת
	}
}

void Step_ForGo(int step)
{
	int i;
	for (i = 0; i < step; i++)
	{
		ForGo();
	}
}

void Step_BackGo(int step)
{
	int i;
	for (i = 0; i < step; i++)
	{
		BackGo();
	}
}

void Step_RightGo(int step)
{
	int i;
	for (i = 0; i < step; i++)
	{
		RightGo();
	}
}

void Step_LeftGo(int step)
{
	int i;
	for (i = 0; i < step; i++)
	{
		LeftGo();
	}
}

void Front_QTI_ForWard(void)
{
	int a,b,c;
	a = Left2_state();
	b = Right2_state();
	if ( (a==1) && (b==1) )
	{c = 1;}
  if ( (a==0) && (b==1) )
	{c = 2;}
  if ( (a==1) && (b==0) )
	{c = 3;}
	
	switch (c)
	{
		case 1 : ForGo();
		         break;             
	
	  case 2 : RightGo();
		         break;               
	
	  case 3 : LeftGo();
		         break;             
	
//    default : Stop();
//							break;
	} 
}

void Behind_QTI_ForWard(void)
{
  int a,b,c;
  a = MiddleLeft_state();
	b = MiddleRight_state();
	if ( (a==1) && (b==1) )
	{c = 1;}
  if ( (a==0) && (b==1) )
	{c = 2;}
  if ( (a==1) && (b==0) )
	{c = 3;}
	
	switch (c)
  {
		case 1 : ForGo();
		         break;             
	
	  case 2 : RightGo();
		         break;               
	
	  case 3 : LeftGo();
		         break;              
	
   
//    default : Stop();
//						  break;			
	} 
}

void Front_QTI_BackWard(void)
{
  int a,b,c;
  a = Left2_state();
	b = Right2_state();
	if ( (a==1) && (b==1) )
	{c = 1;}
  if ( (a==0) && (b==1) )
	{c = 2;}
  if ( (a==1) && (b==0) )
	{c = 3;}
	
	switch (c)
	{
		case 1 : BackGo();
		            break;              
	
	  case 2 : RightGo();
		            break;                 
	
	  case 3 : LeftGo();
		            break;             
	
   
//    default : Stop();
//							break;			
	} 
}

void Behind_QTI_BackWard(void)
{
	int a,b,c;
  a = MiddleLeft_state();
	b = MiddleRight_state();
	if ( (a==1) && (b==1) )
	{c = 1;}
  if ( (a==0) && (b==1) )
	{c = 2;}
  if ( (a==1) && (b==0) )
	{c = 3;}
	
	switch (c)
  {
		case 1 : BackGo();
		         break;              
	
	  case 2 : RightGo();
		         break;               
	
	  case 3 : LeftGo();
		         break;               
	
   
//    default : Stop();
//							break;			
	} 
}

void Front_QTI_TimeForWard(int time)
{
	int i;  //��i���Կ��Ʋ�������
	for (i = 0; i < time; i++)  //ѭ���������˸о�50�ȽϺ��ʣ����޸�
	{
		Front_QTI_ForWard();
	}
}

void Behind_QTI_TimeForWard(int time)
{
	int i;  //��i���Կ��Ʋ�������
	for (i = 0; i < time; i++)  //ѭ���������˸о�50�ȽϺ��ʣ����޸�
	{
		Behind_QTI_ForWard();
	}
}

void Front_QTI_TimeBackWard(int time)
{
	int i;  //��i���Կ��Ʋ�������
	for (i = 0; i < time; i++)  //ѭ���������˸о�50�ȽϺ��ʣ����޸�
	{
		Front_QTI_BackWard();
	}
}

void Behind_QTI_TimeBackWard(int time)
{
	int i;  //��i���Կ��Ʋ�������
	for (i = 0; i < time; i++)  //ѭ���������˸о�50�ȽϺ��ʣ����޸�
	{
		Behind_QTI_BackWard();
	}
}

void WalkLine_ForWard(int flag)  //ģʽ0Ϊ�����ҵ�  ģʽ1ΪѲ���ҵ�
{
  int i;   //��i���Կ��Ʋ�������
	for (i = 0; i < 60; i++)    //ѭ���������˸о�50-60֮�����ȽϺ��ʣ����޸�
  {
    Front_QTI_ForWard();
	}
	while ( (MiddleLeft_state()==1) || (MiddleRight_state()==1) )
	{
		Behind_QTI_ForWard();
		if ( (Left2_state()==0) && (Right2_state()==0) )
		{
			Stop();
			delay_ms(500);
			if (flag)
			{
				//׼��������Ѳ���ҵ�
				for (i = 0; i < 25; i++)    //ѭ���������˸о�15-25֮�����ȽϺ��ʣ����޸�
				{
					Behind_QTI_ForWard();
				}
				break;
			}
			else
			{
				//׼�������Ĳ����ҵ�
				Step_ForGo(25);
				break;
			}
		}
	}
}

void WalkLine_BackWard(int flag)  //ģʽ0Ϊ�����ҵ�  ģʽ1ΪѲ���ҵ�
{
  int i;   //��i���Կ��Ʋ�������
	for (i = 0; i < 60; i++)    //ѭ���������˸о�50-60֮�����ȽϺ��ʣ����޸�
  {
    Behind_QTI_BackWard();
	}
	while ( (Left2_state()==1) || (Right2_state()==1) )
	{
		Front_QTI_BackWard();
		if ( (MiddleLeft_state()==0) && (MiddleRight_state()==0) )
		{
			Stop();
			delay_ms(500);
			if (flag)
			{
				//׼��������Ѳ���ҵ�
				for (i = 0; i < 25; i++)    //ѭ���������˸о�15-25֮�����ȽϺ��ʣ����޸�
				{
					Front_QTI_BackWard();
				}
				break;
			}
			else
			{
				//׼�������Ĳ����ҵ�
				Step_BackGo(25);
				break;
			}
		}
	}
}