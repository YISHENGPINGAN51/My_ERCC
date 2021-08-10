#include "WalkLine.h"

void Front_LeftTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (Left2_state() && Right2_state())  //�Ѿ��ҵ�����
		{
			stop();
			break;
		}
		P1_0 = 1;
		delay_us(LeftTurn_LeftPower);  //����
		P1_0 = 0;
		P1_1 = 1;
		delay_us(LeftTurn_RightPower);  //����
		P1_1 = 0;
		delay_ms(20);
	}	
}

void Front_RightTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (Right2_state() && Left2_state())  //�Ѿ��ҵ�����
		{
			stop();
			break;
		}
		P1_0 = 1;
		delay_us(RightTurn_LeftPower);  //����
		P1_0 = 0;
		P1_1 = 1;
		delay_us(RightTurn_RightPower);  //����
		P1_1 = 0;
		delay_ms(20);
	}	
}

void Behind_LeftTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (MiddleRight_state() && MiddleLeft_state())  //�Ѿ��ҵ�����
		{
			stop();
			break;
		}
		P1_0 = 1;
		delay_us(LeftTurn_LeftPower);  //����
		P1_0 = 0;
		P1_1 = 1;
		delay_us(LeftTurn_RightPower);  //����
		P1_1 = 0;
		delay_ms(20);
	}		
}

void Behind_RightTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (MiddleLeft_state() && MiddleRight_state())  //�Ѿ��ҵ�����
		{
			stop();
			break;
		}
		P1_0 = 1;
		delay_us(RightTurn_LeftPower);  //����
		P1_0 = 0;
		P1_1 = 1;
		delay_us(RightTurn_RightPower);  //����
		P1_1 = 0;
		delay_ms(20);
	}
}

void Step_ForWard(int step)     //�������ǰ��
{
	int i;
	for (i = 0; i < step; i++)
	{
		P1_0 = 1;
		delay_us(ForWard_LeftPower);  //����
    P1_0 = 0;
		P1_1 = 1;
		delay_us(ForWard_RightPower);  //����
		P1_1 = 0;
		delay_ms(20);
	}
}

void Step_BackWard(int step)     //�������ǰ��
{
	int i;
	for (i = 0; i < step; i++)
	{
		P1_0 = 1;
		delay_us(BackWard_LeftPower);  //����
    P1_0 = 0;
		P1_1 = 1;
		delay_us(BackWard_RightPower);  //����
		P1_1 = 0;
		delay_ms(20);
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
		case 1 : Forgo();
		            break;             
	
	  case 2 : Rightgo1();
		            break;               
	
	  case 3 : Leftgo1();
		            break;             
	
//    default : stop();
//							 break;			
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
		case 1 : Backgo();
		            break;              
	
	  case 2 : Rightgo1();
		            break;               
	
	  case 3 : Leftgo1();
		            break;               
	
   
//     default :  stop();
//							 break;			
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
		case 1 : Forgo();
		            break;             
	
	  case 2 : Rightgo1();
		            break;               
	
	  case 3 : Leftgo1();
		            break;              
	
   
//     default :  stop();
//							 break;			
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
		case 1 : Backgo();
		            break;              
	
	  case 2 : Rightgo1();
		            break;                 
	
	  case 3 : Leftgo1();
		            break;             
	
   
//     default :  stop();
//							 break;			
	} 
}	

void WalkLine_ForWard(int flag)  //ģʽ0Ϊ�����ҵ�  ģʽ1ΪѲ���ҵ�
{
  int i;   //��i���Կ��Ʋ�������
	for (i = 0; i < 55; i++)    //ѭ���������˸о�50-60֮�����ȽϺ��ʣ����޸�
  {
    Front_QTI_ForWard();
	}
	while ( (MiddleLeft_state()==1) || (MiddleRight_state()==1) )
	{
		Behind_QTI_ForWard();
		if ( (Left2_state()==0) && (Right2_state()==0) )
		{
			stop();
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
				Step_ForWard(25);
				break;
			}
		}
	}
}	

void WalkLine_BackWard(int flag)  //ģʽ0Ϊ�����ҵ�  ģʽ1ΪѲ���ҵ�
{
  int i;   //��i���Կ��Ʋ�������
	for (i = 0; i < 55; i++)    //ѭ���������˸о�50-60֮�����ȽϺ��ʣ����޸�
  {
    Behind_QTI_BackWard();
	}
	while ( (Left2_state()==1) || (Right2_state()==1) )
	{
		Front_QTI_BackWard();
		if ( (MiddleLeft_state()==0) && (MiddleRight_state()==0) )
		{
			stop();
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
				Step_BackWard(25);
				break;
			}
		}
	}
}