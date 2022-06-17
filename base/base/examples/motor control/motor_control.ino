#include<base.h> // includes base library
#include<Wire.h>

base Base(6,7,8,9,10,11,4,5);  // sets up the pins in the order: motor1, motor1, motor2, motor2, motor3, moto3, motor4, motor4

void setup() {
  Serial.begin(9600);
}

void loop() {
  Base.andarfrente(tempo, velocidade);
  Base.andartras(tempo, velocidade);
  Base.andaresquerda(tempo, velocidade);
  Base.andardireita(tempo, velocidade);
  Base.rodarCW(tempo);
  Base.rodarCCW(tempo); 
  Base.parar(tempo);

}
