#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

#include <Espalexa.h>

//#define D0 0
//#define D1 5
#define D5 14
#define D8 15


const char* ssid = "********";
const char* password = "********";

Espalexa espAlexa;
//void Funcion_D0(uint8_t brightness);
//void Funcion_D1(uint8_t brightness);
void Funcion_D5(uint8_t brightness);
void Funcion_D8(uint8_t brightness);



void setup() {
  Serial.begin(115200);
  // pinMode(D0, OUTPUT);
 // pinMode(D1, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D8, OUTPUT);
 // digitalWrite(D1, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D8, LOW);

  ConectarWifi();
  //espAlexa.addDevice("D0", Funcion_D0);
  //espAlexa.addDevice("Motor", Funcion_D1);
  espAlexa.addDevice("Ventilador", Funcion_D5);
  espAlexa.addDevice("Luz", Funcion_D8);

  espAlexa.begin();
}

void loop() {
  ConectarWifi();
  espAlexa.loop();
  delay(1);
}

// Função para conectar com WIFI
void ConectarWifi() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.println("");
    Serial.println("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
}
// Função para o pin D8
void Funcion_D8(uint8_t brightness) {
  if (brightness) {
    digitalWrite(D8, HIGH);
  }
  else {
    digitalWrite(D8, LOW);
  }
}
// Função para o pin D5
void Funcion_D5(uint8_t brightness) {
  if (brightness) {
    digitalWrite(D5, HIGH);
  }
  else {
    digitalWrite(D5, LOW);
  }
}
// Função para o pin D1
//void Funcion_D1(uint8_t brightness) {
  //if (brightness) {
  //  digitalWrite(D1, HIGH);
//  }
//  else {
//    digitalWrite(D1, LOW);
//  }
//}
