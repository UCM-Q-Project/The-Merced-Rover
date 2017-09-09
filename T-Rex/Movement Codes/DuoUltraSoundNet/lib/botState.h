#ifndef STATE_H
#define STATE_H


#include <Arduino.h>
#include <Servo.h>
using namespace std;




class botState
{
private:
	Servo sRight;
	Servo sLeft;

public:
	botState()
	{
		sRight.attach(12);
		sLeft.attach(13);
	};
	botState(int rPin,int lPin)
	{
		sRight.attach(rPin);
		sLeft.attach(lPin);
	};
	void stop()
	{
		//sRight.writeMicroseconds(1520);
		//sLeft.writeMicroseconds(1530);
		
	};

	void fullSpd()
	{
		sRight.writeMicroseconds(1300);
		sLeft.writeMicroseconds(1725);
	};
	void half();
	void rTurn();
	void lTurn();
	void randTurn();

	
	~botState(){
		sRight.detach();
		sLeft.detach();
	};

	


	
};





#endif // STATE_H