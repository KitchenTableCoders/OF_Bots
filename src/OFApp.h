#ifndef _OF_APP
#define _OF_APP

#include "ofMain.h"
#include "Bot.h"
#include "BotsPolice.h"

// This is our main App class. It inherits from ofBasApp, which gives us access to mouse/keyboard/draw/setup callback funcs
class OFApp : public ofBaseApp{
	
    public:
		
	// These functions are passed through from ofBasApp. OF calls them automatically, and we'll pass some/all of them to each of our classes.
		void setup();
		void update();
		void draw();
		
	// For this example, I'm only using the ones on top. But you can activate any of these below
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
	// These classes are specific to our example I made them private, because no-one else needs to use them
	    vector <Bot*> botsVec; // a vector object (dynamic array) to hold our bots
	    BotsPolice botsPolice;  // a class with utility to deal with bots. We'll pass bot pointers into it.
};

#endif	

