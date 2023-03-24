#pragma once
#include "../ecs/Component.h"
#include "Transform.h"
#include <cassert>

const int PLAYER_SPEED = 500;

class InputComponent : public Component {
private:
	char right, left, ability;
	Transform* tr_;
	//Ability* ab_;
public:
	static constexpr cmpId_type id = _INPUT;
	InputComponent(char r, char l, char a) : right(r), left(l), ability(a) {}
	virtual void initComponent();
	virtual void keyPressed(char k);
	virtual void keyReleased(char k);
};

class WASDInput : public InputComponent {
public:
	WASDInput() : InputComponent('d', 'a', 'w') {}
};
class IJKLInput : public InputComponent {
public:
	IJKLInput() : InputComponent('l', 'j', 'i') {}
};
