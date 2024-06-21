#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
 
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

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
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
   
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

 
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
    digitalWrite(D8_lampukuningPin, HIGH);
    delay(500);  
    digitalWrite(D8_lampukuningPin, LOW);
  }

  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(".");
    digitalWrite(D8_lampukuningPin, HIGH);
    delay(500);  
    digitalWrite(D8_lampukuningPin, LOW);
    ESP.restart();
    return; 
  } else {
    delay(500);
    //Serial.print("+");  
    digitalWrite(D8_lampukuningPin, HIGH);  
  }
  
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(500);
  }
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);

  client.flush();

  if (request.indexOf("/on") != -1){
      digitalWrite(D7_lampuhijauPin, HIGH); 
      client.print("Sistem hidup !!");
      CekSistem = 1;
  } else if (request.indexOf("/off") != -1){
      digitalWrite(D7_lampuhijauPin, LOW);
      client.print("Sistem mati !!");
      CekSistem = 0;
      digitalWrite(D0_atasPin, LOW);
      digitalWrite(D1_tengahPin, LOW);
      digitalWrite(D2_bawahPin, LOW);
      digitalWrite(D3_kananatasPin, LOW);
      digitalWrite(D4_kananbawahPin, LOW);
      digitalWrite(D5_kiriatasPin, LOW);
      digitalWrite(D6_kiribawahPin, LOW);
  }

  if (CekSistem == 1){
    if (request.indexOf("/nomor=0") != -1){
      nol();
        client.print("nol !!");
    } else if (request.indexOf("/nomor=1") != -1) {
      satu();
      client.print("Satu !!");
    } else if (request.indexOf("/nomor=2") != -1) {
      dua();
      client.print("Dua !!");
    } else if (request.indexOf("/nomor=3") != -1) {
      tiga();
      client.print("Tiga !!");
    } else if (request.indexOf("/nomor=4") != -1) {
      empat();
      client.print("Empat !!");
    } else if (request.indexOf("/nomor=5") != -1) {
      lima();
      client.print("Lima !!");
    } else if (request.indexOf("/nomor=6") != -1) {
      enam();
      client.print("Enam !!");
    } else if (request.indexOf("/nomor=7") != -1) {
      tujuh();
      client.print("Tujuh !!");
    } else if (request.indexOf("/nomor=8") != -1) {
      delapan();
      client.print("Delapan !!");
    } else if (request.indexOf("/nomor=9") != -1) {
      sembilan();
      client.print("Sembilan !!");
    }
    
  }
  
}


void nol () {
  digitalWrite(D0_atasPin, HIGH);
  digitalWrite(D1_tengahPin, LOW);
  digitalWrite(D2_bawahPin, HIGH);
  digitalWrite(D3_kananatasPin, HIGH);
  digitalWrite(D4_kananbawahPin, HIGH);
  digitalWrite(D5_kiriatasPin, HIGH);
  digitalWrite(D6_kiribawahPin, HIGH);
    
}

void satu () {
  digitalWrite(D0_atasPin, LOW);
  digitalWrite(D1_tengahPin, LOW);
  digitalWrite(D2_bawahPin, LOW);
  digitalWrite(D3_kananatasPin, HIGH);
  digitalWrite(D4_kananbawahPin, HIGH);
  digitalWrite(D5_kiriatasPin, LOW);
  digitalWrite(D6_kiribawahPin, LOW);
    
}

void dua () {
  digitalWrite(D0_atasPin, HIGH);
  digitalWrite(D1_tengahPin, HIGH);
  digitalWrite(D2_bawahPin, HIGH);
  digitalWrite(D3_kananatasPin, HIGH);
  digitalWrite(D4_kananbawahPin, LOW);
  digitalWrite(D5_kiriatasPin, LOW);
  digitalWrite(D6_kiribawahPin, HIGH);
    
}

void tiga () {
  digitalWrite(D0_atasPin, HIGH);
  digitalWrite(D1_tengahPin, HIGH);
  digitalWrite(D2_bawahPin, HIGH);
  digitalWrite(D3_kananatasPin, HIGH);
  digitalWrite(D4_kananbawahPin, HIGH);
  digitalWrite(D5_kiriatasPin, LOW);
  digitalWrite(D6_kiribawahPin, LOW);
    
}

void empat () {
  digitalWrite(D0_atasPin, LOW);
  digitalWrite(D1_tengahPin, HIGH);
  digitalWrite(D2_bawahPin, LOW);
  digitalWrite(D3_kananatasPin, HIGH);
  digitalWrite(D4_kananbawahPin, HIGH);
  digitalWrite(D5_kiriatasPin, HIGH);
  digitalWrite(D6_kiribawahPin, LOW);
    
}

void lima () {
  digitalWrite(D0_atasPin, HIGH);
  digitalWrite(D1_tengahPin, HIGH);
  digitalWrite(D2_bawahPin, HIGH);
  digitalWrite(D3_kananatasPin, LOW);
  digitalWrite(D4_kananbawahPin, HIGH);
  digitalWrite(D5_kiriatasPin, HIGH);
  digitalWrite(D6_kiribawahPin, LOW);
    
}

void enam () {
  digitalWrite(D0_atasPin, HIGH);
  digitalWrite(D1_tengahPin, HIGH);
  digitalWrite(D2_bawahPin, HIGH);
  digitalWrite(D3_kananatasPin, LOW);
  digitalWrite(D4_kananbawahPin, HIGH);
  digitalWrite(D5_kiriatasPin, HIGH);
  digitalWrite(D6_kiribawahPin, HIGH);
    
}

void tujuh () {
  digitalWrite(D0_atasPin, HIGH);
  digitalWrite(D1_tengahPin, LOW);
  digitalWrite(D2_bawahPin, LOW);
  digitalWrite(D3_kananatasPin, HIGH);
  digitalWrite(D4_kananbawahPin, HIGH);
  digitalWrite(D5_kiriatasPin, LOW);
  digitalWrite(D6_kiribawahPin, LOW);
    
}

void delapan () {
  digitalWrite(D0_atasPin, HIGH);
  digitalWrite(D1_tengahPin, HIGH);
  digitalWrite(D2_bawahPin, HIGH);
  digitalWrite(D3_kananatasPin, HIGH);
  digitalWrite(D4_kananbawahPin, HIGH);
  digitalWrite(D5_kiriatasPin, HIGH);
  digitalWrite(D6_kiribawahPin, HIGH);
    
}

void sembilan () {
  digitalWrite(D0_atasPin, HIGH);
  digitalWrite(D1_tengahPin, HIGH);
  digitalWrite(D2_bawahPin, HIGH);
  digitalWrite(D3_kananatasPin, HIGH);
  digitalWrite(D4_kananbawahPin, HIGH);
  digitalWrite(D5_kiriatasPin, HIGH);
  digitalWrite(D6_kiribawahPin, LOW);
    
}