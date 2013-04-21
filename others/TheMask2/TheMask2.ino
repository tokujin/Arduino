#include<stdio.h>
/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 */

int led1 = 11;           // the pin that the LED is attached to
int led2 = 10;
int brightness1 = 0;    // how bright the LED is
int brightness2 = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by


// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
} 

// the loop routine runs over and over again forever:
void loop()  { 
    // set the brightness of pin 9:
    analogWrite(led1, brightness1);    
  //  analogWrite(led2, brightness2);    
    // change the brightness for next time through the loop:
    brightness1 = brightness1 + fadeAmount;
    brightness2 = brightness2 + fadeAmount;
    
    // reverse the direction of the fading at the ends of the fade: 
    if (brightness1 == 0 || brightness1 == 255) {
      fadeAmount = -fadeAmount ;
      
    }
    delay(8);                            
}

