#include <ESP8266WiFi.h>
 
//const char* ssid = "Diva's Home";
//const char* password = "DIVA1234";

const char* ssid = "Semestapot_home";
const char* password = "jujur1234";
 
int D0_atasPin = 16; // GPIO16
int D1_tengahPin = 5; // GPIO5
int D2_bawahPin = 4; // GPIO4
int D3_kananatasPin = 0; // GPIO0
int D4_kananbawahPin = 2; // GPIO2
int D5_kiriatasPin = 14; // GPIO14
int D6_kiribawahPin = 12; // GPIO12
int D7_lampuhijauPin = 13; // GPIO13
int D8_lampukuningPin = 15; // GPIO15

int CekSistem = 0;

//int RX_GPIO3Pin = 3; // GPIO3
//int TX_GPIO1Pin = 1; // GPIO1

void setup() {
  Serial.begin(9600);
  delay(100);
 
  pinMode(D0_atasPin, OUTPUT);
  pinMode(D1_tengahPin, OUTPUT);
  pinMode(D2_bawahPin, OUTPUT);
  pinMode(D3_kananatasPin, OUTPUT);
  pinMode(D4_kananbawahPin, OUTPUT);
  pinMode(D5_kiriatasPin, OUTPUT);
  pinMode(D6_kiribawahPin, OUTPUT);
  pinMode(D7_lampuhijauPin, OUTPUT);
  pinMode(D8_lampukuningPin, OUTPUT);

  digitalWrite(D7_lampuhijauPin, LOW);
  
  digitalWrite(D0_atasPin, LOW);
  digitalWrite(D1_tengahPin, LOW);
  digitalWrite(D2_bawahPin, LOW);
  digitalWrite(D3_kananatasPin, LOW);
  digitalWrite(D4_kananbawahPin, LOW);
  digitalWrite(D5_kiriatasPin, LOW);
  digitalWrite(D6_kiribawahPin, LOW);

}

void loop() {
    delay(500);
    //Serial.print(".");
    digitalWrite(D8_lampukuningPin, HIGH);
    delay(500);  
    digitalWrite(D8_lampukuningPin, LOW);
}

