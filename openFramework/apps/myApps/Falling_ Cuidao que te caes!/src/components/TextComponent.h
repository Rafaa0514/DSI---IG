#pragma once
#include "../ecs/Component.h"
#include "Transform.h"

class TextComponent : public Component {
private:
	string text;
	ofTrueTypeFont font;
	Transform* tr;

public:
	static constexpr  cmpId_type id = _TEXT;
	TextComponent(string t, int size);

	virtual void initComponent();

	virtual void draw();
};