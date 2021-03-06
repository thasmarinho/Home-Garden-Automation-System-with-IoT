#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define SSID ""
#define PASS ""
#define AUTH ""

#define analogicPin 0 
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
  Serial.println("Valor logico da saida: ");
  Serial.println(digitalRead(analogicPin));
  delay(2000);
}


