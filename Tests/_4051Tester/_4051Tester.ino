// #define analogicPin 15 // D8 = 15
int selPin[] = { 4, 5, 16 }; // select pins on 4051 (D2, D1, D0)
void setup(){
  for(int pin = 0; pin < 3; pin++){ // setup select pins
    pinMode(selPin[pin], OUTPUT);
    digitalWrite(selPin[pin], LOW);
  } 
  Serial.begin(9600);
}

void loop() {
  digitalWrite(selPin[0], HIGH);
  digitalWrite(selPin[1], LOW);
  digitalWrite(selPin[2], LOW);
  Serial.print("Y4 ativo com 100 ?");
  delay(2000);
  digitalWrite(selPin[0], HIGH);
  digitalWrite(selPin[1], HIGH);
  digitalWrite(selPin[2], LOW);
  Serial.print("Y6 ativo com 110 ?");
  delay(2000);
}


