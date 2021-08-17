#include "Broadcast.h"

unsigned int city[CITY_MAX] =
{
	9286            /*����*/
, 55374           /*��ɳ*/
, 32670           /*�人*/
, 32608           /*֣��*/
, 27835           /*����*/
, 54945           /*̫ԭ*/
, 22346           /*ʯ��ׯ*/
, 11636           /*����*/
, 21609           /*���*/
, 25581           /*����*/
, 27514           /*����*/
, 50882           /*����*/
, 49668           /*�ൺ*/
, 43990           /*����*/
, 47128           /*����*/
, 17289           /*�Ϸ�*/
, 24295           /*�Ͼ�*/
, 8609            /*����*/
, 63052           /*�ϲ�*/
, 22333           /*����*/
};

unsigned int VoiceJudge[CITY_MAX]=
{
	1/*����*/
, 1/*��ɳ*/
, 1/*�人*/
, 1/*֣��*/ 
, 1/*����*/
, 1/*̫ԭ*/
, 1/*ʯ��ׯ*/
, 1/*����*/
, 1/*���*/
, 1/*����*/
, 1/*����*/
, 1/*����*/
, 1/*�ൺ*/
, 1/*����*/
, 1/*����*/
, 1/*�Ϸ�*/
, 1/*�Ͼ�*/
, 1/*����*/
, 1/*�ϲ�*/
, 1/*����*/
};

unsigned int city_ready[CITY_MAX][DIGIT];
unsigned char warning;

void Transform(void)  //��������10������ת���ɶ�Ӧ��16���Ƶ�ASCIIֵ��һλһ�����ִ洢��������
{
	unsigned int i, j;
	unsigned int city_copy[CITY_MAX];
	memcpy(city_copy, city, sizeof(city));
	for (i = 0; i < CITY_MAX; i++)
	{
		for (j = 0; j < DIGIT; j++)
		{
			city_ready[i][DIGIT - 1 - j] = city_copy[i] % 16;
			city_copy[i] /= 16;
			if (city_ready[i][DIGIT - 1 - j] < 10)
			{
				city_ready[i][DIGIT - 1 - j] += 48;
			}
			else
			{
				city_ready[i][DIGIT - 1 - j] += 55;
			}
		}
	}
}

void Broadcast_Minor(void)  //�������������ǽ�ԭ����10���Ƶ���ת���ɶ�Ӧ��16���������бȽ��ж��Ƿ񲥱����Ż�ѧ���ϳ���˼·��
{
	delay_init();
  read();	
	unsigned int i, j, tmp;
	unsigned int Judge[DIGIT];
	for (i = 0; i < DIGIT; i++)
	{
		Judge[i] = command[DIGIT + i + 3];
	}
	if (!warning)
	{
		Transform();
		warning++;
	}
	for (i = 0; i < CITY_MAX; i++)
	{
		for (j = 0; j < DIGIT; j++)
		{
			if (Judge[j] != city_ready[i][j])
				break;
		}
		if (j == DIGIT)
		{
			if (VoiceJudge[i])
			{
				tmp = i;
				VoiceJudge[i] = 0;
			}
			else
			{
				tmp = 100;
			}
			Send_threelines(tmp);
			delay_ms(2000);
		}
	}
}

void Broadcast_Major(void)  //�������������ǽ���ȡ�����ַ�ת���ɶ�Ӧ��10���������бȽ��ж��Ƿ񲥱�����ѣ�
{
	delay_init();
  read();
	unsigned int i, j, tmp, sum;
	unsigned int Judge[DIGIT];
	for (i = 0; i < DIGIT; i++)
	{
		if (command[DIGIT + i + 3] < 58)
			Judge[i] = command[DIGIT + i + 3] - 48;
		else
			Judge[i] = command[DIGIT + i + 3] - 55;
	}
	for (i = 0; i < DIGIT; i++)
	{
		tmp = Judge[i];
		for (j = 0; j < DIGIT - i - 1; j++)
		{
			tmp *= 16;
		}
		sum += tmp;
	}
	while (sum != city[j++]);
	if (VoiceJudge[j - 1])
	{
		tmp = j - 1;
		VoiceJudge[j - 1] = 0;
	}
	else
	{
		tmp = 100;
	}
	Send_threelines(tmp);
	delay_ms(2000);
}

void Voice_Broadcast(void)
{
	int flag;  //��Ҫ����Ϊ��  ���÷���Ϊ��
	flag = 1;  //������ѡ����
	if (flag)
		Broadcast_Major();
	else
		Broadcast_Minor();
}