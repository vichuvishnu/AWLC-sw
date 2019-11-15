#ifndef __AWLC_INCLUDES_H__
#define __AWLC_INCLUDES_H__

#include "awlcTypes.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define 	AWLC_SUCCESS					0
#define 	AWLC_FAILURE					-1
#define 	AWLC_ONE						1
#define 	AWLC_ZERO						0
#define 	AWLC_LCD_MSG_LENGTH				10
#define 	AWLC_SOURCE_TANK_LEVEL_ONE_PIN	3


//global var
UINT8 gu8StatusLedBlink=1;
SINT8 u8Msg[AWLC_LCD_MSG_LENGTH];
#endif
