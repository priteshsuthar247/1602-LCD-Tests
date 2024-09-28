#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}

String str = "Hello World";

void loop() {
  lcd.blink();
  lcd.setCursor(0, 0);

  // Display the string
  for (int i = 0; i < str.length(); i++) {
    lcd.print(str.charAt(i));
    delay(400);
  }

  // Backspace effect
  for (int i = str.length()-1; i >= 0; i--) {
    lcd.setCursor(i, 0);
    lcd.print(" ");
    delay(200);
  }

  // Clear the display
  // lcd.clear();
  // delay(400);
}
