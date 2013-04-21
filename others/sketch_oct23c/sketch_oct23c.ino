int pinCount = 6;           // the number of pins (i.e. the length of the array)

unsigned long currentTime;
unsigned long loopTime;
int ledPins[] = { 
  2, 7, 4, 6, 5, 3 };       // an array of pin numbers to which LEDs are attached

void setup(){

  currentTime = millis(); //Both currentTime and loopTime start off as the same
  loopTime = currentTime; //Current time is updated in the main loop, then
  Serial.begin(9600); //Then compared to loopTime
  int thisPin;
  // the array elements are numbered from 0 to (pinCount - 1).
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
    pinMode(ledPins[thisPin], OUTPUT);      
  }

}

void loop(){

  currentTime = millis();
  if(currentTime >= (loopTime + 1000)){
    loopTime = currentTime; //Updates loop time
    Serial.print("The currentTime is ");
    Serial.println(currentTime);
    if(currentTime==1000){
      digitalWrite(ledPins[0],HIGH);
    }
    if(currentTime==2000){
      digitalWrite(ledPins[2],HIGH);
    }
    if(currentTime==3000){
      digitalWrite(ledPins[2],HIGH);

    }
    if(currentTime==4000){
      digitalWrite(ledPins[3],HIGH);

    }
    if(currentTime==3000){
      digitalWrite(ledPins[4],HIGH);

    }
    if(currentTime==6000){
      digitalWrite(ledPins[5],HIGH);
    }
      currentTime==1000;
}


