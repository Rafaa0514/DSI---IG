#pragma once
#include "../ecs/Component.h"
#include "Shape.h"
#include <functional>

enum State {
	Out, Over
};

class ButtonComponent : public Component {
private:
	State st;
	Transform* tr;
	Shape* sh;
	bool clicked;
	function<void(void)> f;
	ofSoundPlayer* mySound;

public:
	static constexpr cmpId_type id = _BUTTON;

	ButtonComponent(function<void(void)> fun, ofSoundPlayer* s);

	virtual void initComponent();
	virtual void update();

	bool isMouseOver();
};