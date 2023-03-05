#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	Manager* m = managers[state::mainmenu];
	// inicializar main menu manager
	m = managers[state::play];
	// inicializar play manager
	controllers[controller::obstacles] = new ObstacleController(m);
	controllers[controller::powerups] = new PowerUpController(m);
	m = managers[state::endmenu];
	// inicializar end menu manager
}

//--------------------------------------------------------------
void ofApp::update(){
	managers[currentState]->update();
	if (currentState == play) {
		for (int i = 0; i < controller::size; ++i) {
			controllers[i]->addFrequently();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	managers[currentState]->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	managers[currentState]->keyPressed(key);
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
