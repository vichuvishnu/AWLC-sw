#ifndef __AWLC_COMMON_INCLUDES_H__
#define __AWLC_COMMON_INCLUDES_H__

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
#define 	AWLC_MOTOR_ON   							AWLC_ONE
#define 	AWLC_MOTOR_OFF  							AWLC_ZERO
#define 	AWLC_WATER_PRESENCE							AWLC_ZERO
#define 	AWLC_WATER_ABSENCE							AWLC_ONE
#define		AWLC_DRY_RUN_INTERVEL						255
#define		AWLC_MAIN_LOOP_INTERVEL						500

typedef enum{
	eAWLC_UNKNOWN_STATUS = 0,
	eAWLC_SOURCE_FULL,   //1
	eAWLC_SOURCE_EMPTY,  //2
	eAWLC_MOTOR_ON,      //3
	eAWLC_MOTOR_OFF,     //4
	eAWLC_DRYRUN,        //5
	eAWLC_SUMP_EMPTY,    //6
	eAWLC_SUMP_HALF,     //7
	eAWLC_SUMP_FULL,     //8
	eAWLC_TOTAL_STATUS,  //9
}AWLC_EN_SENSOR_STATUS;

SINT32 awlcStatusLedBlink();
void awlcPrintf(const char	* ps8Fmt,...);
VOID awlcSerialPrintInit();
void awlcStatusLedInit();
#endif //__AWLC_COMMON_INCLUDES_H__
