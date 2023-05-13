#include "PlayState.h"
#include "MenuState.h"
    
MenuState::MenuState(Game* g) : State(game, "Menu Principal") {
    font.load("AovelSansRounded.ttf", 50);
    posX = ofGetWidth() / 2 - font.getStringBoundingBox("Menu Principal", 0, 0).getWidth() / 2;
    posY = ofGetHeight() / 2 - font.getStringBoundingBox("Menu Principal", 0, 0).getHeight() / 2;
};

void MenuState::update() {

}

void MenuState::draw(){
    ofBackground(0);

    ofPushMatrix();
    ofTranslate(posX, posY);
    ofSetColor(ofColor::white);
    font.drawString(name, 0, 0);
    ofPopMatrix();
};

void MenuState::next(){
    game->pushState(new PlayState(game));
};


void MenuState::keyPressed(int key) {
    if (key == ' ') next();
}