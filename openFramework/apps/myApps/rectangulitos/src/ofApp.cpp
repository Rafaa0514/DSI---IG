#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetColor(255, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofNoFill();
	if (misRectos.size() >= 100) misRectos.pop_front();
	misRectos.push_back(glm::vec2(mouseX, mouseY));
	int a = 1;

	ofBeginShape();
	for (auto it : misRectos) {
		ofSetColor(255, 0, 0, a);
		ofDrawCircle(it.x, it.y, a);
		a++;
		ofSetColor(255, 255, 255);
		//ofVertex(it.x + (a/2), it.y + (a/2));
	}
	ofEndShape();
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
