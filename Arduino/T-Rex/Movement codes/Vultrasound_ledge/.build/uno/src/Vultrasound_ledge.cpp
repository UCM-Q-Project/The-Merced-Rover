#include <Arduino.h>
#include <Servo.h>	//import servo
void setup();
void loop();
#line 1 "src/Vultrasound_ledge.ino"
//#include <Servo.h>	//import servo

int trigPin_forward = 6;  //Forward Sensor Trig pin connected to Arduino pin 6
int echoPin_forward = 7;  //Forward Sensor Echo pin connected to Arduino pin 7 
//int trigPin_ledge = 4;	  //Ledge Sensor Trig pin connected to Arduino pin 4
//int echoPin_ledge = 11;	  //Ledge Servo Echo pin connected to Arduino pin 11

float pingTime_forward;  //time for ping to travel from sensor to target and return
float targetDistance_forward; //Distance to Target in inches
//float pingTime_ledge;
//float targetDistance_ledge;

float speedOfSound=34300;  //Speed of sound in meters per second at sea level

Servo sRight;		//declare right servo
Servo sLeft;		//declare left servo

int sRight_stop = 1515; 	//current calibration for Right servo to stop
int sLeft_stop = 1525;		//current calibration for Left servo to stop
int sRight_fullForward = 1300;	//full forward speed for Right servo
int sLeft_fullForward = 1700;	//full forward speed for Left servo

void setup() {
  sRight.attach(12);
  sLeft.attach(13);
  
  sLeft.writeMicroseconds(sRight_stop);  	//current calibration for Left servo to stop
  sRight.writeMicroseconds(sLeft_stop);	//current calibration for Right servo to stop

  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin_forward, OUTPUT);
  pinMode(echoPin_forward, INPUT);
//  pinMode(trigPin_ledge, OUTPUT);
  //pinMode(echoPin_ledge, INPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(trigPin_forward, LOW); //Set trigger pin low
  //digitalWrite(trigPin_ledge, LOW);
  delayMicroseconds(2000); //Let signal settle

  digitalWrite(trigPin_forward, HIGH); //Set trigPin high
  //digitalWrite(trigPin_ledge,HIGH);
  delayMicroseconds(15); //Delay in high state

  digitalWrite(trigPin_forward, LOW); //ping has now been sent
  //digitalWrite(trigPin_ledge, LOW);
  delayMicroseconds(10); //Delay in low state
  
  
  pingTime_forward = pulseIn(echoPin_forward, HIGH);  //pingTime is presented in microceconds
  pingTime_forward = pingTime_forward/1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
 // pingTime_ledge = pulseIn(echoPin_ledge, HIGH);
  //pingTime_ledge = pingTime_ledge/1000000;
 //Serial.write(pingTime_ledge);


  targetDistance_forward = speedOfSound * pingTime_forward; //speed of sund is in cm/s
  targetDistance_forward = targetDistance_forward/2; //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
  //targetDistance_ledge = speedOfSound * pingTime_ledge;
  //targetDistance_ledge = targetDistance_ledge/2;

  if(targetDistance_forward >25 /*&& targetDistance_ledge < 5*/){
 	sRight.writeMicroseconds(sRight_fullForward);
	sLeft.writeMicroseconds(sLeft_fullForward);
  }
  if(targetDistance_forward <= 25 /*|| targetDistance_ledge >= 5*/){
  	sRight.writeMicroseconds(sRight_stop);
	sLeft.writeMicroseconds(sLeft_stop);
  }

  Serial.write("Forward: ");
  Serial.print(targetDistance_forward);
  Serial.write(" centimeters");
  Serial.println();
/*
  Serial.write("Ledge: ");
  Serial.print(targetDistance_ledge);
  Serial.write(" centimeters");
  Serial.println();
  */
  delay(100); //delay tenth of a  second to slow things down a little.
}

