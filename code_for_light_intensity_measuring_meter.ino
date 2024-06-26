#include <Wire.h>
#include <BH1750.h>
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

BH1750 lightMeter;
   
void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  lightMeter.begin();
  Serial.println("Running...");
  Serial.println("Light Measuring Meter");
  lcd.print("Light Dectector");
}
   
 
void loop() {
  uint16_t lux = lightMeter.readLightLevel();
  lcd.setCursor(0, 1);
  lcd.print("Light: ");
  Serial.println("Light: ");
  lcd.print(lux);
  Serial.println(lux);
  lcd.print(" lx");
  Serial.println(" lx");
  delay(1000);
}
