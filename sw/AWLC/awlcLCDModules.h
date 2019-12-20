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

#include <awlcIncludes.h>
 
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
//#define		AWLC_SERIAL_MAX_FILE_NAME_LEN					10
//#define		AWLC_SERIAL_MAX_API_NAME_LEN					10
//#define		AWLC_SERIAL_MAX_LINE_LEN						6


/**
 * AWLC messages
 * */
#ifdef	LCD_MSG_ID
#undef	LCD_MSG_ID
#endif
#define	LCD_MSG_ID(x) x,

#define	AWLC_LCD_MSG_ID							    \
	LCD_MSG_ID( eAWLC_LCD_UNKNOWN_MSG_ID )			\
	LCD_MSG_ID( eAWLC_LCD_FULL_TANK )			\
	LCD_MSG_ID( eAWLC_LCD_EMPTY_TANK )       \
	LCD_MSG_ID( eAWLC_LCD_MOTOR_ON )         \
	LCD_MSG_ID( eAWLC_LCD_MOTOR_OFF )        \
	LCD_MSG_ID( eAWLC_LCD_DRYRUN )           \
	LCD_MSG_ID( eAWLC_LCD_SUMP_EMPTY)		\
	LCD_MSG_ID( eAWLC_LCD_SUMP_HALF)		\
	LCD_MSG_ID( eAWLC_LCD_SUMP_FULL)		\
	LCD_MSG_ID( eAWLC_LCD_MSG_TOTAL )          	    \

typedef enum {
	AWLC_LCD_MSG_ID
} AWLC_EN_LCD_MSG_ID;

#undef	LCD_MSG_ID
#define	LCD_MSG_ID(x) #x,

const char * const astrLcdMsgIdNameMap[] = {AWLC_LCD_MSG_ID};
#define awlcLcdMsgName(id) astrLcdMsgIdNameMap[id]
/**
 * AWLC messages end
 * */

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


const char * const astrLogLevelNameMap[] = {AWLC_LCD_MSG_ID};
#define awlcLogLevelName(id) astrLogLevelNameMap[id]
 
 /**
 *======================
 * Function Declaration
 *======================
 */
VOID awlcLcdInit();
SINT16 awlcLcdTask();
SINT16 awlcLcdPrint(UINT8 u8MsgType,UINT8 u8MsgId);
SINT16 awlcLcdDisplaySourceTankMsg();
SINT16 awlcLcdDisplaySumpTankMsg();

#endif
