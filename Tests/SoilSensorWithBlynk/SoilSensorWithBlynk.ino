#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define rainPin A0
#define blueLED D3
#define redLED D1
#define SSID ""
#define PASS ""
#define AUTH ""

long lastConnectionTime;
int minUmidadeSolo = 80; // 0 -- 100

void FazConexaoWiFi(void)
{ 
    delay(1000);
    Blynk.begin(AUTH, SSID, PASS);
    delay(1000);
}
float FazLeituraUmidade(void)
{
    int ValorADC;
    float UmidadePercentual;
 
     ValorADC = analogRead(0);   //418 -> 1.0V
 
     //Quanto maior o numero lido do ADC, menor a umidade.
     //Sendo assim, calcula-se a porcentagem de umidade por:
     //      
     //   Valor lido                 Umidade percentual
     //      _    0                           _ 100
     //      |                                |   
     //      |                                |   
     //      -   ValorADC                     - UmidadePercentual 
     //      |                                |   
     //      |                                |   
     //     _|_  418                         _|_ 0
     //
     //   (UmidadePercentual-0) / (100-0)  =  (ValorADC - 418) / (-418)
     //      Logo:
     //      UmidadePercentual = 100 * ((418-ValorADC) / 418)  
      
     UmidadePercentual = 100 * ((418-(float)ValorADC) / 418);
     return UmidadePercentual;
}
void sendUptime()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(12, FazLeituraUmidade()); // virtual pin V12
}
void setup(){
  pinMode(rainPin, INPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, LOW);
  Serial.begin(9600);
  lastConnectionTime = 0; 
  FazConexaoWiFi(); 
}

void loop() {
  Blynk.run();
  // read the input on analog pin 0:
  int sensorValue = FazLeituraUmidade();
  Serial.print(sensorValue);
  Blynk.virtualWrite(12, sensorValue);
  if(sensorValue < minUmidadeSolo){
    Serial.println(" - Doesn't need watering");
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, HIGH);
  }
  else {
    Serial.println(" - Time to water your plant");
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, LOW);
  }
  delay(500);
}


