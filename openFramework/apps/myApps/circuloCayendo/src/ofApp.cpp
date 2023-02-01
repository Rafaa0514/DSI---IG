#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);

}

//--------------------------------------------------------------
void ofApp::update(){
	//posY += 20;
	//posY %= ofGetHeight();
	giro++;
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Pacman
	ofSetColor(255, 255, 0);
	ofFill();
	ofBeginShape();
	for (int i = 0; i < 300; i += 10) {
		ofVertex(ofGetWidth() / 2 + radio * cos(ofDegToRad(i + giro)), ofGetHeight() / 2 + radio * sin(ofDegToRad(i + giro)));
	}
	ofVertex(ofGetWidth() / 2 + cos(ofDegToRad(giro + 20)), ofGetHeight() / 2 + sin(ofDegToRad(giro + 20)));
	ofEndShape();

	ofSetColor(255, 0, 0);

	// Espiral q gira
	ofNoFill();
	ofBeginShape();
	for (int i = 0; i < iteraciones; i += 10) {
		ofVertex(ofGetWidth() / 2 + (radio - (radio * i / iteraciones)) * cos(ofDegToRad(i + giro)), ofGetHeight() / 2 + (radio - (radio * i / iteraciones)) * sin(ofDegToRad(i + giro)));
	}
	ofEndShape();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//if (key == 97) posY += 15;
	//else if (key == 100) posY -= 15;
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
