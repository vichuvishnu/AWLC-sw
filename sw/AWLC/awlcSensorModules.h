/**
 * awlcSensorModules.h
 * 
 * Copyright 2019 Vishnu Bhaskar <vishnu.bhaskar.996@outlook.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
 
#ifndef _AWLC_SENSOR_MODULES_H_
#define	_AWLC_SENSOR_MODULES_H_
#include <awlcIncludes.h>
#include <awlcLCDModules.h>

/**
 *====================
 * Defines
 *====================
 **/
 /*
#define			AWLC_DIGITAL_PIN_13			13
#define			AWLC_DIGITAL_PIN_12			12
#define			AWLC_DIGITAL_PIN_11			11
#define			AWLC_DIGITAL_PIN_10			10
#define			AWLC_DIGITAL_PIN_9			9
#define			AWLC_DIGITAL_PIN_8			8
#define			AWLC_DIGITAL_PIN_7			7
#define			AWLC_DIGITAL_PIN_6			6
#define			AWLC_DIGITAL_PIN_5			5
#define			AWLC_DIGITAL_PIN_4			4
#define			AWLC_DIGITAL_PIN_3			3
*/
#define			AWLC_TOTAL_SENSOR_PINS		11
/**
 * AWLC sensor pins
 */
#pragma pack(1)
#if 0
typedef enum {
	eAWLC_SUMP_TANK_SENSOR_FULL_PIN=0,       // PIN 13
	eAWLC_SUMP_TANK_SENSOR_HALF_PIN,         // PIN 12
	eAWLC_SUMP_TANK_SENSOR_EMPTY_PIN,        // PIN 11
	eAWLC_SOURCE_TANK_SENSOR_FULL_PIN,       // PIN 10
	eAWLC_SOURCE_TANK_SENSOR_EMPTY_PIN,      // PIN 9
	eAWLC_SOURCE_TANK_SENSOR_DRYRUN_PIN,     // PIN 8
	eAWLC_SOURCE_TANK_SENSOR_LEVEL_1_PIN,    // PIN 7
	eAWLC_SOURCE_TANK_SENSOR_LEVEL_2_PIN,    // PIN 6
	eAWLC_SOURCE_TANK_SENSOR_LEVEL_3_PIN,    // PIN 5
	eAWLC_SOURCE_TANK_SENSOR_LEVEL_4_PIN,    // PIN 4
	eAWLC_SOURCE_TANK_SENSOR_LEVEL_5_PIN,    // PIN 3
	eAWLC_TOTAL_SENSOR_PIN
} AWLC_EN_TANK_SENSOR_PIN_ID;
#endif
typedef union {
	UINT16 u16SensorValues;
	typedef struct {
		UINT16 u16SensorPin3Value 	: 1;//0
		UINT16 u16SensorPin4Value 	: 1;
		UINT16 u16SensorPin5Value 	: 1;
		UINT16 u16SensorPin6Value 	: 1;
		UINT16 u16SensorPin7Value 	: 1;
		UINT16 u16SensorPin8Value 	: 1;
		UINT16 u16SensorPin9Value 	: 1;
		UINT16 u16SensorPin10Value 	: 1;
		UINT16 u16SensorPin11Value 	: 1;
		UINT16 u16SensorPin12Value 	: 1;
		UINT16 u16SensorPin13Value 	: 1;//11
	}SENSOR_PIN;
	SENSOR_PIN pin;
}AWLC_SENSOR_PIN_VALUES;
#pragma pack(0)
/**
 *======================
 * Function Declaration
 *======================
 */
void awlcSensorInit();
SINT16 awlcSensorTask();
SINT16 awlcReadSensorValues();
SINT16 awlcWriteStatusTag();
SINT16 awlcReadStatusTag();

#endif
