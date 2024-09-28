#include <LiquidCrystal.h>

// Define LCD connections
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup()
{
  lcd.begin(16,2);
}

void loop()
{
  lcd.setCursor(3,0);
  lcd.print("CROSSWORDS");
  lcd.setCursor(0,1);
  lcd.print("B  GI ");
}