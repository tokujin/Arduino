int ultraSoundSignal = 7; // Ultrasound signal pin
int val = 0;
int ultrasoundValue = 0;
int timecount = 0; // Echo counter
int ledPin = 13; // LED connected to digital pin 13
int prntInteger;

void setup() {
 beginSerial(9600);                  // Sets the baud rate to 9600
 pinMode(ledPin, OUTPUT);            // Sets the digital pin as output
}

void loop() {
timecount = 0;
val = 0;
pinMode(ultraSoundSignal, OUTPUT); // Switch signalpin to output

/* Send low-high-low pulse to activate the trigger pulse of the sensor
* -------------------------------------------------------------------
*/

digitalWrite(ultraSoundSignal, LOW); // Send low pulse
delayMicroseconds(2); // Wait for 2 microseconds
digitalWrite(ultraSoundSignal, HIGH); // Send high pulse
delayMicroseconds(5); // Wait for 5 microseconds
digitalWrite(ultraSoundSignal, LOW); // Holdoff

/* Listening for echo pulse
* -------------------------------------------------------------------
*/

pinMode(ultraSoundSignal, INPUT); // Switch signalpin to input
val = digitalRead(ultraSoundSignal); // Append signal value to val
while(val == LOW) { // Loop until pin reads a high value
 val = digitalRead(ultraSoundSignal);
}

while(val == HIGH) { // Loop until pin reads a high value
 val = digitalRead(ultraSoundSignal);
 timecount = timecount +1;            // Count echo pulse time
}

/* Writing out values to the serial port
* -------------------------------------------------------------------
*/

ultrasoundValue = timecount; // Append echo pulse time to ultrasoundValue

serialWrite('A'); // Example identifier for the sensor
Serial.print(ultrasoundValue);
serialWrite(10);
serialWrite(13);

/* Lite up LED if any value is passed by the echo pulse
* -------------------------------------------------------------------
*/

if(timecount > 0){
 digitalWrite(ledPin, HIGH);
}

/* Delay of program
* -------------------------------------------------------------------
*/

delay(100);
} 

