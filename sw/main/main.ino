#include <awlcIncludes.h>
#include <awlcTypes.h>
#include <awlcLCDModules.h>



extern const char * awlcLcdMessages[eAWLC_LCD_MSG_TOTAL];
VOID setup() {
  awlcLcdInit();
  awlcSerialPrintInit();
}


VOID loop() {
  // put your main code here, to run repeatedly:
  awlcStatusLedBlink();
  awlcLcdPrint(eAWLC_ALERT_MSG,eAWLC_LCD_DRY_RUN_MSG_ID);
  delay(1500);
  awlcStatusLedBlink();
  awlcLcdPrint(eAWLC_STATUS_MSG,eAWLC_LCD_MOTOR_ON_MSG_ID);
  delay(1500);
}
