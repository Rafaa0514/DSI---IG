#include "Game.h"
#include "Player.h"

Game::Game(): StateMachine() {
    // TODO create settings
    ROAD_WIDTH = 3500;
    ROAD_LENGTH = 10000;

    generator = new GameObjectGenerator(this);
    bDebug = false;
    bPlayerFinish = false;
    gameObjects = nullptr;

    loadSounds();
    loadMusic();
}

Game::~Game(){
    ofLogNotice() << "Deleting game";

    // Borramos sonido
    for (ofSoundPlayer* os : sounds) delete os;
    delete sounds;
    
    // Borramos musica
    for (ofSoundPlayer* os : music) delete os;
    delete music;

    delete gameObjects;
    delete generator;
}

void Game::init(){
    if(gameObjects != nullptr)
        delete gameObjects;
    
    gameObjects = new GameObjectContainer();
    
    player = new Player(this);
    player->init();

    cam.setPosition(0, 300, -600);
    cam.setTarget(player->transform);
    cam.setParent(player->transform);
    //cam.disableMouseInput();
    cam.setFarClip(100000);
    
    gameObjects->add(player);
    generator->generateWorld();
    initTime = ofGetElapsedTimef();
}

void Game::update(){
    gameObjects->update();
}

void Game::draw(){
    ofEnableLighting();
    ofEnableDepthTest();
    
    cam.begin();
    {
        if (bDebug) { ofSetColor(ofColor::white); gameObjects->drawDebug(); }
        else gameObjects->draw();
    }
    cam.end();
    
    ofDisableLighting();
    ofDisableDepthTest();
}


Player * Game::getPlayer(){
    return player;
}

vector<GameObject *> Game::getCollisions(GameObject *gameObject){
    return gameObjects->getCollisions(gameObject);
}

void  Game::addGameObject(GameObject *gameobject){
    gameObjects->add(gameobject);
}

void Game::finishGame(){
    bPlayerFinish = true;
}

void Game::toggleDebug(){
    bDebug = !bDebug;
}

bool Game::isDebug() {
    return bDebug;
}

bool Game::isFinished(){
    return bPlayerFinish;
}

void Game::setFinished(bool v){
    bPlayerFinish = v;
}

float Game::getEllapsedTime(){
    return ofGetElapsedTimef() - initTime;
}

void Game::playSound(Sounds s){
    sounds[s]->play();
}

void Game::playMusic(Songs s) {
    music[s]->play();
}

void Game::stopMusic(Songs s) {
    music[s]->stop();
}

void Game::loadSounds() {
    for (int i = 0; i < MAX_SOUND; i++) {
        sounds[i] = new ofSoundPlayer();
        sounds[i]->loadSound(SoundsPaths[i]);
    }
}

void Game::loadMusic() {
    for (int i = 0; i < MAX_MUSIC; i++) {
        music[i] = new ofSoundPlayer();
        music[i]->loadSound(SongsPath[i]);
    }
}