#include "PlayState.h"
#include "MenuState.h"
    
MenuState::MenuState(Game* g) : State(g, "AT THE SPEED OF LIGHT: FORMULA 4") {
    font.load("../../src/resources/fonts/AovelSansRounded.ttf", 50);
    titlePosX = ofGetWidth() / 2 - font.getStringBoundingBox(name, 0, 0).getWidth() / 2;
    titlePosY = ofGetHeight() / 3 - font.getStringBoundingBox(name, 0, 0).getHeight() / 2;

    posX = ofGetWidth() / 2 - font.getStringBoundingBox("Press space to start", 0, 0).getWidth() / 2;
    posY = ofGetHeight() * 2 / 3 - font.getStringBoundingBox("Press space to start", 0, 0).getHeight() / 2;

    alpha = 255;
    increasing = false;
    game->playMusic(MENU_THEME);
};

void MenuState::update() {
    if (increasing) {
        if (alpha < 255) alpha += 2;
        else increasing = false;
    }

    else {
        if (alpha > 2) alpha -= 2;
        else increasing = true;
    }
}

void MenuState::draw(){
    ofBackground(0);

    ofPushMatrix();
    ofTranslate(titlePosX, titlePosY);
    ofSetColor(ofColor::white);
    font.drawString(name, 0, 0);
    ofPopMatrix();

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