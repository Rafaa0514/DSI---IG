#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    
	ofBackgroundHex(0xfdefc2);
	ofSetLogLevel(OF_LOG_NOTICE);
	ofSetVerticalSync(true);
    ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL);
    
	// Box2d
	box2d.init();
	box2d.setGravity(0, 0);
	box2d.createBounds();
	box2d.setFPS(60.0);
	
}

//--------------------------------------------------------------
void ofApp::update() {
	box2d.update();	
}

//--------------------------------------------------------------
void ofApp::draw() {
	
    for(auto & particle : particles) {
		particle->draw();
	}
	
	string info = "FPS: "+ofToString(ofGetFrameRate(), 1);
	info += "\nClick to add particles\nThe letters and color are from the custom data.";
	ofSetHexColor(0x444342);
	ofDrawBitmapString(info, 20, 20);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    
    auto p = std::make_shared<CustomParticle>(box2d.getWorld(), x, y, ofRandom(20, 60));
 
	particles.push_back(p);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

