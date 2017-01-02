#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define SSID ""
#define PASS ""
#define AUTH ""

#define analogicPin 12 // D6 = 12 
int selPin[] = { 4, 5, 16 }; // select pins on 4051 (D2, D1, D0)

void FazConexaoWiFi(void)
{ 
    delay(1000);
    Blynk.begin(AUTH, SSID, PASS);
    delay(1000);
}
void setup(){
  for(int pin = 0; pin < 3; pin++){ // setup select pins
    pinMode(selPin[pin], OUTPUT);
    digitalWrite(selPin[pin], LOW);
  } 
  digitalWrite(analogicPin, INPUT);
  Serial.begin(9600);
  FazConexaoWiFi();
}

void loop() {
  Blynk.run();
  for(int pin = 0; pin < 3; pin++){
    switch(pin){
      case 0: // LDR
        digitalWrite(selPin[0], HIGH); // 100 = Y4
        digitalWrite(selPin[1], LOW);
        digitalWrite(selPin[2], LOW);
        Blynk.virtualWrite(13, analogicPin);
        Serial.println("Y4 com SELECT=100 ?");
        Serial.println(digitalRead(analogicPin));
        delay(1000);
        break;
      case 1: //LM35
        digitalWrite(selPin[0], HIGH); // 110 = Y6
        digitalWrite(selPin[1], HIGH);
        digitalWrite(selPin[2], LOW);
        Blynk.virtualWrite(14, analogicPin);
        Serial.println("Y6 com SELECT=110 ?");
        Serial.println(digitalRead(analogicPin));
        delay(1000);
        break;
      case 2: // Soil Sensor
        digitalWrite(selPin[0], HIGH); // 111 = Y7
        digitalWrite(selPin[1], HIGH);
        digitalWrite(selPin[2], HIGH);
        Blynk.virtualWrite(12, analogicPin);
        Serial.println("Y7 com SELECT=111 ?");
        Serial.println(digitalRead(analogicPin));
        delay(1000);
        break;
    } 
  }
}


