#ifndef __BROADCAST_H__
#define __BROADCAST_H__

#include "read_RFID.h"
#include <stm32f10x.h>
#include "voice.h"
#include "stm32f10x_gpio.h"
#include "delay.h"
#include "oled.h"
#include "string.h"
#include "stdio.h"

#define BUFF_LEN 12
#define CITY_MAX 20
#define DIGIT 4

void Transform(void);
void Broadcast_Minor(void);
void Broadcast_Major(void);
void Voice_Broadcast(void);

#endif