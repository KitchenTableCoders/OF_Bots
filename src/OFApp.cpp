#include "OFApp.h"


//--------------------------------------------------------------
/*
OF calls this automatically for us (a callback function), once, when the app starts. 
*/
void OFApp::setup(){
	
	// Create a bunch of bots, call their setup function, and place them in a vector for later access.
	for(int i = 0; i < 500; i ++)
	{
		// 'bot' is a temporary bot pointer that we're only using here. The rest of the program will access the bots from the vector botsVec
		Bot* bot = new Bot();
		// calling the setup function of our bot. using -> instead of . because it's a pointer variable
		int randomXPos =  ofRandom(0, ofGetWidth());
		int randomYPos =  ofRandom(0, ofGetWidth());
		bot->setup(i,randomXPos , randomYPos);
		
		// place the bot pointer in our vector, for later use
		botsVec.push_back(bot);
	}
}

//--------------------------------------------------------------
/*
 OF calls this automatically for us (a callback function), in a loop, when the app is ready for a new cycle. 
 
 Notice how I'm brute-forcing my way through updating each bot, and checking for collision. 
 A bit of optimization can go a long way here (a fun excersize!), but even now we get good performence..
 .. the great advantage of using C++ is that we can write simple-stooopid code and it still works!
 */
void OFApp::update(){
	
	// For each bot, check if it's colliding, and then call it's update function
	for(int i = 0; i < botsVec.size(); i++)
	{

		bool isThisBotTouchingOtherBot = false;
		
		// for each bot, go through all the others and see if there's a collision.
		// this is a very un-optimized way of doing collision, but it does the job for up to a few hundred bots.
		for(int k = 0; k  < botsVec.size(); k++)
		{
			
			// One optimization is to skip this entire loop here if we already know the bot has collided
			// Try implementing it!
			
			if(k != i) // don't check the bot against itself. 
			{
				// the BotsPolice class is in charge of checking collision. We just pass it two pointers to the bots we're checking
				isThisBotTouchingOtherBot = botsPolice.checkIfTouching(botsVec[i] , botsVec[k]);
				// if collition found, stop running the loop and move below.
				if(isThisBotTouchingOtherBot) break;
			}
		}
		
		// In general, when i do OF code, I make sure that all my sub-classes have an update function, which is only called from this update() scope.
		botsVec[i]->update(isThisBotTouchingOtherBot);
	}
}

//--------------------------------------------------------------
/*
 OF calls this automatically for us (a callback function), in a loop, when the app is ready to draw to the screen 
 */
void OFApp::draw(){
	
	ofBackground(20,20,20);
	for(int i = 0; i < botsVec.size(); i++)
	{
		// In general, when i do OF code, I make sure that all my sub classes have a draw function, which is only called from this draw() scope.
		botsVec[i]->draw();
	}
}


/*
//--------------------------------------------------------------
void OFApp::keyPressed  (int key){ 
	//sprintf(eventString, "keyPressed = (%i)", key);
}

//--------------------------------------------------------------
void OFApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void OFApp::mouseMoved(int x, int y ){
	//sprintf(eventString, "mouseMoved = (%i,%i)", x, y);
}

//--------------------------------------------------------------
void OFApp::mouseDragged(int x, int y, int button){
	//sprintf(eventString, "mouseDragged = (%i,%i - button %i)", x, y, button);
}

//--------------------------------------------------------------
void OFApp::mousePressed(int x, int y, int button){
	//sprintf(eventString, "mousePressed = (%i,%i - button %i)", x, y, button);

}

//--------------------------------------------------------------
void OFApp::mouseReleased(int x, int y, int button){
	//sprintf(eventString, "mouseReleased = (%i,%i - button %i)", x, y, button);
}

//--------------------------------------------------------------
void OFApp::windowResized(int w, int h){
	//sprintf(eventString, "resized = (%i,%i)", w, h);
}
 */
 
