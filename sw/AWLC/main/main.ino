#include <awlcIncludes.h>
#include <awlcSensorModules.h>
#include <awlcTypes.h>
#include <awlcMotorModules.h>
#include <awlcLCDModules.h>



//extern const char * awlcLcdMessages[eAWLC_LCD_MSG_TOTAL];
unsigned long previousMillis=0;
unsigned long intervel=500;

void setup() {
  awlcSerialPrintInit();
  awlcStatusLedInit();
  awlcSensorInit();
  awlcLcdInit();
  awlcMotorInit();
}
void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= intervel) {
    awlcStatusLedBlink();
    //awlcPrintf("%d",intervel);
    previousMillis = currentMillis;
   // awlcSensorTask();
  //  awlcLcdTask();
    //awlcMotorTask();
  }
}
