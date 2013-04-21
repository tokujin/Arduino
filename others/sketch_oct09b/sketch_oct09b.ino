int sensorPin = A0; //select the input pin for the potentiometer
int ledPin = 13; //select the pin for the LED
int sensorValue = 0; //variable to store the value coming from the
int newSensorValue;

void setup(){
  //declare the ledPIN as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}


void loop(){
  //read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  //turn the ledPIN on
  newSensorValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(ledPin, newSensorValue);
  
Serial.print(newSensorValue);
}
 
