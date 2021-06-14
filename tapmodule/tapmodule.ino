int led = 13; // LED pin
int knocksignal = 2; // magnetic senso rpin
int switchState; // variable to store reel switch value

void setup() 
{
  Serial.begin(9600);
  pinMode (led, OUTPUT);
  pinMode (knocksignal, INPUT);
}

void loop()
{
  switchState = digitalRead(knocksignal); // read the value of digital interface 2 and assign it to switchState
  
  if (switchState == HIGH) // when the tap modle detect a signal, LED is flashing
  {
    Serial.println("OFF");
    
    digitalWrite(led, LOW);
    
  }
  else 
  {
    Serial.println("ON");
    
    digitalWrite(led, HIGH);
  }

}
