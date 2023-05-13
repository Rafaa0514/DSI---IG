#include "PauseState.h"

PauseState::PauseState(Game* g) : State(g, "Pause State") {
    font.load("AovelSansRounded.ttf", 50);
    posX = ofGetWidth() / 2 - font.getStringBoundingBox("Pausa", 0, 0).getWidth() / 2;
    posY = ofGetHeight() / 2 - font.getStringBoundingBox("Pausa", 0, 0).getHeight() / 2;
}

void PauseState::update() {

}

void PauseState::draw() {
    ofPushMatrix();
    ofTranslate(posX, posY);
    ofSetColor(ofColor::white);
    font.drawString(name, 0, 0);
    ofPopMatrix();
}

void PauseState::next() {
    game->popState();
}

void PauseState::keyPressed(int key) {
    if (key == ' ') next();
}