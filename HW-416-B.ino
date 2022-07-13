
int pirPin = 2;
int ledPin = 8;
int motion;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  motion = digitalRead(pirPin);

  if(motion==1){
    Serial.println("Motion detected");
    digitalWrite(ledPin, HIGH);
  }
  else{
    Serial.println("No motion detected");
    digitalWrite(ledPin, LOW);
  }
delay(500);
}

