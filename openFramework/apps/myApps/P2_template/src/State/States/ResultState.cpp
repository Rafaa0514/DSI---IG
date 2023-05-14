#include "Game.h"
#include "ResultState.h"
#include "MenuState.h"

 
ResultState::ResultState(Game *g): State(g, "Result State"){
    font.load("AovelSansRounded.ttf", 50);
    posX = ofGetWidth() / 2 - font.getStringBoundingBox("VICTORIA", 0, 0).getWidth() / 2;
    posY = ofGetHeight() / 3 - font.getStringBoundingBox("VICTORIA", 0, 0).getHeight() / 2;
};

ResultState::~ResultState(){};

void ResultState::update(){
};

void ResultState::draw(){
    ofBackground(127);
    ofPushMatrix();
    ofTranslate(posX, posY);
    ofSetColor(ofColor::white);
    font.drawString("VICTORIA", 0, 0);
    ofPopMatrix();
};

void ResultState::next(){
    game->setState(new MenuState(game));
};

void ResultState::keyPressed(int key) {
    if (key == ' ') next();
}