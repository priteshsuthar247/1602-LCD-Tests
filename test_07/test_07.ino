#include <LiquidCrystal.h>

// Define LCD connections
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Define button pins
const int button1 = 10;
const int button2 = 12;
const int button3 = 8;

// Menu options
String menu[] = {"Option 1", "Option 2", "Option 3", "Option 4"};
int count = 0; // Start count from 0

void setup() {
  // Initialize LCD
  lcd.begin(16, 2);

  // Set button pins as inputs
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  // Display initial menu option
  lcd.setCursor(0, 0);
  lcd.print("Menu");
  lcd.setCursor(0, 1);
  lcd.print(menu[count]);
}

void loop() {
  // Read button states
  int val1 = digitalRead(button1);
  int val2 = digitalRead(button2);
  int val3 = digitalRead(button3);

  // Check if button 1 is pressed
  if (val1 == HIGH) {
    delay(250);  // Debounce delay
    count++;
    if (count >= 4) {
      count = 0;  // Wrap around if count goes out of bounds
    }
    lcd.setCursor(0, 1);
    lcd.print(menu[count]);
  }

  // Check if button 2 is pressed
  if (val2 == HIGH) {
    delay(250);  // Debounce delay
    count--;
    if (count < 0) {
      count = 3;  // Wrap around if count goes negative
    }
    lcd.setCursor(0, 1);
    lcd.print(menu[count]);
  }

  // Check if button 3 is pressed
  if (val3 == HIGH) {
    delay(250);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Selected:");
    lcd.setCursor(0, 1);
    switch (count) {
      case 0:
        lcd.print("Option 1");
        break;
      case 1:
        lcd.print("Option 2");
        break;
      case 2:
        lcd.print("Option 3");
        break;
      case 3:
        lcd.print("Option 4");
        break;
    }
    delay(1000); // Delay to display the selected option
  }
}
