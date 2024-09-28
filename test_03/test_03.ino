#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}

String str = "Hello World ";

void loop() {
  for (int i = 0 ; i<str.length(); i++) {
    lcd.print(str.charAt(i));
    delay(100);
  }
  lcd.setCursor(16,0);
  lcd.autoscroll();
  for (int i = 0; i<str.length(); i++) {
    lcd.print(str.charAt(i));
    delay(400);
  }
  lcd.noAutoscroll();
}
