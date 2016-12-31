#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define SSID "Erva_de_Gato"
#define PASS "gatos_negros_1234"
#define AUTH "5b7d55aed6064a0ab4ed9168afa68a65"
#define sensor  A0      //Pino analógico em que o sensor está conectado.
int valorSensor = 0; //Usada para ler o valor do sensor em valorSensoro real.

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
  valorSensor = (float(analogRead(sensor))*3.3/(1023))/0.01; // costance (1/1024*100)

  Blynk.virtualWrite(14, valorSensor);
  Serial.println(valorSensor);
  delay(2000);
}
