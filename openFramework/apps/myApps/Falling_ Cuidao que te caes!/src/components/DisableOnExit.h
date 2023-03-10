#pragma once
#include "Transform.h"

class DisableOnExit : public Component
{
private:
	Transform* tr_;

public:
	static const cmpId id = _DISABLE_ON_EXIT;
	// Constructor
	DisableOnExit();
	// Gets a pointer to the Transform
	virtual void initComponent();
	// When Transform is outside the window the Entity is destroyed
	virtual void update();
};

