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
 
 #include <awlcIncludes.h>
 
UINT8 gu8StatusLedBlink;
 
 void awlcSerialPrintInit()
{
	Serial.begin(AWLC_BAUD_RATE);
}

void awlcStatusLedInit()
{
	pinMode(AWLC_STATUS_LED_PIN, OUTPUT);
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
  //awlcPrintf("LED [%d]",gu8StatusLedBlink);
  if(gu8StatusLedBlink == 1) {
    gu8StatusLedBlink=0;
    digitalWrite(AWLC_STATUS_LED_PIN, HIGH);
  } else if (gu8StatusLedBlink == 0) {
    gu8StatusLedBlink=1;
    digitalWrite(AWLC_STATUS_LED_PIN, LOW);
  }
  return AWLC_SUCCESS;
}
