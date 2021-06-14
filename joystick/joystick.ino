//u mnie dla położenia centralnego ADC zwraca 503 i 521
const int x_mid=503;
const int y_mid=521;
//ustawiamy histerezę - tylko po przekroczeniu tej wartości od centrum będziemy cokolwiek robić
const int center_hist=5;

void setup()
{
  Serial.begin(9600);//ustawiamy port szeregowy do komunikacji z komputerem
  
  pinMode(A3, INPUT);//ustawiamy pin A3 jako wejście pod przycisk i włączamy podciąganie
  digitalWrite(A3, HIGH);
  pinMode(A4, INPUT);//piny A4 i A5 ustawiam jako wejścia - podepniemy tam odpowiednio osie X i Y joysticka
  pinMode(A5, INPUT);
}


void loop()
{
  int x=analogRead(A4);//odczytamy wartości napięć dla osi X i Y
  int y=analogRead(A5);
  
  if(x>(x_mid+center_hist)||x<(x_mid-center_hist)){//jeśli joystick jest wychylony poza połozenie neutralne
    x=(x-x_mid)/16;//przeliczmy jego położenie i zmniejszmy liczbę możliwych stanów (512/16=32)
    //uwaga - z powodu realizacji dzielenia w języku C otrzymamy niesymetryczny zakres - jeśli to nam przeszkadza możemy za pomocą instrukcji if dokonać obcięcia niesymetrycznej wartości) 
  }else x=0;
  
  if(y>(y_mid+center_hist)||y<(y_mid-center_hist)){//to samo dla osi Y
    y=(y-y_mid)/16;
  }else y=0;
  
  Serial.print(x);//wyświetlamy je
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.println(digitalRead(A3));//i na koniec przycisk
}
