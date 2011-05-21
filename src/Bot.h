#ifndef _BOT
#define _BOT

#include "ofMain.h"

class Bot {
	
public:
	
	void setup(int botUID, int x, int y);
	void update(bool isTouchingOtherBot);
	void draw();
	
	ofPoint getPos();
	/*
	void keyPressed(int key);
	void keyReleased(int key);		
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	*/
	
private:
	
	int UID; // a unique id, in case a bot needs to identify itself to others. Not using it in this example.
	int xPos;
	int yPos;
	bool isDriving; // stop driving if you've hit someone, set in update()
	void driveSomewhere();
	
};


#endif	