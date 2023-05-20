#include "PauseState.h"

PauseState::PauseState(Game* g) : State(g, "PAUSA") {
    // Cargamos la fuente
    font.load("../../src/resources/fonts/AovelSansRounded.ttf", 50);
    // Posiciones del titulo
    titlePosX = ofGetWidth() / 2 - font.getStringBoundingBox(name, 0, 0).getWidth() / 2;
    titlePosY = ofGetHeight() / 3 - font.getStringBoundingBox(name, 0, 0).getHeight() / 2;
    // Posiciones del texto
    posX = ofGetWidth() / 2 - font.getStringBoundingBox("Press space to continue", 0, 0).getWidth() / 2;
    posY = ofGetHeight() * 2 / 3 - font.getStringBoundingBox("Press space to continue", 0, 0).getHeight() / 2;

    // Variables
    alpha = 255;
    increasing = false;
    width = ofGetWidth() / 255.0;
}

void PauseState::update() {
    // Aumento el alpha
    if (increasing) {
        if (alpha < 255) alpha += 2;
        else increasing = false;
    }
    // Decrezco el alpha
    else {
        if (alpha > 2) alpha -= 2;
        else increasing = true;
    }
}

void PauseState::draw() {
    
    // Fondo en degradado
    for (int i = 0; i < 255; i++) {
        ofColor c = ofColor(0, 0, i);
        ofSetColor(c);
        ofDrawRectangle(i * width, 0, width, ofGetHeight());
    }

    // Matriz del titulo
    ofPushMatrix();
    ofTranslate(titlePosX, titlePosY);
    ofSetColor(ofColor::white);
    font.drawString(name, 0, 0);
    ofPopMatrix();

    // Matriz del texto
    ofPushMatrix();
    ofTranslate(posX, posY);
    ofSetColor(ofColor::white, alpha);
    font.drawString("Press space to continue", 0, 0);
    ofPopMatrix();
}

void PauseState::next() {
    game->popState();
}

void PauseState::keyPressed(int key) {
    if (key == ' ') next();
}