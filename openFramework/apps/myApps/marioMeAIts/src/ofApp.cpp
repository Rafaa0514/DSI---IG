#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(20);

	mario.load("SMW_player-pouse_Mario.png");
	speed = 12;
	sx = 3 * sw;
	sy = 0;
	x = ofGetWidth() / 2;
	y = ofGetHeight() / 2;
	fliped = false;
	currentFrame = 0;
	currentAnim = 0;
	idleAnim = 0;
	anims.push_back({ 3 });
	movementAnim = 1;
	anims.push_back({ 1, 2 });

}


void ofApp::changeAnim(int anim) {
	if (currentAnim != anim) {
		currentAnim = anim;
		currentFrame = 0;
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	x += velX;
	y += velY;

	if (velX != 0) changeAnim(movementAnim);
	else changeAnim(idleAnim);
	currentFrame = (currentFrame + 1) % anims[currentAnim].size();

	sx = anims[currentAnim][currentFrame] * sw;

	velX = 0;
	velY = 0;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofTranslate(x, y);
	ofScale(2);
	ofRotateDeg((fliped) ? 180 : 0, 0, 1, 0);
	mario.drawSubsection(0, 0, sw, sh, sx, sy);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'a':case'A':
		velX = -speed;
		fliped = false;
		break;
	case 'd': case 'D':
		velX = speed;
		fliped = true;
		break;
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
