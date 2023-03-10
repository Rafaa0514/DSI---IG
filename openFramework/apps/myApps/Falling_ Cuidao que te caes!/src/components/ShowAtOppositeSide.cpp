#include "ShowAtOppositeSide.h"

// Constructor
ShowAtOppositeSide::ShowAtOppositeSide() : Component(), tr_(nullptr), offset(5) {}

// Gets a pointer to the Transform
void ShowAtOppositeSide::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	assert(tr_ != nullptr);
}

// Checks if the Transform is outside the window and changes its position to opposite side if that's the case
void ShowAtOppositeSide::update() {
	if (tr_->getX() + offset > ofGetWidth() && tr_->getVelX() > 0) {
		tr_->setX(-tr_->getWidth() - offset);
	}
	else if (tr_->getX() + tr_->getWidth() < -offset && tr_->getVelX() < 0) {
		tr_->setX(ofGetWidth() + offset);
	}
	if (tr_->getY() > ofGetHeight() + offset && tr_->getVelY() > 0) {
		tr_->setY(-tr_->getHeight() - offset);
	}
	else if (tr_->getY() + tr_->getHeight() < -offset && tr_->getVelY() < 0) {
		tr_->setY(ofGetHeight() + offset);
	}
}