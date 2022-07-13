
int pirPin= A0;
int ledPin;
void setup() {
  // put your setup code here, to run once:
  pinMode(pirPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  attachInterrupt(0, lightON, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void lightON(){
digitalWrite(pirPin, HIGH);
for(int i =0; i <= 1000; i++){
  delay(100);
}
digitalWrite(pirPin, LOW);
}
