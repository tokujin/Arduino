// "tlc_config.h"の値を下記に変更
//    #define NUM_TLCS    2

#include "Tlc5940.h"

#define MAX_BRIGHTNESS 4095

void setup() {
  Tlc.init();
}

void loop() {

  int myR = random(4)*(MAX_BRIGHTNESS/3);
  int myG = random(4)*(MAX_BRIGHTNESS/3);
  int myB = random(4)*(MAX_BRIGHTNESS/3);

  //channelの 0 と 31 は未接続
  for (TLC_CHANNEL_TYPE channel = 1; channel < (NUM_TLCS * 16)-2; channel += 3) {

    Tlc.clear();
    Tlc.set(channel + 0, myR);
    Tlc.set(channel + 1, myG);
    Tlc.set(channel + 2, myB);
    Tlc.update();
    delay(70);
  }
}
