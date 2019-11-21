#include<base.h> // includes base library
#include<Wire.h>

base Base(); // sets up the pins in the order: motor1, motor1, motor2, motor2, motor3, moto3, motor4, motor4

void setup() {
  Serial.begin(9600);


}

void loop() {
  Base.ler_bussola();
  //returns degrees

  //velocidade range: 0-100
  Base.andarfrente(tempo, velocidade);
  Base.andartras(tempo, velocidade);
  Base.andaresquerda(tempo, velocidade);
  Base.andardireita(tempo, velocidade);
  Base.rodar(angulo) //angulo entre -180 e 180
  Base.parar(tempo);
  Base.send(data); //data needs to be integer

}
