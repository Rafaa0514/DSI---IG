#include "LifeTimeComponent.h"
#include "../ecs/Entity.h"

void LifeTimeComponent::update() {
	elapsedTime += ofGetLastFrameTime();
	if (elapsedTime >= lifeTime) {
		ent_->setAlive(false);
	}
}