// T1ISTOR NPN
#define T1 16 //DO = 16
#define T2 5 //D1 = 5

void setup() {
  Serial.begin(9600);
  pinMode(T1, OUTPUT);
  pinMode(T2, OUTPUT);
}

void loop() {
  delay(4000);
  digitalWrite(T1, LOW);
  digitalWrite(T2, HIGH);
  Serial.println("T1 = LOW AND T2 = HIGH");
  delay(4000);
  digitalWrite(T1, HIGH);
  digitalWrite(T2, LOW);
  Serial.println("T1 = HIGH AND T2 = LOW");
}
