const int pinChoque = 11;
const int buzzer = 10;
const int pinDerecha = 9;
const int pinIzquierda = 8;

int option;

void setup() 
{
   Serial.begin(9600);
   pinMode(pinChoque, OUTPUT);
   pinMode(buzzer, OUTPUT);
   pinMode(pinDerecha, OUTPUT);
   pinMode(pinIzquierda, OUTPUT);
}

void loop()
{

  if (Serial.available() > 0){
    option = Serial.read();
    if(option == 'C'){
      digitalWrite(pinChoque, HIGH);
      delay(500);
      digitalWrite(pinChoque, LOW);
    }
    else if(option == 'B'){
      tone(buzzer, 622.25, 300);
      delay(200);
      tone(buzzer, 493.88, 300);
      delay(100);
      tone(buzzer, 392, 300);
      delay(200);
      tone(buzzer, 349.23, 300);
      delay(100);
      tone(buzzer, 329.63, 300);
      delay(5000);
    }
    else if(option == 'W'){
      tone(buzzer, 262, 300);
      delay(350);
      tone(buzzer, 293, 300);
      delay(350);
      tone(buzzer, 329, 300);
      delay(350);
      tone(buzzer, 349, 300);
      delay(350);
    }
    else if(option == 'S'){
      tone(buzzer, 700, 100);
    }
    else if(option == 'D'){
      digitalWrite(pinDerecha, HIGH);
      delay(10);
      digitalWrite(pinDerecha, LOW);
    }
    else if(option == 'I'){
      digitalWrite(pinIzquierda, HIGH);
      delay(10);
      digitalWrite(pinIzquierda, LOW);
    }
  }
}
