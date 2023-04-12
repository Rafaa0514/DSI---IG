#include "TextComponent.h"
#include "../ecs/Entity.h"

TextComponent::TextComponent(string t, int fs, ofColor f) : text(t), tr(nullptr), foreground(f) {
	font.load("AovelSansRounded.ttf", fs);
}

void TextComponent::initComponent() {
	tr = ent_->getComponent<Transform>();
	tr->setWidth(font.getStringBoundingBox(text, 0, 0).getWidth());
	tr->setHeight(font.getStringBoundingBox(text, 0, 0).getHeight());
}

void TextComponent::draw() {
	ofSetColor(foreground);
	ofTranslate(tr->getX(), tr->getY());
	font.drawString(text, 0, 0);
}