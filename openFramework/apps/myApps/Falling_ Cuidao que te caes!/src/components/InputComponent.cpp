#include "InputComponent.h"


void InputComponent::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	ab_ = ent_->getComponent<AbilityComponent>();
	assert(tr_ != nullptr);
}

void InputComponent::keyPressed(char k) {
	if (k == left) {
		tr_->setVelX(tr_->getVelX() - PLAYER_SPEED);
		if (tr_->getVelX() < -MAX_SPEED) {
			tr_->setVelX(-MAX_SPEED);
		}
	}
	else if (k == right) {
		tr_->setVelX(tr_->getVelX() + PLAYER_SPEED);
		if (tr_->getVelX() > MAX_SPEED) {
			tr_->setVelX(MAX_SPEED);
		}
	}
}
void InputComponent::keyReleased(char k) {
	if (k == ability) {
		ab_->activate();
	}
}