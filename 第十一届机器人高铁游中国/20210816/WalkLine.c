//����������QTIѲ�ߵķ�ʽ�����ڵ�4QTI�������������ѧ�������������������ߵ�����
//������4��ת�䷽ʽ
//������ǰ4QTIѲ��ǰ���ͺ�4QTIѲ�ߺ��˵ķ���
//ȷ���˺�2QTIѲ��ǰ����ǰ2QTIѲ�ߺ��˵ķ���
//���������кͺ�4QTI�йص��ж�˳��
//���Ӳ�������ǰ��Ѳ�ߺͺ���Ѳ�ߵ�ģʽѡ�񷽰�

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

void LeftGo_LeftRun(void)
{
	P1_0=1;
	delay_us(LeftTurn_LeftPower);  //����
	P1_0=0;
	P1_1=1;
	delay_us(Stop_RightPower);  //����
	P1_1=0;
	delay_ms(20);
}

void LeftGo_RightRun(void)
{
	P1_0=1;
	delay_us(Stop_LeftPower);  //����
	P1_0=0;
	P1_1=1;
	delay_us(LeftTurn_RightPower);  //����
	P1_1=0;
	delay_ms(20);
}

void RightGo_LeftRun(void)
{
	P1_0=1;
  delay_us(RightTurn_LeftPower);  //����
  P1_0=0;
  P1_1=1;
  delay_us(Stop_RightPower);  //����
  P1_1=0;
  delay_ms(20);
}

void RightGo_RightRun(void)
{
	P1_0=1;
  delay_us(Stop_LeftPower);  //����
  P1_0=0;
  P1_1=1;
  delay_us(RightTurn_RightPower);  //����
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
		if (MiddleLeft_state() && MiddleRight_state())  //��������м������QTI�Ѿ��ҵ����ˣ��Ͳ�������ת��
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
		if (MiddleRight_state() && MiddleLeft_state())  //��������м������QTI�Ѿ��ҵ����ˣ��Ͳ�������ת��
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
	int FLM, FRM, FLL, FRR;
	FLM = Left2_state();  //ǰ����
	FRM = Right2_state();  //ǰ����
	FLL = Left1_state();  //ǰ����
	FRR = Right1_state();  //ǰ����
	
	//����1�ų��������ǰ��ʱ���ֱ����ֿ�һ�㣬ǰ��ʱ�����ж���ת������ת����ǰ��
	if (FRR && !FLM && !FLL)  //0 0 X 1
		RightGo_LeftRun();
	else if (FLL && !FRM && !FRR)  //1 X 0 0
		LeftGo_RightRun();
	else if (FLM || FRM)  //X 1 X X �� X X 1 X ��0 0 1 1 �� 1 1 0 0������������
		ForGo();
	else  //1 0 0 1 �� 0 0 0 0
		Stop();
}

void Behind_QTI_ForWard(void)
{
  int BLM, BRM, BLL, BRR;
  BLM = MiddleRight_state();  //������
	BRM = MiddleLeft_state();  //������
//	BLL = BACKRight_state();  //������
//	BRR = BACKLeft_state();  //������
	
	//����1�ų��������ǰ��ʱ���ֱ����ֿ�һ�㣬ǰ��ʱ�����ж���ת������ת����ǰ��
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
	FLM = Left2_state();  //ǰ����
	FRM = Right2_state();  //ǰ����
//	FLL = Left1_state();  //ǰ����
//	FRR = Right1_state();  //ǰ����

	//����1�ų������������ʱ���ֱ����ֿ�һ�㣬����ʱ�����ж���ת������ת����ǰ��
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
  BLM = MiddleRight_state();  //������
	BRM = MiddleLeft_state();  //������
	BLL = BACKRight_state();  //������
	BRR = BACKLeft_state();  //������
	
	//����1�ų������������ʱ���ֱ����ֿ�һ�㣬����ʱ�����ж���ת������ת����ǰ��
	if (!BRR && !BRM && BLL)  //1 X 0 0
		RightGo_RightRun();
	else if (!BLL && !BLM && BRR)  //0 0 X 1
		LeftGo_LeftRun();
	else if (BRM || BLM)  //X 1 X X �� X X 1 X ��1 1 0 0 �� 0 0 1 1������������
		BackGo();
	else  //1 0 0 1 �� 0 0 0 0
		Stop();
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

void WalkLine_ForWard_Major(int mode)  //ģʽ0Ϊ�����ҵ�  ģʽ1ΪѲ���ҵ�
{
	while(Left2_state() || Right2_state())
	{
		Front_QTI_ForWard();
	}
	if (mode)
	{
		//׼��������Ѳ���ҵ�
		Behind_QTI_TimeForWard(25);  //���˸о�15-25֮�����ȽϺ��ʣ����޸�
	}
	else
	{
		//׼�������Ĳ����ҵ�
		Step_ForGo(25);
	}
}

void WalkLine_BackWard_Major(int mode)  //ģʽ0Ϊ�����ҵ�  ģʽ1ΪѲ���ҵ�
{
	while (MiddleRight_state() || MiddleLeft_state())
	{
		Behind_QTI_BackWard();
	}
	if (mode)
	{
		//׼��������Ѳ���ҵ�
		Front_QTI_TimeBackWard(25);  //���˸о�15-25֮�����ȽϺ��ʣ����޸�
	}
	else
	{
		//׼�������Ĳ����ҵ�
		Step_BackGo(25);
	}
}

void WalkLine_ForWard_Minor(int mode)  //ģʽ0Ϊ�����ҵ�  ģʽ1ΪѲ���ҵ�
{
	Front_QTI_TimeForWard(60);  //���˸о�50-60֮�����ȽϺ��ʣ����޸�
	while (MiddleRight_state() || MiddleLeft_state())
	{
		Behind_QTI_ForWard();
		if (!Left2_state() && !Right2_state())
		{
			Stop();
			delay_ms(500);
			if (mode)
			{
				//׼��������Ѳ���ҵ�
				Behind_QTI_TimeForWard(25);  //���˸о�15-25֮�����ȽϺ��ʣ����޸�
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

void WalkLine_BackWard_Minor(int mode)  //ģʽ0Ϊ�����ҵ�  ģʽ1ΪѲ���ҵ�
{
	Behind_QTI_TimeBackWard(60);    //ѭ���������˸о�50-60֮�����ȽϺ��ʣ����޸�
	while (Left2_state() || Right2_state())
	{
		Front_QTI_BackWard();
		if (!MiddleLeft_state() && !MiddleRight_state())
		{
			Stop();
			delay_ms(500);
			if (mode)
			{
				//׼��������Ѳ���ҵ�
				Front_QTI_TimeBackWard(25);  //���˸о�15-25֮�����ȽϺ��ʣ����޸�
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