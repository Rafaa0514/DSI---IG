#include "ScoreComponent.h"
#include "../ecs/Manager.h"

ScoreComponent::ScoreComponent() : score (0), scoreIncrease(5), scorePenalty(20), increaseInterval(1), 
                counter(0), posX(0), color(ofColor()), stop(false) { 
    font.load("AovelSansRounded.ttf", 40);
}

void ScoreComponent::initComponent() {
    posX = (ent_ == mngr_->getHandler(_hdlr_DIESTRO)) ? SCORE_RIGHT_X : SCORE_LEFT_X;
    color = (ent_ == mngr_->getHandler(_hdlr_DIESTRO)) ? DIESTRO_COLOR : SINIESTRO_COLOR;
}

void ScoreComponent::update() {
    counter += ofGetLastFrameTime();
    if (!stop && counter >= increaseInterval){
        score += scoreIncrease;
        counter = 0;
    }

    if (ent_ == mngr_->getHandler(_hdlr_DIESTRO)) 
        posX = SCORE_RIGHT_X - font.getStringBoundingBox(ofToString(score), 0, 0).width;
}


void ScoreComponent::draw() {
    ofSetColor(color);
    ofTranslate(posX, SCORE_Y);
    font.drawString(ofToString(score), 0, 0);
}