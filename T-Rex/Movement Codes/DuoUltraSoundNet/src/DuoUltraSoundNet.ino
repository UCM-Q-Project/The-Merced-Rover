#include <Servo.h>	
#include "../lib/QueueArray.h"

int trigPin_R = 3; 
int echoPin_R = 4;  
int echoPin_L = 10;
float pingTime;  //time for ping to travel from sensor to target and return
float targetDistance; //Distance to Target in centimeters
float aveDist;
float speedOfSound=34300;  //Speed of sound in centimeters per second at sea level

Servo sRight;		//declare right servo
Servo sLeft;		//declare left servo
QueueArray<float> queue;

int sRight_stop = 1515; 	//current calibration for Right servo to stop
int sLeft_stop = 1525;		//current calibration for Left servo to stop
int sRight_fullForward = 1300;	//full forward speed for Right servo
int sLeft_fullForward = 1725;	//full forward speed for Left servo

void void setup()
{
	sRight.attach(12);
	sLeft.attach(13);

	sLeft.writeMicroseconds(sLeft_stop);
	sRight.writeMicroseconds(sRight_stop);
	delay(1000);

	Serial.begin(9600);
	pinMode(trigPin, OUTPUT);
  	pinMode(echoPin, INPUT);


}