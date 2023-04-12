#include "TextComponent.h"
#include "../ecs/Entity.h"

TextComponent::TextComponent(string t, int fs, ofColor f, Vector2D o) : text(t), tr(nullptr), foreground(f), offset(o) {
	font.load("AovelSansRounded.ttf", fs);
	offset.setX(font.getStringBoundingBox(text, 0, 0).getWidth() / 2);
}

void TextComponent::initComponent() {
	tr = ent_->getComponent<Transform>();
	if (offset.getX() == 0) tr->setWidth(font.getStringBoundingBox(text, 0, 0).getWidth());
	if (offset.getY() == 0) tr->setHeight(font.getStringBoundingBox(text, 0, 0).getHeight());
}

void TextComponent::draw() {
	ofSetColor(foreground);
	ofTranslate(tr->getCenter().getX() - offset.getX(), 
		tr->getY() - offset.getY() + ((offset.getY() != 0) ? tr->getHeight() : 0));
	font.drawString(text, 0, 0);
}