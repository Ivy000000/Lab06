#define do1 261
#define re1 294
#define me1 329
#define fa1 349
#define so1 392
#define la1 440
#define si1 493

#define do2 523
#define re2 587
#define me2 659
#define fa2 698
#define so2 784
#define la2 880
#define si2 988

#define do3 1046
#define re3 1175
int tune[] = {do1,re1,me1,fa1,so1,la1,si1,do2,re2,me2,fa2,so2,la2,si2,do3,re3};
#include<Keypad.h>
const byte KEY_ROWS = 4; // 4 Rows
const byte KEY_COLS = 4; // 4 Columns // 定義 Keypad 的按鍵

char keys[KEY_ROWS][KEY_COLS] = {
  {'F', 'E', 'D', 'C'},
  {'B', '3', '6', '9'},
  {'A', '2', '5', '8'},
  {'0', '1', '4', '7'}}; // 定義 Keypad 連到 Arduino 的接腳
byte colPins[KEY_COLS] = {6,5,4,3};	   // 按鍵模組，行1~4接腳。
byte rowPins[KEY_ROWS] = {10,9,8,7};       // 按鍵模組，列1~4接腳。
// 建立 Keypad 物件
Keypad keypad = Keypad(makeKeymap(keys), rowPins,colPins,KEY_ROWS, KEY_COLS );
void setup(){
Serial.begin(9600);
}
void loop(){
char key = keypad.getKey(); // 讀取 Keypad
  if(key != NO_KEY){
    if(key>='A'&&key<='F')
    {
      Serial.println(key);
      tone(13, tune[key-'A'+10]);
      delay(100);
      noTone(13);
    }
    else
    {
      Serial.println(key);
      tone(13, tune[key-'0']);
      delay(100);
      noTone(13); 
  }
  }
}
