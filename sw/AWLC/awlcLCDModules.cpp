/**
 * awlcLCDModules.cpp
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
 
#include <awlcLCDModules.h>

extern UINT8 gu8SourceTankStatus;
extern UINT8 gu8SumpTankStatus;
const char * awlcLcdMessages[eAWLC_LCD_MSG_TOTAL] = {"","EMPTY TANK","MOTOR ON","MOTOR OFF","DRY RUN","[#   ]","[##  ]","[####]"} ;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE );

VOID awlcLcdInit()
{
	awlcPrintf("=========================");
	awlcPrintf(" LCD Module Initializing");
	awlcPrintf("=========================");
	lcd.begin(AWLC_LCD_DISPLAY_ROW_MAX_LENGTH,AWLC_LCD_DISPLAY_COLUMN_MAX_LENGTH);
	awlcPrintf("Lcd Row : [%d] Columns [%d]",AWLC_LCD_DISPLAY_ROW_MAX_LENGTH,AWLC_LCD_DISPLAY_COLUMN_MAX_LENGTH);
}

SINT16 awlcLcdPrint
(
	UINT8 u8MsgType,
	UINT8 u8MsgId
)
{
	UINT8 u8Msg[AWLC_LCD_DISPLAY_MSG_MAX_LENGTH];  
	lcd.clear();
	switch(u8MsgType) {
	case eAWLC_ALERT_MSG:
	{
		lcd.setCursor ( 0, 0 );
		lcd.print(AWLC_ALERT_MSG_TAG);
		lcd.setCursor ( AWLC_LDC_MSG_POSITION, AWLC_ZERO );
		lcd.print(awlcLcdMessages[u8MsgId]);
	}
	break;
	case eAWLC_STATUS_MSG:
	{
		lcd.setCursor ( 0, 0 );
		lcd.print(AWLC_STATUS_MSG_TAG);
		lcd.setCursor ( AWLC_LDC_MSG_POSITION, AWLC_ZERO );
		lcd.print(awlcLcdMessages[u8MsgId]);
	}
	break;
	case eAWLC_SUMP_TANK_LEVEL_MSG:
	{
		lcd.setCursor( 0, 1 );
		lcd.print(AWLC_SMTANK_LEVEL_TAG);
		lcd.setCursor ( AWLC_LDC_SMT_LEVEL_POSITION, AWLC_ONE );
		lcd.print(awlcLcdMessages[u8MsgId]);
	}
	//~ default:
		//~ awlcPrintf("Unkown");
	//~ break;
	}  
	return AWLC_SUCCESS;
}

SINT16 awlcLcdDisplaySourceTankMsg()
{
	switch (gu8SourceTankStatus) {
	case eAWLC_LCD_MOTOR_ON:
	{
		awlcLcdPrint(eAWLC_STATUS_MSG,eAWLC_LCD_MOTOR_ON);
		awlcPrintf("[MSG] Motor is in ON state [%d]",eAWLC_LCD_MOTOR_ON);
	}
	break;
	case eAWLC_LCD_MOTOR_OFF:
	{
		awlcLcdPrint(eAWLC_STATUS_MSG,eAWLC_LCD_MOTOR_OFF);
		awlcPrintf("[MSG] Motor is in OFF state [%d]",eAWLC_LCD_MOTOR_OFF);
	}
	break;
	case eAWLC_LCD_EMPTY_TANK:
	{
		awlcLcdPrint(eAWLC_ALERT_MSG,eAWLC_LCD_EMPTY_TANK);
		awlcPrintf("[ALR] Tank is in EMPTY state [%d]",eAWLC_LCD_EMPTY_TANK);
	}
	break;
	case eAWLC_LCD_DRYRUN:
	{
		awlcLcdPrint(eAWLC_ALERT_MSG,eAWLC_LCD_DRYRUN);
		awlcPrintf("[ALR] Motor is in DRYrun state [%d]",eAWLC_LCD_DRYRUN);
	}
	break;
	//~ default:
		//~ awlcPrintf("Unkown Msg [%d]",gu8SourceTankStatus);
	//~ break;
	}
}
SINT16 awlcLcdDisplaySumpTankMsg()
{
	switch (gu8SumpTankStatus){
		case eAWLC_LCD_SUMP_EMPTY: 
		{
			awlcLcdPrint(eAWLC_SUMP_TANK_LEVEL_MSG,eAWLC_LCD_SUMP_EMPTY);
			awlcPrintf("Sump tank level is empty [%d]",eAWLC_LCD_SUMP_EMPTY);
		}
		break;
		case eAWLC_LCD_SUMP_HALF:
		{
			awlcLcdPrint(eAWLC_SUMP_TANK_LEVEL_MSG,eAWLC_LCD_SUMP_HALF);
			awlcPrintf("Sump tank level is half [%d]",eAWLC_LCD_SUMP_HALF);
		}
		break;
		case eAWLC_LCD_SUMP_FULL:
		{
			awlcLcdPrint(eAWLC_SUMP_TANK_LEVEL_MSG,eAWLC_LCD_SUMP_FULL);
			awlcPrintf("Sump tank level is full [%d]",eAWLC_LCD_SUMP_FULL);
		}
		break;
	}
}

SINT16 awlcLcdTask()
{
	awlcLcdDisplaySumpTankMsg();
	awlcLcdDisplaySourceTankMsg();
}
