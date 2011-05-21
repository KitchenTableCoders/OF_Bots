#ifndef _BOTS_POLICE
#define _BOTS_POLICE

#include "ofMain.h"
#include "Bot.h"

class BotsPolice {
	
public:

	bool checkIfTouching(Bot* bot1, Bot* bot2);
	
	/*
	 In this example, BotsPolice is just a utility class,
	 but the moment it needs to retain state,I would activate the functions below just like i did with Bots.
	 
	 Also, if OFApp.h gets to long, I would start moving related control code in here. For example, update() code from OFApp might end up here,
	 and i would then call botsPolice.update() from OFApp (just like i'm doing with Bots). 
	*/
	
	
	/*
	 void setup();
	 void update();
	 void draw();
	
	 void keyPressed(int key);
	 void keyReleased(int key);		
	 void mouseMoved(int x, int y );
	 void mouseDragged(int x, int y, int button);
	 void mousePressed(int x, int y, int button);
	 void mouseReleased(int x, int y, int button);
	 void windowResized(int w, int h);
	 */
};

#endif

