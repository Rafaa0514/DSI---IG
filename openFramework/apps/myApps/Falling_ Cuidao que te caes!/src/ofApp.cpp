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

	ofBackground(0, 0, 0);
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
			controllers[i]->update();
		}
		collisionSystem->update();
	}

	managers[currentState]->refresh();
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
	//TITULO
	Entity* e = m->addEntity();
	e->addComponent<Transform>(Vector2D(30, 30));
	e->addComponent<TextComponent>("FALLING!", 50);

	// SUBTITULO
	e = m->addEntity();
	e->addComponent<Transform>(Vector2D(80, 80));
	e->addComponent<TextComponent>("Cuidao que te caes", 50);

	// boton jogar
	e = m->addEntity(); 

	// boton salir
	e = m->addEntity(); 
}
// Inicializa el Play Manager
void ofApp::initPlayManager() {
	Manager*& m = managers[state::play];
	m = new Manager();
	createPlayer(m, _hdlr_DIESTRO);
	createPlayer(m, _hdlr_SINIESTRO);
	controllers[_cont_OBSTACLE] = new ObstacleController(m);
	controllers[_cont_POWERUP] = new PowerUpController(m);
	collisionSystem = new CollisionSystem(m);
}
// Inicializa el EndMenu Manager
void ofApp::initEndMenuManager() {
	Manager*& m = managers[state::endmenu];
	m = new Manager();
	
	// texto diciendo ganador y comparando puntuaciones

	// boton menu principal
}


// Crea y devuelve una entidad player en el manager recibido
Entity* ofApp::createPlayer(Manager* m, hdlrId_type hdlr) {
	Entity* p = m->addEntity();
	m->setHandler(hdlr, p);
	p->addComponent<Transform>(Vector2D(((hdlr == _hdlr_DIESTRO)?3:1) * ofGetWidth() / 4, ofGetHeight() * 4 / 5), 100, 100);
	p->addComponent<AbilityComponent>();
	if (hdlr == _hdlr_DIESTRO) p->addComponent<IJKLInput>();
	else p->addComponent<WASDInput>();
	p->addComponent<ScoreComponent>();
	p->addComponent<LifeComponent>((hdlr == _hdlr_DIESTRO) ? ofColor(255, 0, 0) : ofColor(0, 0, 255), hdlr == _hdlr_DIESTRO);
	p->addComponent<ShowAtOppositeSide>();
	p->addComponent<Shape>(_RECTANGLE, (hdlr == _hdlr_DIESTRO) ? ofColor(255, 0, 0) : ofColor(0, 0, 255));
	p->addComponent<PlayerAnimator>();
	p->addComponent<Collider>(50);
	p->addComponent<DeAcceleration>();
	return p;
}