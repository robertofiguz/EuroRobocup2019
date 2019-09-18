#include<base.h> // includes base library
base Base(13,12,11,10,9,8,7,6); // sets up the pins in the order: motor1, motor1, motor2, motor2, motor3, moto3, motor4, motor4
 
void setup() {
  

}

void loop() {
  //Base.rodarPublico(); //checks the compass to see where it is pointing and rotates accordingly 
  Base.medir();
  if(Base.medir()){
    Base.andarfrente(1000, 100); //function(delay)
    Base.parar(5000,50);//function(delay)
    Base.andartras(1000,100); //function(delay)
    Base.rodarCW(1000);
    Base.rodarCCW(1000);
    Base.andardireita(1000,100);
    Base.andaresquerda(1000,100);
    
  }
   
}



