#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define SSID ""
#define PASS ""
#define AUTH ""

#define analogicPin A0 // D6 = 12 
int selPin[] = { 4, 5, 16 }; // select pins on 4051 (D2, D1, D0)
float valorSensor = 0.0;
float luz = 0.0, temp = 0.0, umidade = 0.0;

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
  delay(300);
  Serial.println("Leitura do LDR");
  Serial.println(luz);
  Blynk.virtualWrite(13, luz);

  Serial.println("Leitura de temperatura");
  Serial.println(temp);
  Blynk.virtualWrite(14, temp);

  Serial.println("Leitura de umidade");
  Serial.println(umidade);
  Blynk.virtualWrite(12, umidade);
  for(int i = 0, count = 0; i < 10; i++, count++){
    if(count >= 3){
      count = 0;
    }
    switch(count){
        case 0: // LDR
          digitalWrite(selPin[0], HIGH); // 100 = Y4
          digitalWrite(selPin[1], LOW);
          digitalWrite(selPin[2], LOW);
          delay(100);
          luz += analogRead(analogicPin);
          break;
        case 1: //LM35
          digitalWrite(selPin[0], HIGH); // 110 = Y6
          digitalWrite(selPin[1], HIGH);
          digitalWrite(selPin[2], LOW);
          delay(100);
          valorSensor = float(analogRead(analogicPin));
          valorSensor = (( valorSensor/1024.0)*1000); // milivolts
          temp += valorSensor/10; // graus celsius
          break;
        case 2: // Soil Sensor
          digitalWrite(selPin[0], HIGH); // 111 = Y7
          digitalWrite(selPin[1], HIGH);
          digitalWrite(selPin[2], HIGH);
          delay(100);
          umidade += analogRead(analogicPin);
          break;
      } 
  }
  luz = luz/10;
  temp = temp/10;
  umidade = umidade/10; 
}


