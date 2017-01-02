#define analogicPin 14 // D5 = 14
int selPin[] = { 4, 5, 16 }; // select pins on 4051 (D2, D1, D0)

void setup(){
  for(int pin = 0; pin < 3; pin++){ // setup select pins
    pinMode(selPin[pin], OUTPUT);
    digitalWrite(selPin[pin], LOW);
  } 
  digitalWrite(analogicPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(selPin[0], HIGH);
  digitalWrite(selPin[1], LOW);
  digitalWrite(selPin[2], LOW);
  Serial.println("Y4=1 com SELECT=100 ?");
  Serial.println(digitalRead(analogicPin));
  Serial.println("Partiu proximo! ");
  delay(2000);
  digitalWrite(selPin[0], HIGH);
  digitalWrite(selPin[1], HIGH);
  digitalWrite(selPin[2], LOW);
  Serial.println("Y6=0 com SELECT=110 ?");
  Serial.println(digitalRead(analogicPin));
  Serial.println("Partiu proximo! ");
  delay(2000);
}


