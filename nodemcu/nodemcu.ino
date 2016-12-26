/* NodeMCU and Blynk App*/   
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define SSID "Erva_de_Gato"
#define PASS "gatos_negros_1234"
#define AUTH "5b7d55aed6064a0ab4ed9168afa68a65"

/* TIMER */
#include <SimpleTimer.h>
SimpleTimer timer;

/* DHT11 */
#include "DHT.h"
#define DHTPIN 7 //D7 = GPIO13
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
float hum = 0, temp = 0; 

void FazConexaoWiFi(void)
{ 
    delay(100);
    Blynk.begin(AUTH, SSID, PASS);
    delay(100);
}

void setup()
{
  Serial.begin(9600);
  FazConexaoWiFi(); 
    // Setup a function to be called every second
  timer.setInterval(1000L, sendUptime);
}

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendUptime()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(10, dht.readTemperature()); //virtual pin
  Blynk.virtualWrite(11, dht.readHumidity()); // virtual pin 
}

void loop()
{
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer
  int chk; 
  chk = dht.read(DHTPIN);    // READ DATA
}
