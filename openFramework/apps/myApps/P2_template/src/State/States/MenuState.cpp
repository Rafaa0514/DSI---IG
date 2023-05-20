#include "PlayState.h"
#include "MenuState.h"
    
MenuState::MenuState(Game* g) : State(g, "AT THE SPEED OF LIGHT: FORMULA 4") {
    // Cargamos la fuente
    font.load("../../src/resources/fonts/AovelSansRounded.ttf", 50);
    // Posiciones del titulo
    titlePosX = ofGetWidth() / 2 - font.getStringBoundingBox(name, 0, 0).getWidth() / 2;
    titlePosY = ofGetHeight() / 3 - font.getStringBoundingBox(name, 0, 0).getHeight() / 2;
    // Posiciones del texto
    posX = ofGetWidth() / 2 - font.getStringBoundingBox("Press space to start", 0, 0).getWidth() / 2;
    posY = ofGetHeight() * 2 / 3 - font.getStringBoundingBox("Press space to start", 0, 0).getHeight() / 2;

    // Variables
    alpha = 255;
    increasing = false;
    width = ofGetWidth() / 255.0;

    // Reproducimos musica
    game->playMusic(MENU_THEME);
};

void MenuState::update() {
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

void MenuState::draw(){
    // Fondo en degradado
    for (int i = 0; i < 255; i++) {
        ofColor c = ofColor(i, 0, 0);
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
    font.drawString("Press space to start", 0, 0);
    ofPopMatrix();
};

void MenuState::next(){
    game->stopMusic(MENU_THEME);
    game->playSound(BUTTON_SFX);
    game->setState(new PlayState(game));
};


void MenuState::keyPressed(int key) {
    if (key == ' ') next();
}