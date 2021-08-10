#ifndef __WALKLINE_H
#define __WALKLINE_H

#include <stm32f10x.h>
#include "delay.h"
#include "move.h"
#include "qti.h"
#include "voice.h"
#include <read_RFID.h>
#include <motor.h>
#include <stdio.h>

#define ForWard_LeftPower 1575          //ǰ������
#define ForWard_RightPower 1420         //ǰ������
#define BackWard_LeftPower 1415         //��������
#define BackWard_RightPower 1564        //��������

#define LeftTurn_LeftPower 1445         //��ת����
#define LeftTurn_RightPower 1450        //��ת����
#define RightTurn_LeftPower 1545        //��ת����
#define RightTurn_RightPower 1540       //��ת����

void Front_LeftTurn(void);              //ǰ���м�����QTI�ж���ת
void Front_RightTurn(void);             //ǰ���м�����QTI�ж���ת
void Behind_LeftTurn(void);             //�����м�����QTI�ж���ת
void Behind_RightTurn(void);            //�����м�����QTI�ж���ת

void Step_ForWard(int step);            //�������ǰ��
void Step_BackWard(int step);           //����������

void Front_QTI_ForWard(void);           //ǰ���м�����QTI�ж�ǰ��Ѳ��
void Behind_QTI_ForWard(void);          //�����м�����QTI�ж�ǰ��Ѳ��
void Front_QTI_BackWard(void);          //ǰ���м�����QTI�жϺ���Ѳ��
void Behind_QTI_BackWard(void);         //�����м�����QTI�жϺ���Ѱ��

void WalkLine_ForWard(int flag);        //ǰ��Ѳ��
void WalkLine_BackWard(int flag);       //����Ѳ��

#endif