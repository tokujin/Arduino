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

int numberOfServos = 104;
int bytes[16];
int counter = 0;

int arr[104]; //data given by an array from OpenFrameworks


#define DELAY_TIME 200
#define NUM_TLCS  7 // how many servos on the chain? "7 daisy chain"

void setup()
{
  Serial.begin(9600);
  tlc_initServos();  // Note: this will drop the PWM freqency down to 50Hz.    
}


void loop(){
  //loop through all the servos and move one at a time to 180º
  
  
  for(int i= 0; i < 104; i++){
    arr[i] = 0;
  }

  if (Serial.available() > 0){
      int val = Serial.read();
      if (val == 255){
        counter = 0;     // skip this byte, it's the start byte;
         bytes[counter] = val;
          counter++;
      } else {
        if (counter < 16){
          bytes[counter] = val;
        }
        counter++;
      }
  
  }
  
  //convert data
  for (int i = 0;  i< 15; ++i){
		for (int j = 0; j < 7; ++j){
			if((bytes[i+1] >> j) & 0x00000001){
				arr[i*7+j] = 1;
			}else{
				arr[i*7+j] = 0;
			}
		}
	}

        for(int k=0; k<numberOfServos; k++){
          for(int l=0; l < 5;l++){
          if(arr[k] == true){
            tlc_setServo(k, 90);
          }else{
            tlc_setServo(k, 90-18*l);
          }
        }
        }
        Tlc.update();
    


//     for (int angle = 0; angle < 180; angle+= 10) {
//        for(int k=0; k<numberOfServos; k++){
//          if(arr[k] == true){
//            tlc_setServo(k, angle);
//          }
//        }
//        Tlc.update();
//        delay(20);
//      }    
//      delay(200);
//
//    //loop through all the servos and move one at a time to 0º          
//      for (int angle = 180; angle >= 0; angle-= 10) {
//        for(int k=0; k<numberOfServos; k++){
//          if(arr[k] == true){
//            tlc_setServo(k, angle);
//          }
//        }
//      Tlc.update();
//      delay(20);
//      }
//      delay(200); 


}
