void setup() {
  pinMode(A5,OUTPUT);
  

}

void loop() {
    tone(A5, 659.3); // 329,6  659.3
    delay(500);
    noTone(A5);
    
   tone(A5, 740.0);  // 370,0  740.0
    delay(300);
    noTone(A5);
    
     tone(A5, 784.0); // 392,0  784.0
     delay(300);
    noTone(A5);
    
  tone(A5, 740.0);  // 370,0  740.0
   delay(500);
    noTone(A5);
    tone(A5, 659.3);  // 329,6  659.3
    delay(300);
    noTone(A5);
    tone(A5, 587.3);  // 293,7  587.3
     delay(300);
    noTone(A5);
    
     tone(A5, 659.3); // 329,6  659.3
    delay(1000);
    noTone(A5);
    
    tone(A5, 659.3);  // 329,6  
    delay(1000);
    noTone(A5);
    delay(2000);
 
}

/*
 * E    tone(A5, 659.3,2000);
 * FIS  tone(A5, 740.0,2000);
 * G    tone(A5, 784.0,2000);
 * FIS  tone(A5, 740.0,2000);
 * E    tone(A5, 659.3,2000);
 * D    tone(A5, 587.3,2000);
 * E    tone(A5, 659.3,2000);
 * E    tone(A5, 659.3,2000);
 * 
  E
  FIS
  G
  A
  G
  A
  H
  G

  E
  FIS
  G
  A
  G
  A
  E

  E
  FIS
  G
  A
  G
  FIS
  E
  D
  E
  E
  

 */
