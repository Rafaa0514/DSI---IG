#include "PowerUpAnimator.h"
#include "../ecs/Entity.h"

PowerUpAnimator::PowerUpAnimator() : sizeDiff(0), alpha(200), tr(nullptr), shp(nullptr) {}

void PowerUpAnimator::initComponent() {
	tr = ent_->getComponent<Transform>();
	shp = ent_->getComponent<Shape>();
    color = shp->getColor();
}

void PowerUpAnimator::update() {
    if (alpha <= 0) {
        sizeDiff = 0;
        alpha = 200;
    }
    sizeDiff += 0.5;
    alpha -= 4;
    color.a = alpha;
}

void PowerUpAnimator::draw() {
    ofSetColor(color);
    ofTranslate(tr->getCenter().getX(), tr->getCenter().getY());
    ofDrawEllipse(0, 0, tr->getWidth() + sizeDiff, tr->getHeight() + sizeDiff);
}