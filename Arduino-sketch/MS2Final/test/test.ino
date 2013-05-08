//From the bildr article: http://bildr.org/2012/03/servos-tlc5940-arduino
//Requires the Tlc5940 library. http://code.google.com/p/tlc5940arduino/downloads/list

#include "Tlc5940.h"
#include "tlc_servos.h"

int numberOfServos = 1; //how many servos on the chain?
int r[3];

void setup(){
  tlc_initServos();  // Note: this will drop the PWM freqency down to 50Hz.
}

void loop(){
  r[0] = 1;
  
  //loop through all the servos and move one at a time to 180º

    for (int angle = 0; angle < 180; angle+= 10) {
      for(int k=0; k<numberOfServos; k++){
        tlc_setServo(0, angle);
      }
        Tlc.update();
        delay(20);
      }

    delay(200);
  

  //loop through all the servos and move one at a time to 0º


    for (int angle = 180; angle >= 0; angle-= 10) {
      for(int k=0; k<numberOfServos; k++){
        tlc_setServo(0, angle);
      }
        Tlc.update();
        delay(20);
      }

    delay(200);
}
