/*
  base.h - Library for Controlling the base.
  Created by Roberto Figueiredo, June 18, 2019.
*/
#ifndef base_h
#define base_h

#include "Arduino.h"
#include "Servo.h"

class base
{
public:
    #define ADDRESS 0x60
    byte highByte, lowByte, fine;
    int bearing, pitch, roll;
    void ler_bussola();

    void andarfrente(int tempo);
    void andartras(int tempo);
    void rodarCW(int tempo);
    void rodarCCW(int tempo);
    void parar(int tempo);
    void rodarPublico();
    int motor1_1;
    int motor1_2;
    int motor2_1;
    int motor2_2;
    int motor3_1;
    int motor3_2;
    int motor4_1;
    int motor4_2;
    base(int motor1_1, int motor1_2, int motor2_1, int motor2_2, int motor3_1, int motor3_2, int motor4_1, int motor4_2);
  private:
    void writeToMotors(int vel1, int vel2, int vel3, int vel4, int vel5, int vel6, int vel7, int vel8);//check if this can be on private


};/*
class bracos
{
public:
  void
};
*/ //use same library for both just create separate classes for arms and base
#endif
