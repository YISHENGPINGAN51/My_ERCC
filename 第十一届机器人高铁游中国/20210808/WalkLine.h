#ifndef __WALKLINE_H
#define __WALKLINE_H

#include <stm32f10x.h>
#include "delay.h"
#include "move.h"
#include "qti.h"
#include "voice.h"
#include <read_RFID.h>
#include <motor.h>

#define LeftTurn_LeftPower 1445         //左转左速
#define LeftTurn_RightPower 1450        //左转右速
#define RightTurn_LeftPower 1545        //右转左速
#define RightTurn_RightPower 1540       //右转右速

void FrontlLeftTurn(void);
void FrontRightTurn(void);
void BehindLeftTurn(void);
void BehindRightTurn(void);

void Step(int step);

void Front_QTI_ForWard(void);
void Behind_QTI_ForWard(void);
void Front_QTI_BackWard(void);
void Behind_QTI_BackWard(void);

void WalkLineForWard(void);
void WalkLineBackWard(void);

#endif