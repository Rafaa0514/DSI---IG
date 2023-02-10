#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//GUI
	gui.setup();

	//Cosas nuestras
	ofSetFrameRate(60);
	deltaTime = 0;
	rectos.push_back(Rectangle(RECT_SIDE, RECT_SIDE));
	elRecto = ofRectangle(ofGetWidth() / 2, ofGetHeight() - RECT_SIDE, RECT_SIDE * 2, RECT_SIDE);
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

	elRecto.setPosition(ofGetMouseX(), elRecto.getPosition().y);

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (Rectangle recto : rectos) {
		ofSetColor(recto.getColor());
		ofDrawRectangle(recto);
	}

	ofSetColor(0, 255, 0);
	ofDrawRectangle(elRecto);

	gui.draw();
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
