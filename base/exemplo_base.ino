#include<base.h> // includes base library
#include<Wire.h>

base Base(13,12,11,10,9,8,7,6); // sets up the pins in the order: motor1, motor1, motor2, motor2, motor3, moto3, motor4, motor4

void setup() {
  Serial.begin(9600);


}

void loop() {
  Base.ler_bussola();
  //returns degrees

  //velocidade range: 0-100
  void andarfrente(tempo, velocidade);
  void andartras(tempo, velocidade);
  void andaresquerda(tempo, velocidade);
  void andardireita(tempo, velocidade);
  void rodarCW(tempo);
  void rodarCCW(tempo);
  void parar(tempo);
  void send(data); //data needs to be integer

}
