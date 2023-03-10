#include "DeAcceleration.h"

// Gets a pointer to the Transform
void DeAcceleration::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	assert(tr_ != nullptr);
}

// Reduces the velocity and if it's very tiny makes it 0
void DeAcceleration::update() {
	Vector2D newVelocity = tr_->getVelocity() * deAcceleration;
	if (tr_->getVelocity().magnitude() < 0.05)
		tr_->setVelocity(Vector2D(0,0));
	else
		tr_->setVelocity(newVelocity);
}