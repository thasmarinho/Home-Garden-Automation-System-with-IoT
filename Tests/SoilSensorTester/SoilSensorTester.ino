#define rainPin A0
#define blueLED D3
#define redLED D1
// you can adjust the threshold value
int thresholdValue = 400;

void setup(){
  pinMode(rainPin, INPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, LOW);
  Serial.begin(9600);
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(rainPin);
  Serial.print(sensorValue);
  if(sensorValue < thresholdValue){
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


