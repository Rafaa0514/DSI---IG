#pragma once

#ifndef DEACCELERATION_H_
#define DEACCELERATION_H_
#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "Transform.h"
#include <cassert>

class DeAcceleration : public Component{
private:
	float deAcceleration;  // deacceleration factor
	Transform* tr_;

public:
	static constexpr cmpId_type id = _DEACCELERATION;
	// Constructor
	DeAcceleration() : deAcceleration(0.99), tr_(nullptr) {};
	// Destructor
	virtual ~DeAcceleration() { tr_ = nullptr; };

	// Gets a pointer to the Transform
	virtual void initComponent();
	// Reduces the velocity and if it's very tiny makes it 0
	virtual void update();
};
#endif