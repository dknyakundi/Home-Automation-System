#include <Servo.h>  

int servopin=9;
int servopos=0;

//give my servo a name
Servo dkServo;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
dkServo.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("What angle for the servo?");
  while (Serial.available()==0){
  }
  servopos = Serial.parseInt();
dkServo.write(servopos);
}
