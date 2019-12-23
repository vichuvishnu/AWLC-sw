#include <awlcCommonModules.h>
#include <awlcSensorModules.h>
#include <awlcTypes.h>
#include <awlcMotorModules.h>
#include <awlcLCDModules.h>

unsigned long previousMillis=0;

void setup() {
  awlcSerialPrintInit();
  awlcStatusLedInit();
  awlcSensorInit();
  awlcLcdInit();
  awlcMotorInit();
}
void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= AWLC_MAIN_LOOP_INTERVEL) {
    awlcStatusLedBlink();
    previousMillis = currentMillis;
    awlcSensorTask();
    awlcLcdTask();
    //awlcMotorTask();
  }
}
