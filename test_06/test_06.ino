#include <LiquidCrystal.h>
int button1=8;
int button2=13;
int val1;
int val2;
int count=0;
int press; int Y;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String menu[] = {"Option 1", "Option 2", "Option 3", "Option 4"};
void setup() {
  lcd.begin(16, 2);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  
}
void loop() {
  val1=digitalRead(button1);
  val2=digitalRead(button2);
  
  if(val1==HIGH){
    delay(250);
    if (count == 4) {
      count = 0;
    }
    count++;
  }
  if(val2==HIGH){
    delay(250);
    if (count == 0) {
      count = 3;
    }
    count--;
  }
  lcd.setCursor(0, 0);
  lcd.print("Image");
  lcd.setCursor(1, 1);
  lcd.print(menu[count]);

}