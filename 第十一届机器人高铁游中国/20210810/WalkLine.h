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

#define ForWard_LeftPower 1575          //前进左速
#define ForWard_RightPower 1420         //前进右速
#define BackWard_LeftPower 1415         //后退左速
#define BackWard_RightPower 1564        //后退右速

#define LeftTurn_LeftPower 1445         //左转左速
#define LeftTurn_RightPower 1450        //左转右速
#define RightTurn_LeftPower 1545        //右转左速
#define RightTurn_RightPower 1540       //右转右速

void Front_LeftTurn(void);              //前面中间两个QTI判断左转
void Front_RightTurn(void);             //前面中间两个QTI判断右转
void Behind_LeftTurn(void);             //后面中间两个QTI判断左转
void Behind_RightTurn(void);            //后面中间两个QTI判断右转

void Step_ForWard(int step);            //步进冲距前进
void Step_BackWard(int step);           //步进冲距后退

void Front_QTI_ForWard(void);           //前面中间两个QTI判断前进巡线
void Behind_QTI_ForWard(void);          //后面中间两个QTI判断前进巡线
void Front_QTI_BackWard(void);          //前面中间两个QTI判断后退巡线
void Behind_QTI_BackWard(void);         //后面中间两个QTI判断后退寻线

void WalkLine_ForWard(int flag);        //前进巡线
void WalkLine_BackWard(int flag);       //后退巡线

#endif