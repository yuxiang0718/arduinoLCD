#include <Wire.h>  // Arduino IDE ����
#include <LiquidCrystal_I2C.h>
#include <dht.h>     
#define dht_dpin A0 

dht DHT; 
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // �]�w LCD I2C ��}

void setup() {
  Serial.begin(115200);  // �Ω��ʿ�J��r
  lcd.begin(16, 2);      // ��l�� LCD�A�@�� 16 ���r���A�@ 2 ��A�w�]�}�ҭI��

  // �{�{�T��
  for(int i = 0; i < 3; i++) {
    lcd.backlight(); // �}�ҭI��
    delay(250);
    lcd.noBacklight(); // �����I��
    delay(250);
  }
  lcd.backlight();
  // ��X��l�Ƥ�r
  lcd.setCursor(0, 0); // �]�w��Ц�m�b�Ĥ@��歺
  lcd.print("Hello, world!");
  delay(1000);
  lcd.setCursor(0, 1); // �]�w��Ц�m�b�ĤG��歺
  lcd.print("GTWang.org");
  delay(8000);

  // �i���ϥΪ̥i�H�}�l��ʿ�J�T��
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Use Serial Mon");
  lcd.setCursor(0, 1);
  lcd.print("Type to display");
}
void loop() {
    DHT.read11(dht_dpin);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NO : 123456789");
    lcd.setCursor(0, 1);
    lcd.print("H=");
    lcd.print(DHT.humidity);
    lcd.print(" t=");
    lcd.print(DHT.temperature); 
    delay(1000);   
}
