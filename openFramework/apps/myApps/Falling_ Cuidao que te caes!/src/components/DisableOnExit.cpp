#include "DisableOnExit.h"

// Constructor
DisableOnExit::DisableOnExit() : Component(), tr_(nullptr) {}

// Gets a pointer to the Transform
void DisableOnExit::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	assert(tr_ != nullptr);
}

// When Transform is outside the window the Entity is destroyed
void DisableOnExit::update() {
	if ((tr_->getX() > ofGetWidth() && tr_->getVelX() > 0) || // right
		(tr_->getX() + tr_->getWidth() < 0 && tr_->getVelX() < 0) || // left
		(tr_->getY() > ofGetHeight() && tr_->getVelY() > 0) || // bottom
		(tr_->getY() + tr_->getHeight() < 0 && tr_->getVelY() < 0)) { // top

		ent_->setAlive(false);
	}
}