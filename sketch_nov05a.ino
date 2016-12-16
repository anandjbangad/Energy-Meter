#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

unsigned int counter = 0;
boolean present = 0,past = 0;

void setup() {
  pinMode(14,INPUT);
  
  lcd.begin(16, 2);
  lcd.print("Energy Meter"); 
  
}

void loop() {
  
 lcd.setCursor(0,1);
 delay(37000);
 lcd.print('1');
 lcd.setCursor(0,1);
 delay(37000);
 lcd.setCursor(0,1);
 lcd.print('2');
 delay(37000);
 lcd.setCursor(0,1);
 lcd.print('3');
delay(37000);
lcd.setCursor(0,1);
 lcd.print('4');
delay(37000);
lcd.setCursor(0,1);
 lcd.print('5');
 delay(37000);
lcd.setCursor(0,1);
 lcd.print('6');
 delay(37000);



}

 
 
  

 
  

 

