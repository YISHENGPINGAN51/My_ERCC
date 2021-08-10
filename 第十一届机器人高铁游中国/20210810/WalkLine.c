#include "WalkLine.h"

void Front_LeftTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (Left2_state() && Right2_state())  //已经找到线了
		{
			stop();
			break;
		}
		P1_0 = 1;
		delay_us(LeftTurn_LeftPower);  //左轮
		P1_0 = 0;
		P1_1 = 1;
		delay_us(LeftTurn_RightPower);  //右轮
		P1_1 = 0;
		delay_ms(20);
	}	
}

void Front_RightTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (Right2_state() && Left2_state())  //已经找到线了
		{
			stop();
			break;
		}
		P1_0 = 1;
		delay_us(RightTurn_LeftPower);  //左轮
		P1_0 = 0;
		P1_1 = 1;
		delay_us(RightTurn_RightPower);  //右轮
		P1_1 = 0;
		delay_ms(20);
	}	
}

void Behind_LeftTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (MiddleRight_state() && MiddleLeft_state())  //已经找到线了
		{
			stop();
			break;
		}
		P1_0 = 1;
		delay_us(LeftTurn_LeftPower);  //左轮
		P1_0 = 0;
		P1_1 = 1;
		delay_us(LeftTurn_RightPower);  //右轮
		P1_1 = 0;
		delay_ms(20);
	}		
}

void Behind_RightTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (MiddleLeft_state() && MiddleRight_state())  //已经找到线了
		{
			stop();
			break;
		}
		P1_0 = 1;
		delay_us(RightTurn_LeftPower);  //左轮
		P1_0 = 0;
		P1_1 = 1;
		delay_us(RightTurn_RightPower);  //右轮
		P1_1 = 0;
		delay_ms(20);
	}
}

void Step_ForWard(int step)     //步进冲距前进
{
	int i;
	for (i = 0; i < step; i++)
	{
		P1_0 = 1;
		delay_us(ForWard_LeftPower);  //左轮
    P1_0 = 0;
		P1_1 = 1;
		delay_us(ForWard_RightPower);  //右轮
		P1_1 = 0;
		delay_ms(20);
	}
}

void Step_BackWard(int step)     //步进冲距前进
{
	int i;
	for (i = 0; i < step; i++)
	{
		P1_0 = 1;
		delay_us(BackWard_LeftPower);  //左轮
    P1_0 = 0;
		P1_1 = 1;
		delay_us(BackWard_RightPower);  //右轮
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

void WalkLine_ForWard(int flag)  //模式0为步进找点  模式1为巡线找点
{
  int i;   //改i可以控制步进距离
	for (i = 0; i < 55; i++)    //循环次数个人感觉50-60之间好像比较合适，可修改
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
				//准备读卡的巡线找点
				for (i = 0; i < 25; i++)    //循环次数个人感觉15-25之间好像比较合适，可修改
				{
					Behind_QTI_ForWard();
				}
				break;
			}
			else
			{
				//准备读卡的步进找点
				Step_ForWard(25);
				break;
			}
		}
	}
}	

void WalkLine_BackWard(int flag)  //模式0为步进找点  模式1为巡线找点
{
  int i;   //改i可以控制步进距离
	for (i = 0; i < 55; i++)    //循环次数个人感觉50-60之间好像比较合适，可修改
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
				//准备读卡的巡线找点
				for (i = 0; i < 25; i++)    //循环次数个人感觉15-25之间好像比较合适，可修改
				{
					Front_QTI_BackWard();
				}
				break;
			}
			else
			{
				//准备读卡的步进找点
				Step_BackWard(25);
				break;
			}
		}
	}
}