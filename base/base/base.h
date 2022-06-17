/*
  base.h - Library for Controlling the base.
  Created by Roberto Figueiredo, June 18, 2019.
*/

#ifndef base_h
#define base_h
#include "Arduino.h"
#include "DFRobot_TCS34725.h"

//#include "Servo.h" // include if end up creating class for the arms
struct compass_values{
    double roll;
    double pitch;
    double angle16;
    double angle8;
  };
struct rgb_values{
    double red;
    double green;
    double blue;

  };
class Base
{
public:
    DFRobot_TCS34725 tcs = DFRobot_TCS34725(&Wire, TCS34725_ADDRESS,TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
    #define CMPS11_ADDRESS 0x60  // Address of CMPS11 shifted right one bit for arduino wire library
    #define ANGLE_8  1           // Register to read 8bit angle from
    compass_values compass;
    rgb_values rgb;
    unsigned char high_byte, low_byte, angle8;
    char pitch, roll;
    unsigned int angle16;

    //rgb sensor
    byte gammatable[256];
    struct rgb_values ler_rgb();
    //-------------------

  //bussola
    
    struct compass_values ler_bussola();
//-------------------
    //Base();
//funções movimento
    void andarfrente(int tempo, int vel);
    void andartras(int tempo, int vel);
    void andaresquerda(int tempo, int vel);
    void andardireita(int tempo, int vel);
    void rodarCW(int tempo);
    void rodarCCW(int tempo);
    void parar(int tempo=0);
    void rodarPublico();
//-------------------
    bool medir();
    int trigPin;
    int echoPin;
    long duration;
    int distance;
    int motor1_1;
    int motor1_2;
    int motor2_1;
    int motor2_2;
    int motor3_1;
    int motor3_2;
    int motor4_1;
    int motor4_2;
    int vel1;
    int vel2;
    int vel3;
    int vel4;
    int vel5;
    int vel6;
    int vel7;
    int vel8;
    Base(int motor1_1, int motor1_2, int motor2_1, int motor2_2, int motor3_1, int motor3_2, int motor4_1, int motor4_2);
    void writeToMotors(int vel1, int vel2, int vel3, int vel4, int vel5, int vel6, int vel7, int vel8);//check if this can be on private
    int convert(int vel);
    void StepUp(int vel);
  private:



};/*
class bracos
{
public:
  void
};
*/ //use same library for both just create separate classes for arms and Base
#endif
