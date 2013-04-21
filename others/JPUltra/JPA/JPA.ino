//反射波の変数を用意
unsigned long echo = 0;
//信号ピンを９番ピンに設定
int signalPin = 9;

void setup(){
  //出力用にシリアル通信開始
  Serial.begin(9600);
}

void loop(){
  //まず信号ピンを出力に設定（発信用）
  pinMode(signalPin, OUTPUT);
  //２マイクロ秒間LOWで出力
  digitalWrite(signalPin, LOW);
  delayMicroseconds(2);
  //５マイクロ秒間HIGHで出力
  digitalWrite(signalPin, HIGH);
  delayMicroseconds(5);//超音波発信
  //信号ピンをLOWに戻す
  digitalWrite(signalPin, LOW);
  
  //信号ピンを入力に設定（受信用）
  pinMode(signalPin, INPUT);
  //信号ピンをHIGHに設定
  digitalWrite(signalPin, HIGH);
  //反射波が戻ってくるまでの時間を計測し
  //片道の時間（半分の値）にする
  echo = pulseIn(signalPin, HIGH)/2;
  //ミリメートル単位に変換
  int distance = echo*0.34442;

  //距離を出力
  Serial.println(distance);
  delay(250);
}
