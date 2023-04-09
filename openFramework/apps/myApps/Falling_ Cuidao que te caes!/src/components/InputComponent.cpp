#include "InputComponent.h"


void InputComponent::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	ab_ = ent_->getComponent<AbilityComponent>();
	assert(tr_ != nullptr);
}

void InputComponent::update() {
	if (isLeftPressed) {
		tr_->setVelX(tr_->getVelX() - PLAYER_SPEED);
		if (tr_->getVelX() < -MAX_SPEED) {
			tr_->setVelX(-MAX_SPEED);
		}
	}
	if (isRightPressed) {
		tr_->setVelX(tr_->getVelX() + PLAYER_SPEED);
		if (tr_->getVelX() > MAX_SPEED) {
			tr_->setVelX(MAX_SPEED);
		}
	}
}

void InputComponent::keyPressed(char k) {
	if (k == left) isLeftPressed = true;
	else if (k == right) isRightPressed = true;
}
void InputComponent::keyReleased(char k) {
	if (k == ability) {
		ab_->activate();
	}

	else if (k == left) isLeftPressed = false;
	else if (k == right) isRightPressed = false;
}