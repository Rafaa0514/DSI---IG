#pragma once
#include "../ecs/Component.h"
#include "Transform.h"

class Collider : public Component {
private:
	Transform* tr;
	float radious;
public:
	static constexpr cmpId_type id = _COLLIDER;
	Collider(float r) : radious(r), tr(nullptr) {}
	virtual void initComponent();
	bool collidesWith(Collider* other);
};