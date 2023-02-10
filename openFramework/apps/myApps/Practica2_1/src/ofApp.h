#pragma once

const int RECT_SIDE = 100;

#include "ofMain.h"
#include "ofxGui.h"
#include <list>


class ofApp : public ofBaseApp{
private:
	class Rectangle : public ofRectangle {
	private:
		float x0, x1;
		float y0, y1;
		bool color;
		float deltaX;

	public:
		Rectangle(float w, float h) :
			ofRectangle(ofRandom(ofGetWidth() - w), 0, w, h), color(ofRandom(2)),
			x0(x), x1(ofRandom(ofGetWidth() - w)), y0(y), y1(ofGetHeight()) {
			deltaX = (x1 - x0) / y1;
		}

		ofColor getColor() {
			if (color) return ofColor(255);
			return ofColor(255, 0, 0);
		}

		void Move() {
			setPosition(getPosition().x + deltaX, getPosition().y + 1);
		}

		//void FollowMouse() { setPosition(3, y); }
	};

	list<Rectangle> rectos;
	ofRectangle elRecto;
	float deltaTime;
	float elapsedTime;
	int points;

	//GUI
	ofxFloatSlider velCubes;
	ofxIntSlider frecuenciaCubes;
	ofxPanel gui;

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
