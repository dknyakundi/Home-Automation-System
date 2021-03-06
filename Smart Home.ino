#include <RTClib.h> 
#include <Servo.h>  
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


RTC_DS1307 rtc;
Servo dkServo;
LiquidCrystal_I2C lcd(0x27, 16, 2); 

//variables for pins
int servopin = 9;
const int lights = 2;
int photopin = A0;
int lamp = 10;
int pirPin = A1;
int ledPin = 4;

//LM35
int val;
int sensor=A2;
int readval;
int del=500;
int red=7;
float mv;
float cel;

int i;

int photoval;

int CurrentHour;
int CurrentMinute;

//delays
int delr = 15;
int delp = 250;

// lights on time
const int ONlightH = 22;
const int ONlightM =44;
const int OFFlightH = 22;
const int OFFlightM = 45;


//drawing curtains
int open = 180;
int close = 0;


const int ONcurtH = 22;
const int ONcurtM =44;
const int OFFcurtH = 22;
const int OFFcurtM = 45;



void setup() {
  Serial.begin(9600);
  rtc.begin();
   pinMode(lights, OUTPUT);

   //initialize LCD 
lcd.begin();
lcd.backlight();
   

  //following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  dkServo.attach(servopin); 

  pinMode(photopin,INPUT);
  pinMode(lamp, OUTPUT); 
  digitalWrite(lamp, LOW);

  pinMode(pirPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  pinMode(sensor,INPUT);
  pinMode(red,OUTPUT);

attachInterrupt(0, lightON, RISING);
 
}

void lightON(){
digitalWrite(pirPin, HIGH);
for(int i =0; i <= 1000; i++){
  delay(100);
}
digitalWrite(pirPin, LOW);
}


void loop() {
//LCD welcome message
lcd.setCursor(1, 0); 
  lcd.print("Congratulations"); 
  lcd.setCursor(1, 1);
  lcd.print("to you");

 DateTime now = rtc.now();

   // Save check in time;
    CurrentHour = now.hour();
    CurrentMinute = now.minute();

  Serial.println(CurrentHour);
  Serial.println(CurrentMinute);

    //security lights
  if((CurrentHour==ONlightH) && (CurrentMinute == ONlightM)){
    digitalWrite(lights,HIGH);
    Serial.println("LIGHTS ON");
    }
if((CurrentHour==OFFlightH) && (CurrentMinute == OFFlightM)){
      digitalWrite(lights,LOW);
      Serial.println("LIGHTS OFF");
    }

//curtains
 if((CurrentHour==ONcurtH) && (CurrentMinute == ONcurtM)){
    for (i=0; i<= 180; i+= 1)
        {
           dkServo.write(i);             
           delay(delr);                     
        }
        
    Serial.println("LIGHTS ON");
    }

if((CurrentHour==OFFcurtH) && (CurrentMinute == OFFcurtM)){
      for (i=180; i>=0; i-= 1) 
        { 
           dkServo.write(i);            
           delay(delr);                    
        }
      Serial.println("LIGHTS OFF");
      i=0;
    }
  delay(500); 

  // security lights:
photoval = analogRead(photopin);
Serial.println(photoval);
delay(delp);

if(photoval>90){
digitalWrite(lamp,LOW);
}
if(photoval<90){
  digitalWrite(lamp,HIGH);
}

//lm35
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