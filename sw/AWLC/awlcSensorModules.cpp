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

UINT8  gu8SourceTankStatus;  
UINT8  gu8SumpTankStatus; 
UINT8  gu8MotorStatus;
UINT8  gu8DryrunStatus; 
UINT64 gu64DryrunPrevTimeQt=0;
AWLC_SENSOR_VALUES gstrSensorPinData[AWLC_TOTAL_SENSOR_PINS];
UINT8 gu16TankSensorPins[AWLC_TOTAL_SENSOR_PINS] = { AWLC_DIGITAL_PIN_13,
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
	memset(gstrSensorPinData,0,sizeof(AWLC_SENSOR_VALUES));
	UINT8	u8SensorId;
	for(u8SensorId=0;u8SensorId<AWLC_TOTAL_SENSOR_PINS;u8SensorId++) {
		gstrSensorPinData[u8SensorId].u8SensorPinValue  =  digitalRead(gu16TankSensorPins[u8SensorId]);
		gstrSensorPinData[u8SensorId].u8SensorPinNo     =  gu16TankSensorPins[u8SensorId];
		awlcPrintf("PIN %d : %d",gstrSensorPinData[u8SensorId].u8SensorPinNo,
								gstrSensorPinData[u8SensorId].u8SensorPinValue);
	}
}
SINT8  awlcDryrunStatusCheck()
{
	
	UINT64 u64DryrunCurTimeOt = millis();
	if(gu8MotorStatus == AWLC_MOTOR_ON) {
		if(gstrSensorPinData[AWLC_DIGITAL_PIN_8].u8SensorPinValue == AWLC_WATER_ABSENCE){
			if (u64DryrunCurTimeOt - gu64DryrunPrevTimeQt >= AWLC_DRY_RUN_INTERVEL) {
				awlcPrintf("Motor is in Dryrun state for last %d sec",AWLC_DRY_RUN_INTERVEL);
				awlcPrintf("Force OFF Motor");
				gu64DryrunPrevTimeQt = u64DryrunCurTimeOt;
				gu8MotorStatus = AWLC_MOTOR_OFF;
			}
		}
	}
}
SINT16 awlcWriteStatusTag()
{
	gu8SourceTankStatus = 0;
	gu8SumpTankStatus   = 0;
	gu8MotorStatus      = 0;
	gu8DryrunStatus     = 0;
	
	// Check sump tank status
	if(gstrSensorPinData[AWLC_DIGITAL_PIN_12].u8SensorPinValue == AWLC_WATER_PRESENCE) {
		if(gstrSensorPinData[AWLC_DIGITAL_PIN_13].u8SensorPinValue == AWLC_WATER_PRESENCE) {
			awlcPrintf("SUMP is FULL");
			gu8SumpTankStatus=eAWLC_SUMP_FULL;
		} else if (gstrSensorPinData[AWLC_DIGITAL_PIN_13].u8SensorPinValue == AWLC_WATER_PRESENCE) {
			awlcPrintf("SUMP is HALF");
			gu8SumpTankStatus=eAWLC_SUMP_HALF;
		}
	} else if(gstrSensorPinData[AWLC_DIGITAL_PIN_11].u8SensorPinValue == AWLC_WATER_PRESENCE) {
		awlcPrintf("SUMP is HALF");
		gu8SumpTankStatus=eAWLC_SUMP_HALF;
	} else if(gstrSensorPinData[AWLC_DIGITAL_PIN_11].u8SensorPinValue == AWLC_WATER_ABSENCE) {
		awlcPrintf("SUMP is EMPTY");
		gu8SumpTankStatus=eAWLC_SUMP_EMPTY;
	}
	
	// Check source tank status
	if(gstrSensorPinData[AWLC_DIGITAL_PIN_9].u8SensorPinValue == AWLC_WATER_ABSENCE) {
		gu8SourceTankStatus=eAWLC_SOURCE_EMPTY;//tank is empty
		if(gu8SumpTankStatus != eAWLC_SUMP_EMPTY){
			awlcPrintf("MOTOR is ON");
			gu8MotorStatus=AWLC_MOTOR_ON;
		}
		if(gu8SumpTankStatus != eAWLC_SUMP_EMPTY){
			awlcPrintf("MOTOR is OFF");
			gu8MotorStatus=AWLC_MOTOR_OFF;
		}
		if(gstrSensorPinData[AWLC_DIGITAL_PIN_10].u8SensorPinValue == AWLC_WATER_PRESENCE){
			awlcPrintf("MOTOR is OFF");
			gu8MotorStatus=AWLC_MOTOR_OFF;	
			gu8SourceTankStatus=eAWLC_SOURCE_FULL;		
		}
	}
	//Tank is full
	if(gstrSensorPinData[AWLC_DIGITAL_PIN_10].u8SensorPinValue == AWLC_WATER_PRESENCE) {
		gu8SourceTankStatus=eAWLC_SOURCE_FULL;
	}
}
/*
 * Sensor task
 */
SINT16 awlcSensorTask() {
	awlcReadSensorValues();
	awlcWriteStatusTag();
	awlcDryrunStatusCheck();
}

