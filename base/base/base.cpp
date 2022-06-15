/*
  base.cpp - Library for Controlling the base.
  Created by Roberto Figueiredo, June 18, 2019.
*/

#include "Arduino.h"
#include "base.h"
#include "Wire.h"
#include "Ultrasonic.h"

Base::Base(int motor1_1, int motor1_2, int motor2_1, int motor2_2, int motor3_1, int motor3_2, int motor4_1, int motor4_2)
{
   
    Serial.begin(19200);
    
    trigPin = A3;
    echoPin = A2;
    Wire.begin();
    pinMode(motor1_1, OUTPUT);  // motor 1
    pinMode(motor1_2, OUTPUT);  // motor 1

    pinMode(motor2_1, OUTPUT);  // motor 2
    pinMode(motor2_2, OUTPUT);  // motor 2

    pinMode(motor3_1, OUTPUT);  // motor 3
    pinMode(motor3_2, OUTPUT);  // motor 3

    pinMode(motor4_1, OUTPUT);  // motor 4
    pinMode(motor4_2, OUTPUT);  // motor 4

    pinMode(trigPin,OUTPUT);
    pinMode(echoPin, INPUT);
//if omni is defenitive define motors here
    
}

//void Base::bracos(){

//}

bool Base::medir(){

  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor

  if (distance<40){
    return true;
  }
  else{
    return false;
  }

}

void Base::writeToMotors(int vel1, int vel2, int vel3, int vel4, int vel5, int vel6, int vel7, int vel8){
//check if i can delete this
  motor1_1= 5;
  motor1_2 = 4;
  motor2_1 = 11;
  motor2_2 = 10;
  motor3_1 = 9;
  motor3_2 = 8;
  motor4_1 = 7;
  motor4_2 = 6;
/////////////////////

//insert code for initial propultion to get lower speeds

  analogWrite(motor1_1,vel1);
  analogWrite(motor1_2, vel2);

  analogWrite(motor2_1,vel3);
  analogWrite(motor2_2,vel4);

  analogWrite(motor3_1,vel5);
  analogWrite(motor3_2, vel6);

  analogWrite(motor4_1,vel7);
  analogWrite(motor4_2,vel8);

}

int Base::convert(int vel){
  vel = map(vel, 0, 100, 0, 255);
  return(vel);
}


void Base::StepUp(int vel){
  int x = 0;
  while(x<vel){
    int velSetUp = 100-x;
        writeToMotors(velSetUp,0,velSetUp,0,velSetUp,0,velSetUp,0);
        x++;
        //probably working - needs testing
  }

}


void Base::andarfrente(int tempo, int vel)
{
    vel = convert(vel);
    //StepUp(vel);

    writeToMotors(vel,0,vel,0,vel,0,vel,0);
    Serial.println("andar");
    delay(tempo); //check if this kinf of delay works, create variable for time
    Serial.println("parar");
    parar();
} 

void Base::andartras(int tempo, int vel)
{
    convert(vel);
    writeToMotors(0,vel,0,vel,0,vel,0,vel);
    delay(tempo); //check if this kinf of delay works, create variable for time
}

void Base::andaresquerda(int tempo, int vel)
{
  convert(vel);
  writeToMotors(vel,0,0,vel,0,vel,vel,0);
  delay(tempo);
}

void Base::andardireita(int tempo, int vel)
{
  convert(vel);
  writeToMotors(0,vel,vel,0,vel,0,0,vel);
  delay(tempo);
}
void Base::rodarCW(int tempo)
{
  //change code for compass and create variable for degrees and use while
  writeToMotors(0,150,150,0,0,150,150,0);
  delay(tempo);
   //delay(tempo); //check if this kinf of delay works, create variable for time
}


void Base::rodarCCW(int tempo)
{
  //change code for compass and create variable for degrees and use while
  writeToMotors(150,0,0,150,150,0,0,150);
  delay(tempo);


}

void Base::parar(int tempo)
{
  //change code for compass and create variable for degrees and use while
  if (tempo == 0){
    writeToMotors(0,0,0,0,0,0,0,0);
  }else{
    writeToMotors(0,0,0,0,0,0,0,0);
    delay(tempo);
  }
  
}



void Base::rodarPublico()
{
//  //change code for compass and create variable for degrees and use while
//    ler_bussola();
//    if(bearing<200 || bearing>220){
//    while(bearing<200 || bearing>220)  // Enquanto o robô estiver desalinhado   ||->ou lógico   &&->e lógico (valor inicial)
// {
//   rodarCW(100);//ver se e este ou rodar CCW
//   ler_bussola();        //Ler a bússola
// }
//}else if (bearing<0 || bearing>40){
//  while(bearing<0 || bearing>40)  // Enquanto o robô estiver desalinhado   ||->ou lógico   &&->e lógico (valor inicial)
//{
// rodarCCW(100);//ver se e este ou rodar CCW
// ler_bussola();        //Ler a bússola
//}
//}

  Serial.println(0);
}



struct compass_values Base::ler_bussola()
{
  Wire.beginTransmission(CMPS11_ADDRESS);  //starts communication with CMPS11
  Wire.write(ANGLE_8);                     //Sends the register we wish to start reading from
  Wire.endTransmission();
  // Request 5 bytes from the CMPS11
  // this will give us the 8 bit bearing, 
  // both bytes of the 16 bit bearing, pitch and roll
  Wire.requestFrom(CMPS11_ADDRESS, 5);       
  while(Wire.available() < 5){
  };        // Wait for all bytes to come back
  
  angle8 = Wire.read();               // Read back the 5 bytes
  high_byte = Wire.read();
  low_byte = Wire.read();
  pitch = Wire.read();
  roll = Wire.read();
  
  angle16 = high_byte;                 // Calculate 16 bit angle
  angle16 <<= 8;
  angle16 += low_byte;
    
  compass.roll = roll;
  compass.pitch = pitch;
  compass.angle16 = angle16;
  compass.angle8 = angle8;    
  return compass;
}

struct rgb_values Base::ler_rgb()
{
  if (!tcs.begin()) {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  };
  uint16_t clear, red, green, blue;
  tcs.getRGBC(&red, &green, &blue, &clear);
  tcs.lock();  // turn off LED
  // Figure out some basic hex code for visualization

  uint32_t sum = clear;

  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;

  rgb.red = r;
  rgb.green = g;
  rgb.blue = b;
  return rgb;
}