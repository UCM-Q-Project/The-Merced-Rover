#include <Servo.h>

Servo sRight;
Servo sLeft;

void setup(){
//	sRight.attach(12);
//	sLeft.attach(13);
}

void loop(){
	sRight.attach(12);
	sLeft.attach(13);

	sLeft.writeMicroseconds(1700);
	sRight.writeMicroseconds(1300);
	delay(3000);

	sLeft.writeMicroseconds(1300);
	sRight.writeMicroseconds(1700);
	delay(3000);

	sLeft.writeMicroseconds(1300);
	sRight.writeMicroseconds(1300);
	delay(3000);

	sLeft.writeMicroseconds(1700);
	sRight.writeMicroseconds(1700);
	delay(3000);

	sRight.detach();
	sLeft.detach();	
	delay(3000);
}
