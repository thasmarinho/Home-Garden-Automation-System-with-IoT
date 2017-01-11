
#define sensor  A0      //Pino analógico em que o sensor está conectado.
int valorSensor = 0; //Usada para ler o valor do sensor em valorSensoro real.


//Função setup, executado uma vez ao ligar o Arduino.
void setup(){
  //Ativando o serial monitor que exibirá os valores lidos no sensor.
  Serial.begin(9600);
  pinMode(sensor, INPUT); 
  loop();
}
 
//Função loop, executado enquanto o Arduino estiver ligado.
void loop(){
 
  //Lendo o valor do sensor.(
  valorSensor = float(analogRead(sensor)); 
  valorSensor = (( valorSensor/1024.0)*5000)/10;
  Serial.println(valorSensor);
  delay(2000);
}
