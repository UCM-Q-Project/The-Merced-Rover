#include <Servo.h>	//import servo

int trigPin=6; //Sensor Trig pin connected to Arduino pin 6
int echoPin=7;  //Sensor Echo pin connected to Arduino pin 7 
float pingTime;  //time for ping to travel from sensor to target and return
float targetDistance; //Distance to Target in inches
float speedOfSound=34300;  //Speed of sound in centimeters per second at sea level

Servo sRight;		//declare right servo
Servo sLeft;		//declare left servo

int sRight_stop = 1515; 	//current calibration for Right servo to stop
int sLeft_stop = 1525;		//current calibration for Left servo to stop
int sRight_fullForward = 1300;	//full forward speed for Right servo
int sLeft_fullForward = 1725;	//full forward speed for Left servo

void setup() {
	sRight.attach(12);
	sLeft.attach(13);

	sLeft.writeMicroseconds(sLeft_stop);
	sRight.writeMicroseconds(sRight_stop);
	delay(1000);
  
	sLeft.writeMicroseconds(sLeft_fullForward);
	sRight.writeMicroseconds(sRight_fullForward);
	delay(1500);
	Serial.begin(9600);
	pinMode(trigPin, OUTPUT);
  	pinMode(echoPin, INPUT);
}
 
void loop() {
	
  	digitalWrite(trigPin, LOW); //Set trigger pin low
  	delayMicroseconds(2000); //Let signal settle
	digitalWrite(trigPin, HIGH); //Set trigPin higg
	delayMicroseconds(15); //Delay in high state
  	digitalWrite(trigPin, LOW); //ping has now been sent
  	delayMicroseconds(10); //Delay in low state
  	
		
	sRight.writeMicroseconds(sRight_fullForward);
  	sLeft.writeMicroseconds(sLeft_fullForward);

	targetDistance = distCalc(pulseIn(echoPin,HIGH));

	if(targetDistance <= 20){
  		sRight.writeMicroseconds(sRight_stop);
		sLeft.writeMicroseconds(sLeft_stop);
		delay(500);

		testSide(25);
  	}else{
		sRight.writeMicroseconds(sRight_fullForward);
		sLeft.writeMicroseconds(sLeft_fullForward);
	}
}


void testSide(float dist1) {
	float dist2;
	if(random(2) == 1){
		sRight.writeMicroseconds(sRight_fullForward);
		sLeft.writeMicroseconds(sRight_fullForward);
	}else{
		sRight.writeMicroseconds(sLeft_fullForward);
		sLeft.writeMicroseconds(sLeft_fullForward);
	}

	sRight.writeMicroseconds(sRight_stop);
	delay(500);
	dist2 = distCalc(pulseIn(echoPin, HIGH));
	if(dist2 <= dist1){
		sRight.writeMicroseconds(sLeft_fullForward);
		sLeft.writeMicroseconds(sLeft_fullForward);
	}else{
		sRight.writeMicroseconds(sRight_fullForward);
		sLeft.writeMicroseconds(sRight_fullForward);
	}
	
	sRight.writeMicroseconds(sRight_fullForward);
	sLeft.writeMicroseconds(sLeft_fullForward);


}


float distCalc (float pingTime){	//calculate target distance based on ping time
	float dist = pingTime * speedOfSound / 2000000;
	if (dist == 0){
		dist = 25;
	}
	Serial.print(dist);
	Serial.write(" centimeters");
	Serial.println();
	
	return dist;
}

