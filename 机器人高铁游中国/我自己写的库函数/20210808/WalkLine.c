#include "WalkLine.h"

void FrontLeftTurn(void)
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

void FrontRightTurn(void)
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

void BehindLeftTurn(void)
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

void BehindRightTurn(void)
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

void Step(int step)     //步进冲距
{
	int i;
	for (i = 0; i < step; i++)
	{
		P1_0 = 1;
		delay_us(1575);  //左轮
    P1_0 = 0;
		P1_1 = 1;
		delay_us(1420);  //右轮
		P1_1 = 0;
		delay_ms(20);
	}
}

void Front_QTI_ForWard(void)
{
  int a,b,d,e,c;
  a = Left2_state();
	d = Left1_state();
	b = Right2_state();
	e = Right1_state();
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

void WalkLineForWard(void)
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
			delay_ms(1000);
			for (i = 0; i < 25; i++)    //循环次数个人感觉15-25之间好像比较合适，可修改
	    {
		    Behind_QTI_ForWard();
	    }
			break;
		}
	}
}	

void WalkLineBackWard(void)
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
			delay_ms(1000);
			//准备读卡的步进距离
			for (i = 0; i < 25; i++)    //循环次数个人感觉15-25之间好像比较合适，可修改
	    {
		    Front_QTI_BackWard();
	    }
			break;
		}
	}
}