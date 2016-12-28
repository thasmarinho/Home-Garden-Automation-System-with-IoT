#define trans 16 //DO = 16

void setup() {
  Serial.begin(9600);
  pinMode(trans, OUTPUT);
}

void loop() {
  delay(4000);
  digitalWrite(trans, LOW);
  Serial.println("trans = LOW");
  delay(4000);
  digitalWrite(trans, HIGH);
  Serial.println("trans = HIGH");
}
