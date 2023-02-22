#pragma once

const int RECT_SIDE = 100;

#include "ofMain.h"
#include "ofxGui.h"
#include <list>
enum ESTADO_DE_JUEGO { vivo = 0, muelto };

class ofApp : public ofBaseApp{
private:

	class Rectangle : public ofRectangle {
		using MiPosicion = list<Rectangle>::iterator;
	private:
		float x0, x1;
		float y0, y1;
		bool color;
		float deltaX;
		MiPosicion miPos;
		ofParameter<float>* speed;
		float* speedFactor;

	public:
		Rectangle(float w, float h, ofParameter<float>* _s, float* _sf) :
			ofRectangle(ofRandom(ofGetWidth() - w), 0, w, h), color((int)ofRandom(3)),
			x0(x), x1(ofRandom(ofGetWidth() - w)), y0(y), y1(ofGetHeight()), speed(_s), speedFactor(_sf) {
			deltaX = (x1 - x0) / y1;
		}

		ofColor getColor() {
			if (color) return ofColor(255);
			return ofColor(255, 0, 0);
		}

		void setPos(MiPosicion _pos) { miPos = _pos; }

		MiPosicion getPos() { return miPos; }

		void Move() {
			setPosition(getPosition().x + (deltaX * *speed * *speedFactor), getPosition().y + (1 * *speed * *speedFactor));
		}

		bool getOutOfWindow() { return getPosition().y >= ofGetHeight(); }
		//void FollowMouse() { setPosition(3, y); }
	};

	ofImage background;
	list<Rectangle> rectos;
	list<list<Rectangle>::iterator> anos;
	ofRectangle elRecto;
	float spawnStartTime;
	float challengeStartTime;
	float elapsedTime;
	int points;
	ESTADO_DE_JUEGO estado;

	//GUI
	ofParameter<float> rectoSpeed;
	ofParameter<float> spawnTime;
	int increaseChallenge;
	float speedFactor;
	float spawnTimeFactor;
	ofParameterGroup parameters;
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
