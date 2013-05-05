/*
    This sketch sweeps a servo on channel 0.
    To connect a servo:
     1. Put a 2k-5k pull-up resistor (R0 below; I've tried with 3.3k) between the
          servo control output pin and +5v.
     2. Connect that same pin to the servo's control line like so
        servo data pin
              |     _____
     OUTn ----+----[_____]---+5v
                      R0
    Steve Pomeroy <steve ~AT~ staticfree.info>, 2009-01-20 */

#include "Tlc5940.h"
#include "tlc_servos.h"
#include <Firmata.h>

int numberOfServos = 104;

bool arr[104] = {false}; //data given by an array from OpenFrameworks via Firmata


#define DELAY_TIME 200
#define NUM_TLCS  7 // how many servos on the chain? "7 daisy chain"

void setup()
{
  tlc_initServos();  // Note: this will drop the PWM freqency down to 50Hz.    
}


void loop(){
  //loop through all the servos and move one at a time to 180º
     for (int angle = 0; angle < 180; angle+= 10) {
        for(int k=0; k<numberOfServos; k++){
          if(arr[k] == true){
            tlc_setServo(k, angle);
          }
        }
        Tlc.update();
        delay(20);
      }    
      delay(200);

    //loop through all the servos and move one at a time to 0º          
      for (int angle = 180; angle >= 0; angle-= 10) {
        for(int k=0; k<numberOfServos; k++){
          if(arr[k] == true){
            tlc_setServo(k, angle);
          }
        }
      Tlc.update();
      delay(20);
      }
      delay(200); 
}
