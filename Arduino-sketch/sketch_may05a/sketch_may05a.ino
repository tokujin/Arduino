/*
 * Arduino establishes a Serial Communication
 * to send and receive two Bytes (16 Bit) i.e. from a Java Programm
 * 
 * done by Laurid Meyer
 * 28.04.2012
 * 
 * http://www.lauridmeyer.com
 */
 
#include <Servo.h> 
//Settings
int servoPin=9;

Servo myservo;

void setup(){
  Serial.begin(9600);//start the Serial
  myservo.attach(servoPin);  // attache the servo on the givven servoPin
}

int oldPotiValue=0;


void loop(){
    int curPotiValue = analogRead(A0);//reads the Poti
    //checks if the value of the poti has changed +-2
    if(curPotiValue>(oldPotiValue+2) || curPotiValue<(oldPotiValue-2)){
         send2bytes(curPotiValue);
         oldPotiValue=curPotiValue;
    }
   
    int recieved=recieve2bytes();//call method recieve2bytes and store the result
    if(recieved>=0){//if an integer was recieved
        //map the recieved values (in this case 0...1023) to the degrees our servo can move 0...179
        recieved = map(recieved, 0, 1023, 0, 179);
        myservo.write(recieved);
    }
    delay(10);
}

//Methods converts an integer to two bytes and sends them via the serial
void send2bytes(int value)
{
    //send both bytes
    Serial.write(value & 0xFF);
    Serial.write((value >> 8) & 0xFF);
}

//Method checks for incoming data in the serial
//and converts the frist two Bytes into an integer
int recieve2bytes()
{
    if(Serial.available() > 2)
    {
        union{
          int i;
          byte b[2];
        } v;
        //paste the 2 bytes into the union
        v.b[0] = Serial.read();
        v.b[1] = Serial.read();
        return v.i;//reutrn the integer
    }else{
        return -1;
    }
}
