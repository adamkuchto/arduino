#include <OneWire.h>
#include <Wire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h> 
#define ONE_WIRE_BUS (2);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x20, 16, 2);
//************
int czujnik = A1;
void setup()
  {
    Serial.begin(9600);
    sensors.begin();
    lcd.init();
    lcd.backlight();
    //**********
    pinMode(13, OUTPUT);
  }
void loop()
  { 
    sensors.requestTemperatures();
  Serial.print(sensors.getTempCByIndex(0)); //dokladnosc wyswietlania temp
  Serial.println("C"); 
    delay(500);
    lcd.setCursor(2, 0);
     lcd.print("TEMPERATURA:");
     lcd.setCursor(2, 1);
     lcd.print(sensors.getTempCByIndex(0),1);
     lcd.setCursor(9,1);
     lcd.print("st. C");
//***************
    int war = analogRead(czujnik);
    Serial.print(war);
    if (war > 600)
    {
      Serial.print(" dioda on" );
      digitalWrite (13,HIGH);
    }
    else
    {
      digitalWrite(13,LOW);
    }
      Serial.println("");
      delay(200);         
  }
