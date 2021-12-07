#include <Wire.h>  // Arduino IDE 內建
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // 設定 LCD I2C 位址

void setup() {
  Serial.begin(115200);  // 用於手動輸入文字
  lcd.begin(16, 2);      // 初始化 LCD，一行 16 的字元，共 2 行，預設開啟背光

  // 閃爍三次
  for(int i = 0; i < 3; i++) {
    lcd.backlight(); // 開啟背光
    delay(250);
    lcd.noBacklight(); // 關閉背光
    delay(250);
  }
  lcd.backlight();
  // 輸出初始化文字
  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
  lcd.print("Hello, world!");
  delay(1000);
  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
  lcd.print("GTWang.org");
  delay(8000);

  // 告知使用者可以開始手動輸入訊息
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Use Serial Mon");
  lcd.setCursor(0, 1);
  lcd.print("Type to display");
}
void loop() {
  // 當使用者手動輸入訊息
  if (Serial.available()) {
    // 等待一小段時間，確認資料都接收下來了
    delay(100);
    // 清除舊訊息
    lcd.clear();
    // 讀取新訊息
    while (Serial.available() > 0) {
      // 將訊息顯示在 LCD 上
      lcd.write(Serial.read());
    }
  }
}
