#include <Servo.h>

Servo myservo;              // create servo object to control a servo

int data = 0;               // variable to read from the serial port
int val = 0;

void setup()
{
  myservo.attach(9);        // attaches the servo on pin 8 to the servo object
  Serial.begin(9600);       // starts the serial Serial at 9600 bauds
}

void loop()
{
  if (Serial.available())   // if data is available to read
  {
    data = Serial.read();   // read it and store it in 'val'
    if(data < 200){
      val = data * 0.8;
  }else{
      val = data * 1.5;
    }
  myservo.write(val);      // sets the servo position according to value in val
  delay(8);                // waits for the servo to get there
}

}
