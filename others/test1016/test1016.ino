void setup() {
// initialize the digital pin as an output.
// Pin 13 has an LED connected on most Arduino boards:
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
}

void loop() {
digitalWrite(13, HIGH);   // set the LED on
digitalWrite(12, LOW);
delay(1000);              // wait for a second
digitalWrite(13, LOW);    // set the LED off
digitalWrite(12, HIGH);
delay(1000);              // wait for a second
}
