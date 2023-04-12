#pragma once
#include "../ecs/Component.h"
#include "Transform.h"

class TextComponent : public Component {
private:
	string text;
	ofTrueTypeFont font;
	Transform* tr;
	ofColor foreground;

public:
	static constexpr  cmpId_type id = _TEXT;
	TextComponent(string t, int size, ofColor f = ofColor(255,255,255));

	virtual void initComponent();

	virtual void draw();
};