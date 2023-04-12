#include "LifeComponent.h"
#include "InputComponent.h"
#include "ShowAtOppositeSide.h"
#include "ScoreComponent.h"
#include "../ecs/Entity.h"

void LifeComponent::initComponent() {
	for (int i = 0; i < 5; ++i) {
		increaseLifes();
	}
}

void LifeComponent::setLifes(int l) {
	int n = abs(lifes - l);
	for (int i = 0; i < n; ++i) {
		if (l < lifes) reduceLifes();
		else increaseLifes();
	}
}

void LifeComponent::increaseLifes() {
	Entity* e = mngr_->addEntity(_grp_UI);
	e->addComponent<Transform>(
		Vector2D(((side) ? (RIGHT_X + lifes * RIGHT_X_OFFSET) : (LEFT_X + lifes * LEFT_X_OFFSET)),
		LIFE_Y), LIFE_WIDTH, LIFE_HEIGHT);
	e->addComponent<Shape>(_RECTANGLE, color);
	lifesObjs.push_back(e);
	++lifes;
}

bool LifeComponent::reduceLifes() {
	if (lifes > 0 && !immunity) {
		lifesObjs.back()->setAlive(false);
		lifesObjs.pop_back();
		--lifes;
		if (lifes == 0) {
			ent_->removeComponent<InputComponent>();
			ent_->removeComponent<ShowAtOppositeSide>();
			auto tr = ent_->getComponent<Transform>();
			tr->setX(ofGetWidth() * 2);
			tr->setVelocity(Vector2D(0,0));
			ent_->getComponent<ScoreComponent>()->stopCounting();
			onDeath();
		}
		immunity = true;
		return true;
	}
	return false;
}

void LifeComponent::update() {
	if (immunity) {
		if (immunityTime > elapsedTime) {
			elapsedTime += ofGetLastFrameTime();
		}
		else {
			elapsedTime = 0;
			immunity = false;
		}
	}
}