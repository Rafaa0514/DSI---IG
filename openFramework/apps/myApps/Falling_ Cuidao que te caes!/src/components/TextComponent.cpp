#include "TextComponent.h"
#include "../ecs/Entity.h"

TextComponent::TextComponent(string t, int fs) : text(t), tr(nullptr) {
	font.load("AovelSansRounded.ttf", fs);
}

void TextComponent::initComponent() {
	tr = ent_->getComponent<Transform>();
}

void TextComponent::draw() {
	ofTranslate(tr->getX(), tr->getY());
	font.drawString(text, 0, 0);
}