#include "WalkLine.h"

void ForGo(void)
{
	P1_0=1;
	delay_us(ForWard_LeftPower);  //左轮
	P1_0=0;	
	P1_1=1;
	delay_us(ForWard_RightPower);  //右轮
	P1_1=0;
	delay_ms(20);
}

void BackGo(void)
{
	P1_0=1;
	delay_us(BackWard_LeftPower);  //左轮
	P1_0=0;	
	P1_1=1;
	delay_us(BackWard_RightPower);  //右轮
	P1_1=0;
	delay_ms(20);
}

void RightGo(void)
{
	P1_0=1;
	delay_us(RightTurn_LeftPower);  //左轮
	P1_0=0;	
	P1_1=1;
	delay_us(RightTurn_RightPower);  //右轮
	P1_1=0;
	delay_ms(20);
}

void LeftGo(void)
{
	P1_0=1;
	delay_us(LeftTurn_LeftPower);  //左轮
	P1_0=0;	
	P1_1=1;
	delay_us(LeftTurn_RightPower);  //右轮
	P1_1=0;
	delay_ms(20);
}

void Stop(void)
{
	P1_0=1;
	delay_us(Stop_LeftPower);  //左轮
	P1_0=0;	
	P1_1=1;
	delay_us(Stop_RightPower);  //右轮
	P1_1=0;
	delay_ms(20);
}

void Front_LeftTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (Left2_state() && Right2_state())  //如果前面中间的两个QTI已经找到线了，就不用再左转了
		{
			Stop();
			break;
		}
		LeftGo();  //开始左转
	}	
}

void Front_RightTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (Right2_state() && Left2_state())  //如果前面中间的两个QTI已经找到线了，就不用再右转了
		{
			Stop();
			break;
		}
		RightGo();  //开始右转
	}	
}

void Behind_LeftTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (MiddleRight_state() && MiddleLeft_state())  //如果后面中间的两个QTI已经找到线了，就不用再左转了
		{
			Stop();
			break;
		}
		LeftGo();  //开始左转
	}		
}

void Behind_RightTurn(void)
{
	int i;
	for (i = 0; i < 88; i++)
	{
		if (MiddleLeft_state() && MiddleRight_state())  //如果后面中间的两个QTI已经找到线了，就不用再右转了
		{
			Stop();
			break;
		}
		RightGo();  //开始右转
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
	int i;  //改i可以控制步进距离
	for (i = 0; i < time; i++)  //循环次数个人感觉50比较合适，可修改
	{
		Front_QTI_ForWard();
	}
}

void Behind_QTI_TimeForWard(int time)
{
	int i;  //改i可以控制步进距离
	for (i = 0; i < time; i++)  //循环次数个人感觉50比较合适，可修改
	{
		Behind_QTI_ForWard();
	}
}

void Front_QTI_TimeBackWard(int time)
{
	int i;  //改i可以控制步进距离
	for (i = 0; i < time; i++)  //循环次数个人感觉50比较合适，可修改
	{
		Front_QTI_BackWard();
	}
}

void Behind_QTI_TimeBackWard(int time)
{
	int i;  //改i可以控制步进距离
	for (i = 0; i < time; i++)  //循环次数个人感觉50比较合适，可修改
	{
		Behind_QTI_BackWard();
	}
}

void WalkLine_ForWard(int flag)  //模式0为步进找点  模式1为巡线找点
{
  int i;   //改i可以控制步进距离
	for (i = 0; i < 60; i++)    //循环次数个人感觉50-60之间好像比较合适，可修改
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
				Step_ForGo(25);
				break;
			}
		}
	}
}

void WalkLine_BackWard(int flag)  //模式0为步进找点  模式1为巡线找点
{
  int i;   //改i可以控制步进距离
	for (i = 0; i < 60; i++)    //循环次数个人感觉50-60之间好像比较合适，可修改
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
				Step_BackGo(25);
				break;
			}
		}
	}
}