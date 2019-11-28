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

UINT8 gu8StatusLedBlink;
const char * awlcLcdMessages[eAWLC_LCD_MSG_TOTAL] = {"","EMPTY TANK","MOTOR ON","MOTOR OFF","DRY RUN"} ;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE );
void awlcSerialPrintInit()
{
	Serial.begin(AWLC_BAUD_RATE);
}

VOID awlcLcdInit()
{
	pinMode(LED_BUILTIN, OUTPUT);
	lcd.begin(16,2);
}

void	awlcPrintf
(
	const char	* ps8Fmt,
	...
)
{
#ifdef AWLC_DEBUG_PRINT_ENABLE
    SINT8 as8LogBuf[AWLC_SERIAL_PRINT_BUF_MAX];
	va_list args;
	va_start(args, ps8Fmt);
	vsprintf(as8LogBuf, ps8Fmt, args);
	va_end(args);
	Serial.print("[AWLC] ");
	Serial.println(as8LogBuf);
#endif
} /* mdcPrintf */

SINT32 awlcStatusLedBlink()
{
  if(gu8StatusLedBlink == 1) {
    gu8StatusLedBlink=0;
    digitalWrite(LED_BUILTIN, HIGH);
  } else if (gu8StatusLedBlink == 0) {
    gu8StatusLedBlink=1;
    digitalWrite(LED_BUILTIN, LOW);
  }
  return AWLC_SUCCESS;
}

SINT32 awlcLcdPrint
(
	UINT8 u8MsgType,
	UINT8 u8MsgId
)
{
	UINT8 u8Msg[AWLC_LCD_DISPLAY_MSG_MAX_LENGTH];  
	lcd.clear();
	switch(u8MsgType) {
	case eAWLC_ALERT_MSG:
		lcd.setCursor ( 0, 0 );
		lcd.print(AWLC_ALERT_MSG_TAG);
		lcd.setCursor ( AWLC_LDC_MSG_POSITION, 0 );
		lcd.print(awlcLcdMessages[u8MsgId]);
		awlcPrintf("Unkown");
	break;
	case eAWLC_STATUS_MSG:
		lcd.setCursor ( 0, 0 );
		lcd.print(AWLC_STATUS_MSG_TAG);
		lcd.setCursor ( AWLC_LDC_MSG_POSITION, 0 );
		lcd.print(awlcLcdMessages[u8MsgId]);
		awlcPrintf("Unkown");
	break;
	default:
		awlcPrintf("Unkown");
	break;
	}  
	return AWLC_SUCCESS;
}
