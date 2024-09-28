#include <LiquidCrystal.h>
int button=8;
int val;
int count=0;
int press; int Y;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  pinMode(button,INPUT);
}

void loop() {
  val=digitalRead(button);
  if(val==HIGH){
    press=count++;
    Y=press; //y=mx+b
    delay(250);
  }
  lcd.setCursor(0, 0);
  lcd.print("Button Count");
  lcd.setCursor(0, 1);
  lcd.print(Y);

}