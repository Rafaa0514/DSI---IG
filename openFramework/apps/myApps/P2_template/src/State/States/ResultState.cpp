#include "Game.h"
#include "ResultState.h"
#include "MenuState.h"

 
ResultState::ResultState(Game *g): State(g, "VICTORIA"){
    font.load("../../src/resources/fonts/AovelSansRounded.ttf", 80);
    posX = ofGetWidth() / 2 - font.getStringBoundingBox(name, 0, 0).getWidth() / 2;
    posY = ofGetHeight() / 3 - font.getStringBoundingBox(name, 0, 0).getHeight() / 2;

    game->playMusic(RESULT_THEME);
};

ResultState::~ResultState(){};

void ResultState::update(){
};

void ResultState::draw(){
    ofBackground(ofColor::darkorange);

    ofPushMatrix();
    ofTranslate(posX, posY);
    ofSetColor(ofColor::white);
    font.drawString(name, 0, 0);
    ofPopMatrix();
};

void ResultState::next(){
    game->stopMusic(RESULT_THEME);
    game->setState(new MenuState(game));
};

void ResultState::keyPressed(int key) {
    if (key == ' ') next();
}