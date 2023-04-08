#pragma once
#include "../ecs/Component.h"
#include "Transform.h"

class GrappleBehaviour : public Component {
private:
	Transform* tr;
	Transform* actorTr;
	Transform* targetTr;
	float grappleSpeed;
public:
	static constexpr cmpId_type id = _GRAPPLE;
	GrappleBehaviour(Transform* act, Transform* trg);
	virtual void initComponent();
	virtual void update();
};

