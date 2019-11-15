/**
 * awlcLCDModules.c
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
 
#include "awlcLCDModules.h"

SINT32 awlcLcdPrint
(
	UINT8 u8MsgType,
	UINT8 u8MsgId
)
{
	UINT8 u8Msg[AWLC_LCD_DISPLAY_ROW_MAX_LENGTH];
	switch(u8MsgType)
	{
		case eAWLC_ALERT_MSG:
		{
			sprintf(u8Msg,"%s%s",AWLC_ALERT_MSG_TAG,"haiii");
		}
		break;
		case eAWLC_STATUS_MSG:
		{
		}
		break;
		case eAWLC_TANK_LEVEL_MSG:
		{
		}
		break;
		default:
			printf("Error msg");
		break;
	}
}
