#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
private:
	ofImage mario;
	const int sw = 16, sh = 32;
	int x, y;
	int sx, sy;
	int speed;
	int velX, velY;
	bool fliped;
	vector<vector<int>> anims;
	int idleAnim, movementAnim;
	int currentAnim;
	int currentFrame;

	public:
		void setup();
		void update();
		void draw();

		void changeAnim(int anim);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
