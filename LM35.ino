int val;
int sensor=A0;
int readval;
int del=500;
int red=7;
float mv;
float cel;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor,INPUT);
  pinMode(red,OUTPUT);
  
Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
val=analogRead(readval);
mv=(val/1024.0)*5000;
cel=mv/10;
Serial.println(cel);
delay(del);

if (val>48){
  digitalWrite(red,HIGH);
}

if (val<48){
  digitalWrite(red,LOW);
}
}









LCM 1602
