#include "InputComponent.h"


void InputComponent::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	//ab_ = ent_->getComponent<Ability>();
	assert(tr_ != nullptr);
}

void InputComponent::keyPressed(char k) {
	if (k == left) {
		tr_->setVelX(-PLAYER_SPEED);
	}
	else if (k == right) {
		tr_->setVelX(PLAYER_SPEED);
	}
}
void InputComponent::keyReleased(char k) {
	if (k == ability) {
		//ab_->acivate();
	}
}