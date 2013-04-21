/* LEDの明るさ変更
   PWM制御の基礎
*/

const int led_pin = 11;
const int led_pin2 = 9;

void setup() {         
}

void loop() {
  for (int led_value = 0; led_value < 256; led_value += 50) {    
    analogWrite(led_pin, led_value);                             ．
    delay(10);                         
  }
  for (int led_value = 255; led_value > -1; led_value -= 10) {   
    analogWrite(led_pin, led_value);
    delay(20);
  }
  for (int led_value = 0; led_value < 256; led_value += 50) { 
    analogWrite(led_pin2, led_value);                            
    delay(20);                         
  }
  for (int led_value = 255; led_value > -1; led_value -= 10) { 
    analogWrite(led_pin2, led_value);
    delay(20);
  }
}
