#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2 //Temp sensor
#define TEMP_NORM 25
#define RELAY_PIN 9

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x27,20,4);

 
void setup(void) 
{
  Serial.begin(9600);
  sensors.begin();

  pinMode(RELAY_PIN,OUTPUT); 
  
  lcd.init();
  lcd.backlight();

}

void loop() 
{  
  sensors.requestTemperatures(); 
  double temp = sensors.getTempCByIndex(0);

  lcd.setCursor(0,1); 
  lcd.print(temp); 
  lcd.setCursor(6,1); 
  lcd.print("Celsius"); 
  
  if(temp > TEMP_NORM){
    digitalWrite(RELAY_PIN,LOW);
  }else{
    digitalWrite(RELAY_PIN,HIGH);
  }
  
    
}
