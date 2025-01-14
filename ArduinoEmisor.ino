// Arduino pin numbers
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
const int sw_pin = 2; //analog pin connected to switch input
const int tiempo_delay = 50; // Tiempo de delay despues de una lectura

int Left;
int Rigth;
int Up;
int Down;

int switchState;
int Direccion;

void setup() {
  Serial.begin(9600);
  pinMode(sw_pin, INPUT);
  //El boton va a estar encendido, a menos de que se presione
  digitalWrite(sw_pin, HIGH);
}

void loop() {
  //650
  if(analogRead(X_pin)>650){
    Rigth = 1;
  }else{
    Rigth = 0;
  }
  //350
  if(analogRead(X_pin)<350){
    Left = 1;
  }else{
    Left = 0;
  }
 
   if (digitalRead(sw_pin) == HIGH){
     
      if(Up==0 && Down==0 && Rigth==1 && Left==0)
      {
        Direccion = 2; //DERECHA
        //Serial.println("DERECHA");
        Serial.println(Direccion);
        delay(tiempo_delay);
      }
 
      if(Up==0 && Down==0 && Rigth==0 && Left==1)
      {
        Direccion = 4; //IZQUIERDA
        //Serial.println("IZQUIERDA");
        Serial.println(Direccion);
        delay(tiempo_delay);
      }
    }
    else{
      switchState = 5;
      Serial.println(switchState);
      delay(tiempo_delay);
    }
 
}
