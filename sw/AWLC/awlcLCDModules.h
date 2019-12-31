/**
 * awlcLCDModules.h
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
#ifndef _AWLC_MODULES_H_
#define	_AWLC_MODULES_H_

/**
 *====================
 * Includes
 *====================
 **/

#include <awlcCommonModules.h>
 
 /**
 *====================
 * Defines
 *====================
 **/

#define 	AWLC_LCD_DISPLAY_ROW_MAX_LENGTH				16
#define		AWLC_LCD_DISPLAY_COLUMN_MAX_LENGTH			2
#define		AWLC_LCD_DISPLAY_MSG_MAX_LENGTH				12
#define		AWLC_LCD_DISPLAY_TANK_LEVEL_MAX_LENGTH		10
#define 	AWLC_LDC_ALRT_MSG_LENGTH					AWLC_LCD_DISPLAY_MSG_MAX_LENGTH
#define 	AWLC_LDC_STATUS_MSG_LENGTH					AWLC_LCD_DISPLAY_MSG_MAX_LENGTH
#define 	AWLC_LDC_MSG_POSITION						AWLC_LCD_DISPLAY_MSG_MAX_LENGTH
#define 	AWLC_LDC_SMT_LEVEL_POSITION					10
#define		AWLC_ALERT_MSG_TAG							"ALT:"
#define		AWLC_STATUS_MSG_TAG 						"MSG:"
#define		AWLC_TANK_LEVEL_TAG							"LEVEL:"
#define		AWLC_SMTANK_LEVEL_TAG						"SMT LEVEL:"

/**
 *======================
 * Enumeration
 *======================
 */
 /** AWLC display msg types **/
typedef enum AWLC_MESSAGE_TYPE {
	eAWLC_UNKNOWN_MSG = 0,
	eAWLC_ALERT_MSG,
	eAWLC_STATUS_MSG,
	eAWLC_SUMP_TANK_LEVEL_MSG,
	eAWLC_SOURCE_TANK_LEVEL_MSG
}AWLC_EN_LCD_MESSAGE_TYPES;

/** AWLC display msg **/
typedef enum {
	eAWLC_LCD_UNKNOWN_MSG_ID=0,
	eAWLC_LCD_FULL_TANK,
	eAWLC_LCD_EMPTY_TANK,
	eAWLC_LCD_MOTOR_ON,
	eAWLC_LCD_MOTOR_OFF,
	eAWLC_LCD_DRYRUN,
	eAWLC_LCD_SUMP_EMPTY,
	eAWLC_LCD_SUMP_HALF,
	eAWLC_LCD_SUMP_FULL,
	eAWLC_LCD_MSG_TOTAL,
}AWLC_EN_LCD_MSG_ID;

 /**
 *======================
 * Function Declaration
 *======================
 */
 /** lcd task init **/
VOID awlcLcdInit();
/** lcd task **/
SINT16 awlcLcdTask();
/** awlc Boot Animation **/
VOID awlcBootAnimation();
/** lcd print msg **/
SINT16 awlcLcdPrint(UINT8 u8MsgType,UINT8 u8MsgId);
/** lcd print source tank msg **/
SINT16 awlcLcdDisplaySourceTankMsg();
/** lcd print sump tank msg **/
SINT16 awlcLcdDisplaySumpTankMsg();

#endif
