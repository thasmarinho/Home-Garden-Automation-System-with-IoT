#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define SSID ""
#define PASS ""
#define AUTH ""
#define sensor  A0      //Pino analógico em que o sensor está conectado.
int valorSensor = 0; //Usada para ler o valor do sensor em tempo real.

void FazConexaoWiFi(void)
{ 
    delay(1000);
    Blynk.begin(AUTH, SSID, PASS);
    delay(1000);
}
//Função setup, executado uma vez ao ligar o Arduino.
void setup(){
  //Ativando o serial monitor que exibirá os valores lidos no sensor.
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  FazConexaoWiFi(); 
  loop();
}
 
//Função loop, executado enquanto o Arduino estiver ligado.
void loop(){
  Blynk.run();
  //Lendo o valor do sensor.
  int valorSensor = analogRead(sensor);

  Blynk.virtualWrite(13, valorSensor);
  Serial.println(valorSensor);

}
