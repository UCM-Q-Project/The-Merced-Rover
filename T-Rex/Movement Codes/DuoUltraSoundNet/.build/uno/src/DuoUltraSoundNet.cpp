#include <Arduino.h>
#include <Servo.h>	
#include "../lib/QueueArray.h"
#include "../lib/botState.h"
void setup();
void loop();
#line 1 "src/DuoUltraSoundNet.ino"
//#include <Servo.h>	
//#include "../lib/QueueArray.h"
//#include "../lib/botState.h"

int trigPin_R = 3; 
int echoPin_R = 4;
int trigPin_L = 10; 
int echoPin_L = 11;
float pingTime;  //time for ping to travel from sensor to target and return
float targetDistance; //Distance to Target in centimeters
float aveDist;
float speedOfSound=34300;  //Speed of sound in centimeters per second at sea level

botState tRex;
QueueArray<float> queue;

int sRight_stop = 1520; 	//current calibration for Right servo to stop
int sLeft_stop = 1530;		//current calibration for Left servo to stop
int sRight_fullForward = 1300;	//full forward speed for Right servo
int sLeft_fullForward = 1725;	//full forward speed for Left servo

void setup()
{
	tRex.stop();
	Serial.begin(9600);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	digitalWrite(6, HIGH);
	digitalWrite(7, HIGH);

}

void loop()
{
	digitalWrite(6, HIGH);
	digitalWrite(7, HIGH);
	Serial.println("FULL");
	tRex.fullSpd();
	delay(10000);
	Serial.println("STOP");
	digitalWrite(6, LOW);
	digitalWrite(7, LOW);
	delay(10000);
}