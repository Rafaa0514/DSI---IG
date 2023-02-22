#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//GUI
	gui.setup();

	parameters.setName("parameters");
	parameters.add(rectoSpeed.set("rectoSpeed", 1, 0.5, 2));
	parameters.add(spawnTime.set("spawnTime", 3, 1, 5));
	gui.setup(parameters);
	// by now needs to pass the gui parameter groups since the panel internally creates it's own group
	//sync.setup((ofParameterGroup&)gui.getParameter(), 6667, "localhost", 6666);
	ofSetVerticalSync(true);
	background = ofImage();
	background.load("naruto.png");
	speedFactor = 1;
	spawnTimeFactor = 1;
	increaseChallenge = 2;

	//Cosas nuestras
	ofSetFrameRate(60);
	spawnStartTime = 0;
	challengeStartTime = 0;
	auto it = rectos.insert(rectos.end(), Rectangle(RECT_SIDE, RECT_SIDE, &rectoSpeed, &speedFactor));
	it->setPos(it);
	elRecto = ofRectangle(ofGetWidth() / 2, ofGetHeight() - RECT_SIDE, RECT_SIDE * 2, RECT_SIDE);
}

//--------------------------------------------------------------
void ofApp::update(){

	if (estado == vivo) {

		if (ofGetElapsedTimef() - spawnStartTime >= (spawnTime * spawnTimeFactor)) {
			spawnStartTime = ofGetElapsedTimef();
			auto it = rectos.insert(rectos.end(), Rectangle(RECT_SIDE, RECT_SIDE, &rectoSpeed, &speedFactor));
			it->setPos(it);
		}

		if (ofGetElapsedTimef() - challengeStartTime >= increaseChallenge) {
			challengeStartTime = ofGetElapsedTimef();
			spawnTimeFactor /= increaseChallenge;
			speedFactor *= increaseChallenge;
		}

		for (Rectangle& recto : rectos) {
			recto.Move();
			if (recto.intersects(elRecto)) {
				if (recto.getColor() == ofColor(255)) points++;
				else estado = muelto;
				anos.push_back(recto.getPos());
			}

			else if (recto.getOutOfWindow()) {
				if (recto.getColor() == ofColor(255)) points--;
				anos.push_back(recto.getPos());
			}
		}
		elRecto.setPosition(ofGetMouseX(), elRecto.getPosition().y);

		for (auto it : anos) {
			rectos.erase(it);
		}
		anos.clear();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	if (estado == vivo) {

		ofSetColor(255);
		background.draw(0,0, ofGetWidth(), ofGetHeight());
		for (Rectangle& recto : rectos) {
			ofSetColor(recto.getColor());
			ofDrawRectangle(recto);
		}

		ofSetColor(0, 255, 0);
		ofDrawRectangle(elRecto);

		gui.draw();
	}

	else {
		string mensaje = "Su puntuacion ha sido de " + ofToString(points);
		ofDrawBitmapString(mensaje, ofGetWidth() / 2, ofGetHeight() / 2);
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
