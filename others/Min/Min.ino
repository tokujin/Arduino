// Arduino + Sound WS
// 2011.11.26-27
//
// 01-1:Arduinoで音を出そう
// "音が鳴るサンプル"


//スピーカーのピンを９ピンにする
int speakerPin = 9;



void setup(){

  //スピーカーのピンを出力モードに  
  pinMode(speakerPin, OUTPUT);

}



void loop(){
  
  digitalWrite(speakerPin, HIGH);
  delayMicroseconds(200);

  digitalWrite(speakerPin, LOW);
  delayMicroseconds(200);

}
