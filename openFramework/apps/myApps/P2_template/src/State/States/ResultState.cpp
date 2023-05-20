#include "Game.h"
#include "ResultState.h"
#include "MenuState.h"

 
ResultState::ResultState(Game *g): State(g, "VICTORIA"){
    // Cargamos fuente
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
    game->playMusic(RESULT_THEME);
};

ResultState::~ResultState(){};

void ResultState::update(){
    // Aumento alpha del texto
    if (increasing) {
        if (alpha < 255) alpha += 2;
        else increasing = false;
    }
    // Decrezco alpha del texto
    else {
        if (alpha > 2) alpha -= 2;
        else increasing = true;
    }
};

void ResultState::draw(){
    // Fondo degradado
    for (int i = 0; i < 255; i++) {
        ofColor c = ofColor(i, i/2, 0);
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

void ResultState::next(){
    game->stopMusic(RESULT_THEME);
    game->setState(new MenuState(game));
};

void ResultState::keyPressed(int key) {
    if (key == ' ') next();
}