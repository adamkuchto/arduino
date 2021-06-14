// program do obsługi sterownika wrapper //24_11_2020_ zmniejszenie wartosci pwm //zatwierdzone Kuba,Adam,Junior,ja
//jako odsuwacza kubków w rom      MUG15
#define lewopwm 9
#define prawopwm 10     // napiecie na silnik prezuwajacy
#define outpwm 11       //napiecie na silownik

#define wejscie 2       //sygnał z elektroniki przesun pas 

#define czujnik_a 3     //czujnik optyczny przed przesunieciem
#define czujnik_b 4     //czunik optyczny po przesunięciu
#define stan_awaria 5   // podłączenie do czujnika ciśnienia




void setup() {
  //wyjscia
pinMode(lewopwm, OUTPUT); 
pinMode(prawopwm, OUTPUT);
pinMode(outpwm, OUTPUT);
 // wejscia
pinMode(wejscie, INPUT_PULLUP);
pinMode(czujnik_a, INPUT_PULLUP);
pinMode(czujnik_b, INPUT_PULLUP);
pinMode(stan_awaria, INPUT_PULLUP);

}

void loop() {
  
if(!digitalRead(stan_awaria)){
   while(!digitalRead (wejscie)){                                                             //jeżeli pojawi się sygnał z wyjścia 29 pre4(na silnik -29 podłączone do IN1 +)
      if((!digitalRead (czujnik_b))&&(!digitalRead(wejscie))){                                //*w tym przypadku - jeżeli w tym czasie jest sygnał na IN4 (przekaznik z czujnika optycznego
      analogWrite(prawopwm,140);                                                              //            nr 2 -kubek znajduje się również po prawej stronie)
                                                                                              // załącz silnik pasa transmisyjnego ze zredukowaną mocą
      
    
    while((!digitalRead (wejscie))||(!digitalRead(czujnik_b))||(!digitalRead(czujnik_a))){    //i dopuki sygnał z elektroniki,przycisku wysuwania pasa oraz czujnika kubka z prawej strony 
                                                                                              //          trzymaj ten stan w zamkniętej pętli
    }
      analogWrite(prawopwm,0);                                                                //kiedy wszystkie czujniki są nieaktywne  - wyłącz silnik pasa transmisyjnego
      delay(200);  
      }                                                                                       // koniec warunku
    if((digitalRead(czujnik_b))&&(!digitalRead(wejscie))){                                    //*w tym przypadku brak jest sygnału z czunika prawego kubka (IN4) i pojawia się sygnał z 
      digitalWrite (outpwm,HIGH);                                                             // elektroniki wyjścia - 29 pre4 (IN1) 
                                                                                              // podaj napięcie na siłownik przesuwający kubek i czekaj 900 ms
      delay(900);
      //while((digitalRead (czujnik_b))){
       
      //}
      while ((!digitalRead (wejscie))){                                                       //jeżeli w tym czasie z jakiejś przyczyny pojawi się sygnał z wejścia IN1 co oznacza ze jest 
        analogWrite(prawopwm,140);                                                            // tam kubek   nie pozwól na schowanie siłownika przesuwającego dopuki przeszkoda nie zostanie
        delay(1000);                                                                          // usunięta (sygnał z elektroniki pre4 nr 29- musi  być 0)
        analogWrite(prawopwm,0);
      }
      
      digitalWrite (outpwm,LOW);                                                              // jezeli wszystko ok  wyzeruj wyjscie na siłownik 
    }
   
      
    
   }                                                                                          // koniec programu obsługującego  wywołanie z wejście IN1
 while(!digitalRead(czujnik_a)){                                                              //w przypadku naciśniecia  przycisku IN3 , uruchom pas transmisyjny
  analogWrite(prawopwm,140);
 }
analogWrite(prawopwm,0);                                                                      //w każdym innym przypadku wyłącz silnik pasa transmisyjnego

 
}
else{
       while ((!digitalRead (wejscie))||(!digitalRead(czujnik_a))){                                                       //jeżeli w tym czasie z jakiejś przyczyny pojawi się sygnał z wejścia IN1 co oznacza ze jest 
        analogWrite(prawopwm,140); 
       }
        analogWrite(prawopwm,0);
}

}
