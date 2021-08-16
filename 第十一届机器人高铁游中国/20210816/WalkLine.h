#ifndef __WALKLINE_H
#define __WALKLINE_H

#include <stm32f10x.h>
#include "delay.h"
#include "qti.h"
#include "voice.h"
#include <read_RFID.h>
#include <motor.h>
#include <stdio.h>

#define ForWard_LeftPower 1575            //前进左速
#define ForWard_RightPower 1420           //前进右速
#define BackWard_LeftPower 1415           //后退左速
#define BackWard_RightPower 1564          //后退右速

#define LeftTurn_LeftPower 1445           //左转左速
#define LeftTurn_RightPower 1450          //左转右速
#define RightTurn_LeftPower 1545          //右转左速
#define RightTurn_RightPower 1540         //右转右速

#define Stop_LeftPower 1495               //停止左速
#define Stop_RightPower 1492              //停止右速

void ForGo(void);                         //前进
void BackGo(void);                        //后退
void RightGo(void);                       //右转
void LeftGo(void);                        //左转
void Stop(void);                          //停止

void LeftGo_LeftRun(void);                //绕右轮后退左转
void LeftGo_RightRun(void);               //绕左轮前进左转
void RightGo_LeftRun(void);               //绕右轮前进右转
void RightGo_RightRun(void);              //绕左轮后退右转

void Front_LeftTurn(void);                //前面中间两个QTI判断左转
void Front_RightTurn(void);               //前面中间两个QTI判断右转
void Behind_LeftTurn(void);               //后面中间两个QTI判断左转
void Behind_RightTurn(void);              //后面中间两个QTI判断右转

void Step_ForGo(int step);                //步进冲距前进
void Step_BackGo(int step);               //步进冲距后退
void Step_RightGo(int step);              //步进冲距右转
void Step_LeftGo(int step);               //步进冲距左转

void Front_QTI_ForWard(void);             //前面四个QTI判断前进巡线
void Behind_QTI_ForWard(void);            //后面中间两个QTI判断前进巡线
void Front_QTI_BackWard(void);            //前面中间两个QTI判断后退巡线
void Behind_QTI_BackWard(void);           //后面四个QTI判断后退寻线

void Front_QTI_TimeForWard(int time);     //前面四个QTI按时前进巡线
void Behind_QTI_TimeForWard(int time);    //后面中间两个QTI按时前进巡线
void Front_QTI_TimeBackWard(int time);    //前面中间两个QTI按时后退巡线
void Behind_QTI_TimeBackWard(int time);   //后面四个QTI按时后退巡线

void WalkLine_ForWard_Major(int mode);    //正常前进巡线  能用模式0就用模式0  没事不要用模式1
void WalkLine_BackWard_Major(int mode);   //正常后退巡线  能用模式0就用模式0  没事不要用模式1
void WalkLine_ForWard_Minor(int mode);    //备用前进巡线  模式0中短距使用  模式1长距使用（可补增一段按时巡线）
void WalkLine_BackWard_Minor(int mode);   //备用后退巡线  模式0中短距使用  模式1长距使用（可补增一段按时巡线）

#endif