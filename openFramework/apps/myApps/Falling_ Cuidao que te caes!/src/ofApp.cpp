#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	muelto[0] = false;
	muelto[1] = false;
	scoreD = scoreS = 0;

	winner = _LAST_HDLR_ID;
	currentState = mainmenu;
	futureState = mainmenu;
	initMainMenuManager();
	
	ofBackground(0, 0, 0);
}

ofApp::~ofApp() {
	delete mngr;

	for (int i = 0; i < maxControllerId; ++i) {
		delete controllers[i];
		controllers[i] = nullptr;
	}
	delete collisionSystem;
	collisionSystem = nullptr;
}

//--------------------------------------------------------------
void ofApp::update(){
	mngr->update();
	if (currentState == play) {
		for (int i = 0; i < maxControllerId; ++i) {
			controllers[i]->update();
		}
		collisionSystem->update();

		if (muelto[0] && muelto[1]) {
			// comparar scores
			scoreD = mngr->getHandler(_hdlr_DIESTRO)->getComponent<ScoreComponent>()->getScore();
			scoreS = mngr->getHandler(_hdlr_SINIESTRO)->getComponent<ScoreComponent>()->getScore();
			
			winner = (scoreD == scoreS) ? _LAST_HDLR_ID :
				(scoreD > scoreS) ? _hdlr_DIESTRO : _hdlr_SINIESTRO;
			// endstate
			futureState = state::endmenu;
		}
	}

	mngr->refresh();
	if (currentState != futureState) changeState();
}

//--------------------------------------------------------------
void ofApp::draw(){
	mngr->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	mngr->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	mngr->keyReleased(key);
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
	mngr = new Manager();
	//TITULO
	Entity* e = mngr->addEntity();
	Transform* title = e->addComponent<Transform>(Vector2D(ofGetWidth() / 2, ofGetHeight() / 5), 1, 1);
	e->addComponent<TextComponent>("FALLING!", 90);
	title->setX(title->getX() - title->getWidth() / 2);

	// SUBTITULO
	e = mngr->addEntity();
	Transform* subtitle = e->addComponent<Transform>(Vector2D(ofGetWidth() / 2, ofGetHeight() * 2 / 5), 1,1);
	e->addComponent<TextComponent>("Cuidao que te caes", 50);
	subtitle->setX(subtitle->getX() - subtitle->getWidth() / 2);

	// boton jogar
	e = mngr->addEntity();
	e->addComponent<Transform>(Vector2D(ofGetWidth() / 2 - 250, ofGetHeight() * 3 / 5), 500, 100);
	e->addComponent<Shape>(_RECTANGLE, ofColor(255, 124, 16));
	e->addComponent<ButtonComponent>([&]() { setFutureState(state::play); });
	e->addComponent<TextComponent>("JUGAR", 80, ofColor(255,255,255), Vector2D(0,10));

	// boton salir
	e = mngr->addEntity();
	e->addComponent<Transform>(Vector2D(ofGetWidth() / 2 - 250, ofGetHeight() * 4 / 5), 500, 100);
	e->addComponent<Shape>(_RECTANGLE, ofColor(255, 124, 16));
	e->addComponent<TextComponent>("SALIR", 80, ofColor(255, 255, 255), Vector2D(0, 10));
	e->addComponent<ButtonComponent>([&]() {});
}
// Inicializa el Play Manager
void ofApp::initPlayManager() {
	mngr = new Manager();
	createPlayer(mngr, _hdlr_DIESTRO);
	createPlayer(mngr, _hdlr_SINIESTRO);
	controllers[_cont_OBSTACLE] = new ObstacleController(mngr);
	controllers[_cont_POWERUP] = new PowerUpController(mngr);
	collisionSystem = new CollisionSystem(mngr);
}

// Inicializa el EndMenu Manager
void ofApp::initEndMenuManager() {
	mngr = new Manager();
	
	// texto diciendo ganador y comparando puntuaciones
	string message = "";
	ofColor color = ofColor();
	switch (winner) {
		case _LAST_HDLR_ID: {message = "EMPATE"; color = ofColor(255, 255, 255); } break;
		case _hdlr_DIESTRO: {message = "GANADOR ROJO"; color = ofColor(255, 0, 0); } break;
		case _hdlr_SINIESTRO: {message = "GANADOR AZUL"; color = ofColor(0, 0, 255); } break;
	}

	Entity* e = mngr->addEntity();
	Transform* tr = e->addComponent<Transform>(Vector2D(ofGetWidth() / 2, ofGetHeight() / 3), 1, 80);
	e->addComponent<TextComponent>(message, 80, color);
	tr->setX(tr->getX() - tr->getWidth() / 2);

	e = mngr->addEntity();
	tr = e->addComponent<Transform>(Vector2D(ofGetWidth() / 3, ofGetHeight() / 2), 1, 30);
	e->addComponent<TextComponent>("Jugador Azul: " + ofToString(scoreS), 30, ofColor(0, 0, 255));
	tr->setX(tr->getX() - tr->getWidth() / 2);

	e = mngr->addEntity();
	tr = e->addComponent<Transform>(Vector2D(ofGetWidth() * 2 / 3, ofGetHeight() / 2), 1, 30);
	e->addComponent<TextComponent>("Jugador Rojo: " + ofToString(scoreD), 30, ofColor(255, 0, 0));
	tr->setX(tr->getX() - tr->getWidth() / 2);

	// boton menu principal
	e = mngr->addEntity();
	e->addComponent<Transform>(Vector2D(ofGetWidth() / 2 - 200, ofGetHeight() * 2 / 3), 400, 100);
	e->addComponent<Shape>(_RECTANGLE, ofColor(255, 124, 16));
	e->addComponent<TextComponent>("MENU", 80, ofColor(255, 255, 255), Vector2D(0, 10));
	e->addComponent<ButtonComponent>([&]() { setFutureState(state::mainmenu); });
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
	p->addComponent<LifeComponent>((hdlr == _hdlr_DIESTRO) ? ofColor(255, 0, 0) : ofColor(0, 0, 255), hdlr == _hdlr_DIESTRO,
		[&](hdlrId_type h) { muelto[h] = true; });
	p->addComponent<ShowAtOppositeSide>();
	p->addComponent<Shape>(_RECTANGLE, (hdlr == _hdlr_DIESTRO) ? ofColor(255, 0, 0) : ofColor(0, 0, 255));
	p->addComponent<PlayerAnimator>();
	p->addComponent<Collider>(50);
	p->addComponent<DeAcceleration>();
	return p;
}

void ofApp::changeState() {
	delete mngr;
	mngr = nullptr;
	currentState = futureState;
	switch (currentState) {
		case mainmenu: initMainMenuManager(); break;
		case play: initPlayManager(); break;
		case endmenu: initEndMenuManager(); break;
	}
}