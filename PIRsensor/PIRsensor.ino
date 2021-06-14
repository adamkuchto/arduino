
int czujnik = 2;   //pin 8 połączony z sygnałem z czujnika
int led = 13;
void setup(){
  Serial.begin(9600);        //inicjalizacja monitora szeregowego
  pinMode(czujnik, INPUT);   //ustawienie pinu Arduino jako wejście
  
  Serial.println("---- TEST CZUJNIKA RUCHU ----"); 
}
 
void loop(){
  int ruch = digitalRead(czujnik);      //odczytanie wartości z czujnika
  if(ruch == HIGH)                      //wyświetlenie informacji na monitorze szeregowym
  {                                     //stan wysoki oznacza wykrycie ruchu, stan niski - brak ruchu
    Serial.println("RUCH WYKRYTY!");
    pinMode(led, LOW);
  }
  else 
  {Serial.println("brak ruchu");
   pinMode(led, HIGH);
  }
  
  delay(200);                         //opóźnienie między kolejnymi odczytami
}
