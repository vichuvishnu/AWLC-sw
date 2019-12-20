#ifndef __AWLC_INCLUDES_H__
#define __AWLC_INCLUDES_H__

#include <awlcTypes.h>
#include <Wire.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <libgen.h>
#include <LiquidCrystal_I2C.h>

#define 	AWLC_ONE									1
#define 	AWLC_ZERO									0
#define 	AWLC_SUCCESS								AWLC_ZERO
#define 	AWLC_FAILURE								-1
#define 	AWLC_LCD_MSG_LENGTH							10
#define 	AWLC_SOURCE_TANK_LEVEL_ONE_PIN				3
#define 	AWLC_DEBUG_PRINT_ENABLE 					
#define		AWLC_STATUS_LED_PIN							A0
#define		AWLC_BAUD_RATE								9600
#define		AWLC_SERIAL_PRINT_BUF_MAX   				1024
#define 	AWLC_DIGITAL_HIGH							AWLC_ONE
#define 	AWLC_DIGITAL_LOW							AWLC_ZERO
SINT32 awlcStatusLedBlink();
void awlcPrintf(const char	* ps8Fmt,...);
VOID awlcSerialPrintInit();
void awlcStatusLedInit();
#endif
