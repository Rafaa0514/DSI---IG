#include "ofApp.h"
const int RECT_SIDE = 100;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	deltaTime = 0;
	elRecto = Rectangle(RECT_SIDE * 2, RECT_SIDE, true);
	elRecto.setPosition(ofGetWidth() / 2, ofGetHeight() - RECT_SIDE);
	rectos.push_back(Rectangle(RECT_SIDE, RECT_SIDE));


}

//--------------------------------------------------------------
void ofApp::update(){
	
	if (ofGetElapsedTimef() - deltaTime >= 3) {
		deltaTime = ofGetElapsedTimef();
		rectos.push_back(Rectangle(RECT_SIDE, RECT_SIDE));
	}
	for (Rectangle& recto : rectos) {
		recto.Move();
	}

	elRecto.FollowMouse();

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (Rectangle recto : rectos) {
		ofSetColor(recto.getColor());
		ofDrawRectangle(recto);
	}

	
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
