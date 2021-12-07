#include <dht.h>     
#define dht_dpin A0 	           //DHT 11 類比輸入 Pin A0  
dht DHT;   

String a;
String Sch_no = "555";

void setup(){  
  Serial.begin(9600);   
  delay(300);                                            //Let system settle   
  Serial.println("Humidity and temperature");   
  delay(700);                       //Wait rest of 1000ms recommended delay before   
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){   
  while(Serial.available()) {
    a = Serial.readString();// read the incoming data as string
    if (a == Sch_no) {
	  DHT.read11(dht_dpin); 
      Serial.print("Humidity = ");   
      Serial.print(DHT.humidity);   
      Serial.print("% ");   
      Serial.print("temperature = ");   
      Serial.print(DHT.temperature);   
      Serial.println("C ");   
      delay(1000);                                       //延遲 1000ms 
      digitalWrite(LED_BUILTIN, LOW);
    }
    else
      digitalWrite(LED_BUILTIN, HIGH); 
  }
} 
