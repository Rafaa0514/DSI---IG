#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
	posY += 20;
	posY %= ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 0, 255);
	//ofDrawCircle(ofGetWidth() / 2, posY, 50);
	ofBeginShape();
	for (int i = 0; i < 360; ++i) {
		ofVertex(ofGetWidth() / 2 + 50 * cos(i), posY + 50 * sin(i));
	}
	ofEndShape();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 97) posY += 15;
	else if (key == 100) posY -= 15;
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
