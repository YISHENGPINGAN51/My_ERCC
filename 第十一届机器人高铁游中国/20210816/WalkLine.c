//更新了利用QTI巡线的方式，现在的4QTI方案解决了往年学长方案车子容易跑脱线的问题
//增加了4种转弯方式
//更新了前4QTI巡线前进和后4QTI巡线后退的方案
//确定了后2QTI巡线前进和前2QTI巡线后退的方案
//更新了所有和后4QTI有关的判断顺序
//增加并更新了前进巡线和后退巡线的模式选择方案

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

void LeftGo_LeftRun(void)
{
	P1_0=1;
	delay_us(LeftTurn_LeftPower);  //左轮
	P1_0=0;
	P1_1=1;
	delay_us(Stop_RightPower);  //右轮
	P1_1=0;
	delay_ms(20);
}

void LeftGo_RightRun(void)
{
	P1_0=1;
	delay_us(Stop_LeftPower);  //左轮
	P1_0=0;
	P1_1=1;
	delay_us(LeftTurn_RightPower);  //右轮
	P1_1=0;
	delay_ms(20);
}

void RightGo_LeftRun(void)
{
	P1_0=1;
  delay_us(RightTurn_LeftPower);  //左轮
  P1_0=0;
  P1_1=1;
  delay_us(Stop_RightPower);  //右轮
  P1_1=0;
  delay_ms(20);
}

void RightGo_RightRun(void)
{
	P1_0=1;
  delay_us(Stop_LeftPower);  //左轮
  P1_0=0;
  P1_1=1;
  delay_us(RightTurn_RightPower);  //右轮
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
		if (MiddleLeft_state() && MiddleRight_state())  //如果后面中间的两个QTI已经找到线了，就不用再左转了
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
		if (MiddleRight_state() && MiddleLeft_state())  //如果后面中间的两个QTI已经找到线了，就不用再右转了
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
	int FLM, FRM, FLL, FRR;
	FLM = Left2_state();  //前左中
	FRM = Right2_state();  //前右中
	FLL = Left1_state();  //前左最
	FRR = Right1_state();  //前右最
	
	//由于1号车电机参数前进时右轮比左轮快一点，前进时优先判断右转——左转——前进
	if (FRR && !FLM && !FLL)  //0 0 X 1
		RightGo_LeftRun();
	else if (FLL && !FRM && !FRR)  //1 X 0 0
		LeftGo_RightRun();
	else if (FLM || FRM)  //X 1 X X 或 X X 1 X （0 0 1 1 和 1 1 0 0不会进此情况）
		ForGo();
	else  //1 0 0 1 或 0 0 0 0
		Stop();
}

void Behind_QTI_ForWard(void)
{
  int BLM, BRM, BLL, BRR;
  BLM = MiddleRight_state();  //后左中
	BRM = MiddleLeft_state();  //后右中
//	BLL = BACKRight_state();  //后左最
//	BRR = BACKLeft_state();  //后右最
	
	//由于1号车电机参数前进时右轮比左轮快一点，前进时优先判断右转——左转——前进
	if (BLM && !BRM)
		RightGo_LeftRun();
	else if (BRM && !BLM)
		LeftGo_RightRun();
	else if (BLM && BRM)
		ForGo();
//	else
//		Stop();
}

void Front_QTI_BackWard(void)
{
	int FLM, FRM, FLL, FRR;
	FLM = Left2_state();  //前左中
	FRM = Right2_state();  //前右中
//	FLL = Left1_state();  //前左最
//	FRR = Right1_state();  //前右最

	//由于1号车电机参数后退时左轮比右轮快一点，后退时优先判断右转——左转——前进
	if (FRM && !FLM)
		RightGo_RightRun();
	else if (FLM && !FRM)
		LeftGo_LeftRun();
	else if (FLM && FRM)
		BackGo();
//	else
//		Stop();
}

void Behind_QTI_BackWard(void)
{
  int BLM, BRM, BLL, BRR;
  BLM = MiddleRight_state();  //后左中
	BRM = MiddleLeft_state();  //后右中
	BLL = BACKRight_state();  //后左最
	BRR = BACKLeft_state();  //后右最
	
	//由于1号车电机参数后退时左轮比右轮快一点，后退时优先判断右转——左转——前进
	if (!BRR && !BRM && BLL)  //1 X 0 0
		RightGo_RightRun();
	else if (!BLL && !BLM && BRR)  //0 0 X 1
		LeftGo_LeftRun();
	else if (BRM || BLM)  //X 1 X X 或 X X 1 X （1 1 0 0 和 0 0 1 1不会进此情况）
		BackGo();
	else  //1 0 0 1 或 0 0 0 0
		Stop();
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

void WalkLine_ForWard_Major(int mode)  //模式0为步进找点  模式1为巡线找点
{
	while(Left2_state() || Right2_state())
	{
		Front_QTI_ForWard();
	}
	if (mode)
	{
		//准备读卡的巡线找点
		Behind_QTI_TimeForWard(25);  //个人感觉15-25之间好像比较合适，可修改
	}
	else
	{
		//准备读卡的步进找点
		Step_ForGo(25);
	}
}

void WalkLine_BackWard_Major(int mode)  //模式0为步进找点  模式1为巡线找点
{
	while (MiddleRight_state() || MiddleLeft_state())
	{
		Behind_QTI_BackWard();
	}
	if (mode)
	{
		//准备读卡的巡线找点
		Front_QTI_TimeBackWard(25);  //个人感觉15-25之间好像比较合适，可修改
	}
	else
	{
		//准备读卡的步进找点
		Step_BackGo(25);
	}
}

void WalkLine_ForWard_Minor(int mode)  //模式0为步进找点  模式1为巡线找点
{
	Front_QTI_TimeForWard(60);  //个人感觉50-60之间好像比较合适，可修改
	while (MiddleRight_state() || MiddleLeft_state())
	{
		Behind_QTI_ForWard();
		if (!Left2_state() && !Right2_state())
		{
			Stop();
			delay_ms(500);
			if (mode)
			{
				//准备读卡的巡线找点
				Behind_QTI_TimeForWard(25);  //个人感觉15-25之间好像比较合适，可修改
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

void WalkLine_BackWard_Minor(int mode)  //模式0为步进找点  模式1为巡线找点
{
	Behind_QTI_TimeBackWard(60);    //循环次数个人感觉50-60之间好像比较合适，可修改
	while (Left2_state() || Right2_state())
	{
		Front_QTI_BackWard();
		if (!MiddleLeft_state() && !MiddleRight_state())
		{
			Stop();
			delay_ms(500);
			if (mode)
			{
				//准备读卡的巡线找点
				Front_QTI_TimeBackWard(25);  //个人感觉15-25之间好像比较合适，可修改
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