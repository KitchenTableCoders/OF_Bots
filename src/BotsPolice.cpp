

#include "BotsPolice.h"

bool BotsPolice::checkIfTouching(Bot* bot1, Bot* bot2)
{
	ofPoint bot1Pos = bot1->getPos();
	ofPoint bot2Pos = bot2->getPos();
	
	bool isTouching = (ofDist(bot1Pos.x, bot1Pos.y, bot2Pos.x, bot2Pos.y) < 3) ;
	return isTouching;
}