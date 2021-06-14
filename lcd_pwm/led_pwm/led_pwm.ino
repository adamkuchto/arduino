#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#define blue 5
#define green 6
#define red 7
int pot = 0;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x20, 16, 2);
void setup()
{
  Serial.begin(9600);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop()
{
  pot = analogRead(A5);
  for (int i = 1; i <= 3; i++)
  {
    if (i == 1)
    {

      digitalWrite(blue, HIGH);
      // lcd.setCursor(0, 4);
      Serial.println("blue");
      delay(pot);
      digitalWrite(blue, LOW);
    }
    else if (i == 2)
    {

      digitalWrite(green, HIGH);
      Serial.println("green");
      delay(pot);
      digitalWrite(green, LOW);
    }
    else if (i == 3)
    {

      digitalWrite(red, HIGH);
      Serial.println("red");
      delay(pot);
      digitalWrite(red, LOW);
    }
  }
  // delay(500);
}