#include "Broadcast.h"

unsigned int city[CITY_MAX] =
{
	9286            /*广州*/
, 55374           /*长沙*/
, 32670           /*武汉*/
, 32608           /*郑州*/
, 27835           /*西安*/
, 54945           /*太原*/
, 22346           /*石家庄*/
, 11636           /*北京*/
, 21609           /*天津*/
, 25581           /*沈阳*/
, 27514           /*大连*/
, 50882           /*济南*/
, 49668           /*青岛*/
, 43990           /*徐州*/
, 47128           /*蚌埠*/
, 17289           /*合肥*/
, 24295           /*南京*/
, 8609            /*杭州*/
, 63052           /*南昌*/
, 22333           /*深圳*/
};

unsigned int VoiceJudge[CITY_MAX]=
{
	1/*广州*/
, 1/*长沙*/
, 1/*武汉*/
, 1/*郑州*/ 
, 1/*西安*/
, 1/*太原*/
, 1/*石家庄*/
, 1/*北京*/
, 1/*天津*/
, 1/*沈阳*/
, 1/*大连*/
, 1/*济南*/
, 1/*青岛*/
, 1/*徐州*/
, 1/*蚌埠*/
, 1/*合肥*/
, 1/*南京*/
, 1/*杭州*/
, 1/*南昌*/
, 1/*深圳*/
};

unsigned int city_ready[CITY_MAX][DIGIT];
unsigned char warning;

void Transform(void)  //将给出的10进制数转换成对应的16进制的ASCII值，一位一个数字存储在数组中
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

void Broadcast_Minor(void)  //这种语音播报是将原来的10进制的数转换成对应的16进制数进行比较判断是否播报（优化学长老程序思路）
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

void Broadcast_Major(void)  //这种语音播报是将读取到的字符转换成对应的10进制数进行比较判断是否播报（最佳）
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
	int flag;  //主要方案为真  备用方案为假
	flag = 1;  //改这里选方案
	if (flag)
		Broadcast_Major();
	else
		Broadcast_Minor();
}