#pragma once

#include "ofMain.h"
#include <list>

class ofApp : public ofBaseApp{
private: 
	class Rectangle : public ofRectangle{
	private:
		float x0, x1;
		float y0, y1;
		bool player;
		bool color;
		float deltaX;

	public:
		Rectangle(float w, float h, bool plyr = false) : 
			ofRectangle(ofRandom(ofGetWidth() - w), 0, w, h), color(ofRandom(2)), player(plyr),
			x0(x), x1(ofRandom(ofGetWidth() - w)), y0(y), y1(ofGetHeight()) {
			deltaX = (x1 - x0) / y1;
		}

		ofColor getColor() {
			if (player) return ofColor(0, 255, 0);
			if (color) return ofColor(255);
			return ofColor(255, 0, 0);
		}

		void Move() {
			setPosition(getPosition().x + deltaX, getPosition().y + 1);
		}

		void FollowMouse() { setPosition(ofGetMouseX(), y); }
	};

	list<Rectangle> rectos;
	Rectangle elRecto;
	float deltaTime;
	float elapsedTime;

	public:

		void setup();
		void update();
		void draw();

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
