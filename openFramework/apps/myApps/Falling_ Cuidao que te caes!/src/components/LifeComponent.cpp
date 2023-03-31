#include "LifeComponent.h"
#include "../ecs/Entity.h"

void LifeComponent::initComponent() {
	for (int i = 0; i < lifes; ++i) {
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
	Entity* e = mngr_->addEntity();
	e->addComponent<Transform>(
		((side) ? (RIGHT_X + lifes * RIGHT_X_OFFSET) : (LEFT_X + lifes * LEFT_X_OFFSET)),
		LIFE_Y, LIFE_WIDTH, LIFE_HEIGHT);
	e->addComponent<Shape>(_RECTANGLE);
	lifesObjs.push_back(e);
	++lifes;
}

void LifeComponent::reduceLifes() {
	lifesObjs.back()->setAlive(false);
	lifesObjs.pop_back();
	--lifes;
}