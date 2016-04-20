#include <Servo.h>		//import servo library

Servo servoL;			//left and right servos
Servo servoR;

int speedR = 93;              //max 
//int speedL = 90;

void setup(){
	servoR.attach(12);	//attach right servo to pin 12
//	servoL.attach(13);	//attach left servp  to pin 13
}

void loop(){
	servoR.write(speedR);
//	servoL.write(speedL);
}

