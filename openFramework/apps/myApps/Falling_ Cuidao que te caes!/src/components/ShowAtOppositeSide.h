#pragma once

#include "Transform.h"
#include <cassert>

class ShowAtOppositeSide : public Component {
private:
	Transform* tr_;
	int offset;

public:
	static constexpr cmpId_type id = _SHOW_AT_OPPOSITE_SIDE;
	// Constructor
	ShowAtOppositeSide();
	// Gets a pointer to the Transform
	virtual void initComponent();
	// Checks if the Transform is outside the window and changes its position to opposite side if that's the case
	virtual void update();
};

