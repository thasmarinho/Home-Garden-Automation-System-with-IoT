/* NodeMCU and Blynk App*/
#define BLYNK_PRINT Serial    
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define SSID "Erva_de_Gato"
#define PASS "gatos_negros_1234"
#define AUTH "5b7d55aed6064a0ab4ed9168afa68a65"

/* DHT11 */
#include "DHT.h"
#define DHTPIN D3  
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
float hum = 0, temp = 0; 

/* TIMER */
#include <SimpleTimer.h>
SimpleTimer timer;

/* Soil Moister */
#define soilMoisterPin A0
#define soilMoisterVcc D4
int soilMoister = 0;


void FazConexaoWiFi(void);
float FazLeituraUmidade(void);

void FazConexaoWiFi(void)
{ 
    delay(1000);
    Blynk.begin(AUTH, SSID, PASS);
    delay(1000);
}

void setup()
{
  Serial.begin(9600);
  pinMode(D7, OUTPUT);
  FazConexaoWiFi(); 
}
