/**
 * awlcMotorModules.cpp
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
#include <awlcMotorModules.h>
extern UINT8  gu8MotorStatus;

void awlcMotorInit()
{
	awlcPrintf("===========================");
	awlcPrintf(" Motor Module Initializing");
	awlcPrintf("===========================");
	pinMode(AWLC_MOTOR_TRIGGER_PIN, OUTPUT);
	awlcPrintf("PIN : [%d] Direction : [%d]",AWLC_MOTOR_TRIGGER_PIN,OUTPUT);
}

UINT16 awlcMotorOn() 
{
	awlcPrintf("[MOTOR-MODULE] Motor ON");
	digitalWrite(AWLC_MOTOR_TRIGGER_PIN, AWLC_MOTOR_ON);
}

UINT16 awlcMotorOff() 
{
	awlcPrintf("[MOTOR-MODULE] Motor OFF");
	digitalWrite(AWLC_MOTOR_TRIGGER_PIN, AWLC_MOTOR_OFF);
}

UINT16 awlcReadMotorStatus()
{
	if(gu8MotorStatus == AWLC_MOTOR_ON) {
		awlcMotorOn();
	} else if(gu8MotorStatus == AWLC_MOTOR_OFF) {
		awlcMotorOff();
	} else {
		awlcPrintf("[MOTOR-MODULE] Motor Idel");
	}
}

UINT16 awlcMotorTask()
{
	awlcReadMotorStatus();
}
