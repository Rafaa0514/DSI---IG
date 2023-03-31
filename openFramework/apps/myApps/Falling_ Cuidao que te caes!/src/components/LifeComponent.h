#pragma once
#include "../ecs/Component.h"
#include "Transform.h"
#include "Shape.h"

const int LIFE_Y = 20;
const int RIGHT_X = ofGetWidth() - LIFE_Y;
const int LEFT_X = LIFE_Y;
const int LIFE_WIDTH = 25;
const int LIFE_HEIGHT = 25;
const int RIGHT_X_OFFSET = LIFE_WIDTH + LIFE_WIDTH / 2;
const int LEFT_X_OFFSET = -LIFE_WIDTH - LIFE_WIDTH / 2;

class LifeComponent : public Component {
private:
	int lifes;
	ofColor color;
	bool side; // true = right, false = left
	vector<Entity*> lifesObjs;

public:
	static constexpr cmpId_type id = _LIFE;

	LifeComponent(ofColor c, bool s) : lifes(5), color(c), side(s) {
		lifesObjs.reserve(lifes);
	}
	virtual void initComponent();
	inline int getLifes() { return lifes; }
	void setLifes(int l);
	void increaseLifes();
	void reduceLifes();

	
};