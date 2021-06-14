#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16,2);

int trigPin = 9;
int echoPin = 8;

float duration_us, distance_cm;

void setup() {
  lcd.init();
  lcd.backlight();
  /***********************/
  Serial.begin (9600);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
}

void loop() {
  
  
  digitalWrite (trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite (trigPin, LOW);

  duration_us = pulseIn (echoPin, HIGH);
  distance_cm = 0.017 * duration_us;

  Serial.print ("\nOdległość: \n ");
  Serial.print(distance_cm);
  Serial.print (" cm");

  /*************************************/
  
  if(distance_cm > 20);
  {
    
    lcd.setCursor (2,1);
    lcd.print ("STOP!");
    
    
  }
  
  /************************************/
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance_cm);
  
  delay(1100);

}
