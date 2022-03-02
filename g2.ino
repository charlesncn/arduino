
#include <LiquidCrystal.h>


const int LM = A0;
const int motor = 13;
const int Red = 12;
const int Green = 11;


LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Automated Plant");
  lcd.setCursor(0,1);
  lcd.print("Watering System!");
  delay(2000);
  lcd.clear();
  lcd.print("Temp= ");
  lcd.setCursor(0,1);
  lcd.print("Pump= ");
}
void loop() {
  int value = analogRead(LM);
  float Temperature = value * 500.0 / 1023.0;
  lcd.setCursor(6,0);
  lcd.print(Temperature); 
  lcd.setCursor(11,1);
  

  if (Temperature > 24){
    lcd.print("ON ");
  }
  else {
    digitalWrite(Green, HIGH);
    lcd.print("OFF");
  }
  
   delay(1000);
}
