#include "ButtonComponent.h"
#include "../ecs/Entity.h"

ButtonComponent::ButtonComponent(function<void(void)> fun) : Component(), st(Over), tr(nullptr), sh(nullptr), clicked(false), f(fun) {

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
		clicked = true;

	if (st == Over && clicked && !ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
		f();
		clicked = false;
	}
}

void ButtonComponent::keyReleased(char k) {
	
}

void ButtonComponent::keyPressed(char k) {
	
}

bool ButtonComponent::isMouseOver() {
	return (ofGetMouseX() > tr->getX() && ofGetMouseX() < tr->getX() + tr->getWidth()) && 
		(ofGetMouseY() > tr->getY() && ofGetMouseY() < tr->getY() + tr->getHeight());
}