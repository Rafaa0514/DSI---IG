#include "ofApp.h"

const int RECT_W = 150;
const int RECT_H = 20;
const int SQUARE_SIDE = 200;

//--------------------------------------------------------------
void ofApp::setup(){
	aspa = ofRectangle(0,0, RECT_W, RECT_H);
	rotation = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	rotation+= 5;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofNoFill();

	//Por orden inverso, lo ultimo q se hace es el movimiento del cuadrado siguiendo el mouse
	ofTranslate(ofGetMouseX(), ofGetMouseY());

	ofScale(2);

	for (int i = 0; i < 4; i++) {
		drawAspe(i);
	}

	ofTranslate(-SQUARE_SIDE / 2, -SQUARE_SIDE / 2);
	//Lo ultimo que s ehace es pintar el cuadrado
	ofDrawRectangle(0,0, SQUARE_SIDE, SQUARE_SIDE);
}

void ofApp::drawAspe(int i) {
	ofPushMatrix();

	ofTranslate(pow(-1, i) * (-SQUARE_SIDE / 2), pow(-1, i / 2) * (-SQUARE_SIDE / 2));

	ofRotateDeg(rotation, 0, 0, 1);

	ofTranslate(-RECT_W / 2, -RECT_H / 2);

	ofDrawRectangle(aspa);
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
