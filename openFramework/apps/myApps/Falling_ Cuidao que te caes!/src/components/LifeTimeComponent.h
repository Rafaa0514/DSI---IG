#pragma once
#include "../ecs/Component.h"


class LifeTimeComponent : public Component {
private:
	float lifeTime, elapsedTime;

public: 
	static constexpr cmpId_type id = _LIFE_TIME;

	LifeTimeComponent(float lt) : lifeTime(lt), elapsedTime(0) { }

	virtual void update();
};