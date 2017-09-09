#include "Servo.h"

//Servo sRight;
Servo sLeft;

void setup()
{
	Serial.begin(9600);
	//sRight.attach(12);
	sLeft.attach(13);
}

void loop()
{
	//sRight.write(95);
	sLeft.write(96);
}
