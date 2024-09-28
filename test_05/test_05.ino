#include <LiquidCrystal.h>
int button1=8;
int button2=13;
int val1;
int val2;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
byte Skull[8] = {
  0b00000,
  0b01110,
  0b10101,
  0b11011,
  0b01110,
  0b01110,
  0b00000,
  0b00000
};
byte Alien[8] = {
  0b11111,
  0b10101,
  0b11111,
  0b11111,
  0b01110,
  0b01010,
  0b11011,
  0b00000
};
void setup() {
  lcd.begin(16, 2);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  lcd.createChar(0,Alien);
  lcd.createChar(1,Skull);
}

void loop() {
  val1=digitalRead(button1);
  val2=digitalRead(button2);
  if(val1==HIGH){
    lcd.write(byte(0));
    delay(250);
  }
  if(val2==HIGH){
    lcd.write(byte(1));
    delay(250);
  }
  lcd.setCursor(0, 0);
  lcd.print("Image");
  lcd.setCursor(1, 1);
  

}