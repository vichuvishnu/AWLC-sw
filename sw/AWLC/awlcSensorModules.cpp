/**
 * awlcSensorModules.cpp
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
#include <awlcSensorModules.h>
#include <awlcLCDModules.h>

UINT8  gu8SensorValue = 0;
UINT8  gu8SourceTankStatus =0;  
UINT8  gu8SumpTankStatus=0;  
AWLC_SENSOR_PIN_VALUES strPinValues;
#if 0
UINT16 gu16TankSensorPins[AWLC_TOTAL_SENSOR_PINS] = { AWLC_DIGITAL_PIN_13,
														AWLC_DIGITAL_PIN_12,
														AWLC_DIGITAL_PIN_11,
														AWLC_DIGITAL_PIN_10,
														AWLC_DIGITAL_PIN_9,
														AWLC_DIGITAL_PIN_8,
														AWLC_DIGITAL_PIN_7,
														AWLC_DIGITAL_PIN_6,
														AWLC_DIGITAL_PIN_5,
														AWLC_DIGITAL_PIN_4,
														AWLC_DIGITAL_PIN_3 };
#endif
UINT16 gu16TankSensorPins[AWLC_TOTAL_SENSOR_PINS] = { 13,12,11,10,9,8,7,6,5,4,3 };

void awlcSensorInit()
{
	UINT16 u16SensorId;
	awlcPrintf("============================");
	awlcPrintf(" Sensor Module Initializing");
	awlcPrintf("============================");
	for (u16SensorId = 0; u16SensorId < AWLC_TOTAL_SENSOR_PINS; u16SensorId++) {
		pinMode(gu16TankSensorPins[u16SensorId], INPUT);
		awlcPrintf("PIN : [%d] Direction : [%d]",gu16TankSensorPins[u16SensorId],INPUT);
	}
}

SINT16 awlcReadSensorValues () 
{
	strPinValues.u16SensorValues=0;
	strPinValues.pin.u16SensorPin13Value = digitalRead(13);	
	strPinValues.pin.u16SensorPin12Value = digitalRead(12);	
	strPinValues.pin.u16SensorPin11Value = digitalRead(11);	
	strPinValues.pin.u16SensorPin10Value = digitalRead(10);	
	strPinValues.pin.u16SensorPin9Value  = digitalRead(9);	
	strPinValues.pin.u16SensorPin8Value  = digitalRead(8);	
	strPinValues.pin.u16SensorPin7Value  = digitalRead(7);	
	strPinValues.pin.u16SensorPin6Value  = digitalRead(6);	
	strPinValues.pin.u16SensorPin5Value  = digitalRead(5);	
	strPinValues.pin.u16SensorPin4Value  = digitalRead(4);	
	strPinValues.pin.u16SensorPin3Value  = digitalRead(3);	
#if 0
	awlcPrintf("PIN 13 : %d",strPinValues.pin.u16SensorPin13Value);
	awlcPrintf("PIN 12 : %d",strPinValues.pin.u16SensorPin12Value);
	awlcPrintf("PIN 11 : %d",strPinValues.pin.u16SensorPin11Value);
	awlcPrintf("PIN 10 : %d",strPinValues.pin.u16SensorPin10Value);
	awlcPrintf("PIN 9  : %d",strPinValues.pin.u16SensorPin9Value);
	awlcPrintf("PIN 8  : %d",strPinValues.pin.u16SensorPin8Value);
	awlcPrintf("PIN 7  : %d",strPinValues.pin.u16SensorPin7Value);
	awlcPrintf("PIN 6  : %d",strPinValues.pin.u16SensorPin6Value);
	awlcPrintf("PIN 5  : %d",strPinValues.pin.u16SensorPin5Value);
	awlcPrintf("PIN 4  : %d",strPinValues.pin.u16SensorPin4Value);
	awlcPrintf("PIN 3  : %d",strPinValues.pin.u16SensorPin3Value);
#endif
}

SINT16 awlcWriteStatusTag()
{
	// Check that sump tank is full
	if (strPinValues.u16SensorValues == 128) {
		gu8SourceTankStatus=eAWLC_LCD_FULL_TANK;
		gu8SumpTankStatus=eAWLC_LCD_SUMP_FULL;
	}
}
/*
 * Sensor task
 */
SINT16 awlcSensorTask() {
	awlcReadSensorValues();
	awlcWriteStatusTag();
}

