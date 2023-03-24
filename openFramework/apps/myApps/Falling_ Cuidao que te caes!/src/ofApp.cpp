#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	currentState = state::play;

	// inicializar main menu manager
	initMainMenuManager();
	// inicializar play manager
	initPlayManager();
	// inicializar end menu manager
	initEndMenuManager();
}

ofApp::~ofApp() {
	for (int i = 0; i < state::size; ++i) {
		delete managers[i];
		managers[i] = nullptr;
	}
	for (int i = 0; i < maxControllerId; ++i) {
		delete controllers[i];
		controllers[i] = nullptr;
	}
	delete collisionSystem;
	collisionSystem = nullptr;
}

//--------------------------------------------------------------
void ofApp::update(){
	managers[currentState]->update();
	if (currentState == play) {
		for (int i = 0; i < maxControllerId; ++i) {
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
	managers[currentState]->keyReleased(key);
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

// Inicializa el MainMenu Manager
void ofApp::initMainMenuManager() {
	Manager*& m = managers[state::mainmenu];
	m = new Manager();
	// tetolo
	// boton jogar
	// boton salir
}
// Inicializa el Play Manager
void ofApp::initPlayManager() {
	Manager*& m = managers[state::play];
	m = new Manager();
	controllers[_cont_OBSTACLE] = new ObstacleController(m);
	controllers[_cont_POWERUP] = new PowerUpController(m);
	createPlayer(m);
}
// Inicializa el EndMenu Manager
void ofApp::initEndMenuManager() {
	Manager*& m = managers[state::endmenu];
	m = new Manager();
}


// Crea y devuelve una entidad player en el manager recibido
Entity* ofApp::createPlayer(Manager* m) {
	Entity* p = m->addEntity();
	p->addComponent<Transform>(Vector2D(ofGetWidth() / 2, ofGetHeight() / 2), 100, 100);
	//p->addComponent<Ability>();
	p->addComponent<IJKLInput>();
	//p->addComponent<PlayerAnimator>();
	//p->addComponent<ScoreComponent>();
	//p->addComponent<LifeComponent>();
	p->addComponent<ShowAtOppositeSide>();
	p->addComponent<Shape>(_RECTANGLE);
	//p->addComponent<Collider>();
	p->addComponent<DeAcceleration>();
	return p;
}