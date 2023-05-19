#include "Game.h"
#include "ResultState.h"
#include "MenuState.h"

 
ResultState::ResultState(Game *g): State(g, "VICTORIA"){
    font.load("../../src/resources/fonts/AovelSansRounded.ttf", 50);
    titlePosX = ofGetWidth() / 2 - font.getStringBoundingBox(name, 0, 0).getWidth() / 2;
    titlePosY = ofGetHeight() / 3 - font.getStringBoundingBox(name, 0, 0).getHeight() / 2;

    posX = ofGetWidth() / 2 - font.getStringBoundingBox("Press space to start", 0, 0).getWidth() / 2;
    posY = ofGetHeight() * 2 / 3 - font.getStringBoundingBox("Press space to start", 0, 0).getHeight() / 2;

    alpha = 255;
    increasing = false;

    game->playMusic(RESULT_THEME);
};

ResultState::~ResultState(){};

void ResultState::update(){
    if (increasing) {
        if (alpha < 255) alpha += 2;
        else increasing = false;
    }

    else {
        if (alpha > 2) alpha -= 2;
        else increasing = true;
    }
};

void ResultState::draw(){
    ofBackground(ofColor::darkorange);

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

void ResultState::next(){
    game->stopMusic(RESULT_THEME);
    game->setState(new MenuState(game));
};

void ResultState::keyPressed(int key) {
    if (key == ' ') next();
}