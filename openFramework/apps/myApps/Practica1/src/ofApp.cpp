#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(20);

	int aux = ofRandom(2);
	color1 = aux;
	aux = ofRandom(2);
	color2 = aux;
	aux = ofRandom(2);
	forma1 = aux;
	aux = ofRandom(2);
	forma2 = aux;
	
}

//--------------------------------------------------------------
void ofApp::update(){
	if (rondas < 10) {
		if (mensaje != "") cont++;
		if (cont >= 60) {
			ofSetBackgroundColor(ofRandom(255), ofRandom(255), ofRandom(255));
			mensaje = "";
			int aux = ofRandom(2);
			color1 = aux;
			aux = ofRandom(2);
			color2 = aux;
			aux = ofRandom(2);
			forma1 = aux;
			aux = ofRandom(2);
			forma2 = aux;
			cont = 0;
			rondas++;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	if (rondas >= 10) {
		ofDrawBitmapString("EL JUGADOR 1 gano " + ofToString(wins1) + " rondas", ofGetWidth() / 2, ofGetHeight() / 4);
		ofDrawBitmapString("EL JUGADOR 2 gano " + ofToString(wins2) + " rondas", ofGetWidth() / 2, 2 * ofGetHeight() / 4);

	}
	else {
		if (color1) ofSetColor(255, 0, 0);
		else ofSetColor(0, 0, 255);

		if (forma1) ofDrawCircle(ofGetWidth() / 3, ofGetHeight() / 2, 50);
		else ofDrawRectangle(ofGetWidth() / 3, ofGetHeight() / 2, 50, 50);

		if (color2) ofSetColor(255, 0, 0);
		else ofSetColor(0, 0, 255);

		if (forma2) ofDrawCircle(2 * ofGetWidth() / 3, ofGetHeight() / 2, 50);
		else ofDrawRectangle(2 * ofGetWidth() / 3, ofGetHeight() / 2, 50, 50);

		ofDrawBitmapString("RONDAS: " + ofToString(rondas), ofGetWidth() / 2, ofGetHeight() / 4);
		ofDrawBitmapString(mensaje, ofGetWidth() / 2, 3 * ofGetHeight() / 4);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (mensaje == "") {
		if (forma1 == forma2 || color1 == color2) {
			if ('q' == key) mensaje = "GANO EL JUGADOR 1";
			else if ('o' == key) mensaje = "GANO EL JUGADOR 2";
			else if ('w' == key) mensaje = "GANO EL JUGADOR 2";
			else if ('p' == key) mensaje = "GANO EL JUGADOR 1";
		}

		else {
			if ('w' == key) mensaje = "GANO EL JUGADOR 1";
			else if ('p' == key) mensaje = "GANO EL JUGADOR 2";
			else if ('q' == key) mensaje = "GANO EL JUGADOR 2";
			else if ('o' == key) mensaje = "GANO EL JUGADOR 1";
		}
	

		if (mensaje == "GANO EL JUGADOR 1") wins1++;
		else if (mensaje == "GANO EL JUGADOR 2") wins2++;
	}

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
