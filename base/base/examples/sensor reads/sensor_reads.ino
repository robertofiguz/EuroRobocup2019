#include<base.h> // includes base library
#include<Wire.h>

Base base(6,7,8,9,10,11,4,5); // sets up the pins in the order: motor1, motor1, motor2, motor2, motor3, moto3, motor4, motor4

void setup() {
  Serial.begin(9600);
}

void loop() {
  base.compass = base.ler_bussola();
  Serial.print("roll:");
  Serial.println(base.compass.roll);

  base.rgb = base.ler_rgb();
  Serial.print("r:");
  Serial.print(base.rgb.red);
  Serial.print(" g:");
  Serial.print(base.rgb.green);
  Serial.print(" b:");
  Serial.println(base.rgb.blue);

  Serial.println(base.medir());
}
