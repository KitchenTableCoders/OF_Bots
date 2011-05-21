#include "Bot.h"

void Bot::setup(int botUID, int x, int y)
{
	UID = botUID; // a unique id, in case a bot needs to identify itself to others. Not using it in this example.
	xPos = x;
	yPos = y;
	isDriving = true;
}

void Bot::update(bool isTouchingOtherBot)
{
	isDriving = !isTouchingOtherBot;
	
	// Only drive if you havn't touched someone yet.
	if(isDriving)
	{
		driveSomewhere();
	} 
}

void Bot::draw()
{
	// Green if driving, Red if not.
	if(isDriving)
	{
		ofSetColor(0,244,0);
	} else {
		ofSetColor(244,0,0);		
	}
	ofCircle(xPos, yPos, 3);
}


void Bot::driveSomewhere()
{
	xPos+= ofRandom(-1, 2);
	yPos+= ofRandom(-1, 2);	
}

ofPoint Bot::getPos()
{
	ofPoint p;
	p.x = xPos;
	p.y = yPos;
	return p;
}
