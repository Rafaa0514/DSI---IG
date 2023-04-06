#pragma once
#include "../ecs/Component.h"

class PowerUpComponent : public Component {
private:
	puType type;
public:
	static constexpr cmpId_type id = _POWERUP_COMP;

	PowerUpComponent(puType t) : type(t) { }
	
	inline puType getType() { return type; }
};