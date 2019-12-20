/**
 * awlcMotorModules.h
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
#ifndef _AWLC_MOTOR_MODULES_H
#define _AWLC_MOTOR_MODULES_H

#include <awlcIncludes.h>
/**
 *====================
 * Defines
 *====================
 **/
#define			AWLC_MOTOR_TRIGGER_PIN	  2
/**
 *======================
 * Function Declaration
 *======================
 */
void awlcMotorInit();
/* to turn on the motor */
UINT32 awlcMotorOn();
/* to turn off the motor */
UINT32 awlcMotorOff();
/* to read motor status */
UINT32 awlcReadMotorStatus();
/* to write motor status */
UINT32 awlcWriteMotorStatus();
/* main task of motor */
UINT32 awlcMotorTask();
#endif
