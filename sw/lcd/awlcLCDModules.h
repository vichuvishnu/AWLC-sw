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

#include "../includes/awlcIncludes.h"

 
 /**
 *====================
 * Defines
 *====================
 **/
#define 	AWLC_LCD_DISPLAY_ROW_MAX_LENGTH				16
#define		AWLC_LCD_DISPLAY_COLUMN_MAX_LENGTH			2
#define		AWLC_LCD_DISPLAY_MSG_MAX_LENGTH				12
#define		AWLC_LCD_DISPLAY_TANK_LEVEL_MAX_LENGTH		10
#define 	AWLC_LDC_ALRT_MSG_LENTH						AWLC_LCD_DISPLAY_MSG_MAX_LENGTH
#define 	AWLC_LDC_STATUS_MSG_LENTH					AWLC_LCD_DISPLAY_MSG_MAX_LENGTH
#define		AWLC_ALERT_MSG_TAG							"ALT:"
#define		AWLC_STATUS_MSG_TAG 						"MSG:"
#define		AWLC_TANK_LEVEL_TAG							"LEVEL:"


/**
 * AWLC messages
 * */
#ifdef	MSG_ID
#undef	MSG_ID
#endif
#define	MSG_ID(x) x,

#define	AWLC_LCD_MSG_ID							\
	MSG_ID( eAWLC_LCD_UNKNOWN_MSG_ID )			\
	MSG_ID( eAWLC_LCD_EMPTY_TANK_MSG_ID )              \
	MSG_ID( eAWLC_LCD_MOTOR_ON_MSG_ID )          	\
	MSG_ID( eAWLC_LCD_MOTOR_OFF_MSG_ID )          	\
	MSG_ID( eAWLC_LCD_DRY_RUN_MSG_ID )          	\
	MSG_ID( eAWLC_LCD_MSG_TOTAL )          	\

typedef enum {
	AWLC_LCD_MSG_ID
} AWLC_EN_LCD_MSG_ID;

#undef	MSG_ID
#define	MSG_ID(x) #x,

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
	eAWLC_TANK_LEVEL_MSG
}AWLC_EN_LCD_MESSAGE_TYPES;

const char * awlcLcdMessages[eAWLC_LCD_MSG_TOTAL] = {"","EMPTY TANK","MOTOR ON","MOTOR OFF","DRY RUN"} ;
/**
 *======================
 * Structure 
 *======================
 **/
 
 
 /**
 *======================
 * Function Declaration
 *======================
 */
  SINT32 awlcLcdPrint(UINT8 u8MsgType,UINT8 u8MsgId);
  SINT32 awlcLcdDisplayAlert();
  SINT32 awlcLcdDisplayMsg();
  SINT32 awlcLcdDisplayTankLevel();
#endif
