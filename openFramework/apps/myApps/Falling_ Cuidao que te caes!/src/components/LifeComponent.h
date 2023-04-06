#pragma once
#include "../ecs/Component.h"
#include "Transform.h"
#include "Shape.h"


class LifeComponent : public Component {
protected:
	static const int LIFE_Y = 20;
	static const int RIGHT_X = 1024 - LIFE_Y - 25;
	static const int LEFT_X = LIFE_Y;
	static const int LIFE_WIDTH = 25;
	static const int LIFE_HEIGHT = 25;
	static const int RIGHT_X_OFFSET = -LIFE_WIDTH - LIFE_WIDTH / 2;
	static const int LEFT_X_OFFSET = LIFE_WIDTH + LIFE_WIDTH / 2;

private:
	int lifes;
	ofColor color;
	bool side; // true = right, false = left
	vector<Entity*> lifesObjs;
	float immunityTime, elapsedTime;
	bool immunity;

public:
	static constexpr cmpId_type id = _LIFE;

	LifeComponent(ofColor c, bool s) : lifes(0), color(c), side(s), 
		elapsedTime(0), immunityTime(1.5), immunity(false) {
		
	}
	virtual void initComponent();
	inline int getLifes() { return lifes; }
	void setLifes(int l);
	void increaseLifes();
	bool reduceLifes();

	virtual void update();
};