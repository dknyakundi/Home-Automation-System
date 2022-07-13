#include <RTClib.h> 
#include <Servo.h>  


// Instance of the class for RTC
RTC_DS1307 rtc;
Servo dkServo;

int CurrentHour;
int CurrentMinute;

// lights on time
const int ONlightH = 18;
const int ONlightM =30;
const int OFFlightH = 21;
const int OFFlightM = 00;

const int lights = 2;

//drawing curtains
int open = 180;
int close = 0;

int servopin = 9;

const int ONcurtH = 8;
const int ONcurtM =00;
const int OFFcurtH = 18;
const int OFFcurtM = 00;



void setup() {
  Serial.begin(9600);
  rtc.begin();
   pinMode(lights, OUTPUT);

  // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  dkServo.attach(servopin);    
 
}
void loop() {
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
    digitalWrite(lights,HIGH);
    Serial.println("LIGHTS ON");
    }
if((CurrentHour==OFFcurtH) && (CurrentMinute == OFFcurtM)){
      digitalWrite(lights,LOW);
      Serial.println("LIGHTS OFF");
    }
   
}