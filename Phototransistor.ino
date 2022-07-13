//variables:
int photopin = A0;
int photoval;
int del = 250;
int lamp = 9;

void setup() {

pinMode(photopin,INPUT);
pinMode(lamp, OUTPUT);
Serial.begin(9600);

}


void loop() {
  // security lights:
photoval = analogRead(photopin);
Serial.println(photoval);
delay(del);

if(photoval>90){
digitalWrite(lamp,LOW);
}
if(photoval<90){
  digitalWrite(lamp,HIGH);
}


}
