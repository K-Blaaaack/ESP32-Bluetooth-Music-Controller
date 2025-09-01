#include <BleKeyboard.h>

BleKeyboard bleKeyboard("ESP32 BleMusic Switcher");

// 定义引脚
const int PIN_NEXT = 18;
const int PIN_PREV = 19;
const int PIN_PLAY_PAUSE = 21;
const int PIN_MEDIA_VOLUME_UP = 16;
const int PIN_MEDIA_VOLUME_DOWN = 17;
const int PIN_MEDIA_MUTE = 5;

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 BleMusic Switcher,Starting BLE work!");
  bleKeyboard.begin();

  // 设置按键输入模式（使用内置上拉电阻）
  pinMode(PIN_NEXT, INPUT_PULLUP);
  pinMode(PIN_PREV, INPUT_PULLUP);
  pinMode(PIN_PLAY_PAUSE, INPUT_PULLUP);
  pinMode(PIN_MEDIA_VOLUME_UP, INPUT_PULLUP);
  pinMode(PIN_MEDIA_VOLUME_DOWN, INPUT_PULLUP);
  pinMode(PIN_MEDIA_MUTE, INPUT_PULLUP);
}

void loop() {
  if (bleKeyboard.isConnected()) {

    if (digitalRead(PIN_NEXT) == LOW) {
      Serial.println("Next track/上一首");
      bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
      delay(500); // 防止连续触发
    }

    if (digitalRead(PIN_PREV) == LOW) {
      Serial.println("Previous track/下一首");
      bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
      delay(500);
    }

    if (digitalRead(PIN_PLAY_PAUSE) == LOW) {
      Serial.println("Play/Pause/播放/暂停");
      bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
      delay(500);
    }

    if (digitalRead(PIN_MEDIA_VOLUME_UP) == LOW) {
      Serial.println("Volume Up/音量+");
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
      delay(500);
    }

    if (digitalRead(PIN_MEDIA_VOLUME_DOWN) == LOW) {
      Serial.println("Volume Down/音量-");
      bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
      delay(500);
    }

    if (digitalRead(PIN_MEDIA_MUTE) == LOW) {
      Serial.println("Mute/静音");
      bleKeyboard.write(KEY_MEDIA_MUTE);
      delay(500);
    }
  }

  delay(50); // 小延迟防抖与节省资源
}
