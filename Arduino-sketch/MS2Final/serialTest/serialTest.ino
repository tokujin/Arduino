


int bytes[5];
int counter = 0;
int led = 11;

void setup(){
   Serial.begin(9600);
  
   pinMode(led, OUTPUT);
}

void loop(){
  
  if (Serial.available() > 0){
      
      int val = Serial.read();
      if (val == 255){
        counter = 0;     // skip this byte, it's the start byte;
         bytes[counter] = val;
          counter++;
      } else {
        if (counter < 5){
          bytes[counter] = val;
        }
        counter++;
      }
  }
  
  
  analogWrite(led,  bytes[4]);    
  
}
