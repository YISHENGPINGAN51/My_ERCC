#ifndef __WALKLINE_H
#define __WALKLINE_H

#include <stm32f10x.h>
#include "delay.h"
#include "qti.h"
#include "voice.h"
#include <read_RFID.h>
#include <motor.h>
#include <stdio.h>

#define ForWard_LeftPower 1575            //ǰ������
#define ForWard_RightPower 1420           //ǰ������
#define BackWard_LeftPower 1415           //��������
#define BackWard_RightPower 1564          //��������

#define LeftTurn_LeftPower 1445           //��ת����
#define LeftTurn_RightPower 1450          //��ת����
#define RightTurn_LeftPower 1545          //��ת����
#define RightTurn_RightPower 1540         //��ת����

#define Stop_LeftPower 1495               //ֹͣ����
#define Stop_RightPower 1492              //ֹͣ����

void ForGo(void);                         //ǰ��
void BackGo(void);                        //����
void RightGo(void);                       //��ת
void LeftGo(void);                        //��ת
void Stop(void);                          //ֹͣ

void LeftGo_LeftRun(void);                //�����ֺ�����ת
void LeftGo_RightRun(void);               //������ǰ����ת
void RightGo_LeftRun(void);               //������ǰ����ת
void RightGo_RightRun(void);              //�����ֺ�����ת

void Front_LeftTurn(void);                //ǰ���м�����QTI�ж���ת
void Front_RightTurn(void);               //ǰ���м�����QTI�ж���ת
void Behind_LeftTurn(void);               //�����м�����QTI�ж���ת
void Behind_RightTurn(void);              //�����м�����QTI�ж���ת

void Step_ForGo(int step);                //�������ǰ��
void Step_BackGo(int step);               //����������
void Step_RightGo(int step);              //���������ת
void Step_LeftGo(int step);               //���������ת

void Front_QTI_ForWard(void);             //ǰ���ĸ�QTI�ж�ǰ��Ѳ��
void Behind_QTI_ForWard(void);            //�����м�����QTI�ж�ǰ��Ѳ��
void Front_QTI_BackWard(void);            //ǰ���м�����QTI�жϺ���Ѳ��
void Behind_QTI_BackWard(void);           //�����ĸ�QTI�жϺ���Ѱ��

void Front_QTI_TimeForWard(int time);     //ǰ���ĸ�QTI��ʱǰ��Ѳ��
void Behind_QTI_TimeForWard(int time);    //�����м�����QTI��ʱǰ��Ѳ��
void Front_QTI_TimeBackWard(int time);    //ǰ���м�����QTI��ʱ����Ѳ��
void Behind_QTI_TimeBackWard(int time);   //�����ĸ�QTI��ʱ����Ѳ��

void WalkLine_ForWard_Major(int mode);    //����ǰ��Ѳ��  ����ģʽ0����ģʽ0  û�²�Ҫ��ģʽ1
void WalkLine_BackWard_Major(int mode);   //��������Ѳ��  ����ģʽ0����ģʽ0  û�²�Ҫ��ģʽ1
void WalkLine_ForWard_Minor(int mode);    //����ǰ��Ѳ��  ģʽ0�ж̾�ʹ��  ģʽ1����ʹ�ã��ɲ���һ�ΰ�ʱѲ�ߣ�
void WalkLine_BackWard_Minor(int mode);   //���ú���Ѳ��  ģʽ0�ж̾�ʹ��  ģʽ1����ʹ�ã��ɲ���һ�ΰ�ʱѲ�ߣ�

#endif