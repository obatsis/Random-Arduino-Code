#include <LiquidCrystal.h> // gia na sviso mia mono grammi tha grapso kena se oli ti seira

#define D7 2  //#define = const int
#define D6 3
#define D5 4
#define D4 5
#define EN 6
#define RS 7

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello World");  
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);  //sec=millis()/1000
  delay(15);

  
}
