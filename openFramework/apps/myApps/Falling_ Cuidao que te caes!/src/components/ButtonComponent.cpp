#include "ButtonComponent.h"
#include "../ecs/Entity.h"

ButtonComponent::ButtonComponent(function<void(void)> fun, ofSoundPlayer* s) : 
	Component(), st(Over), tr(nullptr), sh(nullptr), clicked(false), f(fun), mySound(s) {

}

void ButtonComponent::initComponent() {
	tr = ent_->getComponent<Transform>();
	sh = ent_->getComponent<Shape>();
}

void ButtonComponent::update() {
	if (isMouseOver()) 
		st = Over;
	else st = Out;

	if (!clicked && ofGetMousePressed(OF_MOUSE_BUTTON_LEFT) && st == Over)
	{
		mySound->play();
		clicked = true;
	}

	if (st == Over && clicked && !ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
		f();
		clicked = false;
	}
}

bool ButtonComponent::isMouseOver() {
	return (ofGetMouseX() > tr->getX() && ofGetMouseX() < tr->getX() + tr->getWidth()) && 
		(ofGetMouseY() > tr->getY() && ofGetMouseY() < tr->getY() + tr->getHeight());
}