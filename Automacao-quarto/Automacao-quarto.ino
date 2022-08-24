#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

#include <Espalexa.h>
#include <LiquidCrystal.h>

//#define D0 0
//#define D1 5
#define D5 14
#define D8 12


const char* ssid = "TP-LINK_AF2E5C";
const char* password = "tinta54321";
const int rs = 5, en = 4, d4 = 0, d5 = 2, d6 = 13, d7 = 3;

Espalexa espAlexa;
//void Funcion_D0(uint8_t brightness);
//void Funcion_D1(uint8_t brightness);
void Funcion_D5(uint8_t brightness);
void Funcion_D8(uint8_t brightness);

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(115200);
  // pinMode(D0, OUTPUT);
 // pinMode(D1, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D8, OUTPUT);
 // digitalWrite(D1, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D8, LOW);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("QUARTO DE WALLAS");
  lcd.setCursor(0,1); 
  lcd.print("LUZ:");
  lcd.setCursor(4,1);
  lcd.print("OFF");
  lcd.setCursor(8,1);
  lcd.print("VENT:");
  lcd.setCursor(13,1);
  lcd.print("OFF");
  
  
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
    lcd.setCursor(4,1);
    lcd.print("ON ");
  }
  else {
    digitalWrite(D8, LOW);
    lcd.setCursor(4,1);
    lcd.print("OFF");
  }
}
// Função para o pin D5
void Funcion_D5(uint8_t brightness) {
  if (brightness) {
    digitalWrite(D5, HIGH);
    lcd.setCursor(13,1);
    lcd.print("ON ");
  }
  else {
    digitalWrite(D5, LOW);
    lcd.setCursor(13,1);
    lcd.print("OFF");
  }
}

void displayonoff(){
  const int n = 1;
  while(n == 1){
    lcd.noDisplay();
    delay(1000);
    lcd.display();
    delay(2000); 
  }
} 

 
