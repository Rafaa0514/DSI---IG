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
public:
	static constexpr cmpId_type id = _BUTTON;

	ButtonComponent(function<void(void)> fun);

	virtual void initComponent();
	virtual void update();

	virtual void keyReleased(char k);
	virtual void keyPressed(char k);

	bool isMouseOver();
};