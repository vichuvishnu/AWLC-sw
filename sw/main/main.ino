#include <awlcIncludes.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE );


VOID setup() {
  // initialize digital pin LED_BUILTIN as an output.for status
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}

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

SINT32 awlcLcdDisplayMsg
(
  SINT8 s8Msg[AWLC_LCD_MSG_LENGTH]
)
{
  lcd.clear();
  lcd.setCursor(0,0);
  Serial.println(s8Msg);
  lcd.print(u8Msg);
  return AWLC_SUCCESS;
}
SINT32 awlcWriteOnLCD()
{
  strcpy(u8Msg,"ALT:error");
  awlcLcdDisplayMsg(u8Msg);
}
VOID loop() {
  // put your main code here, to run repeatedly:
  awlcStatusLedBlink();
  awlcWriteOnLCD();
  delay(500);
}
