#include "Shape.h"

Shape::Shape(shapeType shape) : shp(shape) {
	switch (shp) {
	case _TRIANGLE:
		createTriangle();
		break;
	case _RECTANGLE:
		createRectangle();
		break;
	case _CIRCLE:
		createCircle();
		break;
	}
}

void Shape::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	assert(tr_ != nullptr);
}

void Shape::createTriangle() {
	points.push_back(vec2(0, 0));
	points.push_back(vec2(1, 0));
	points.push_back(vec2(0.5, 1));
}
void Shape::createRectangle() {
	points.push_back(vec2(0, 0));
	points.push_back(vec2(0, 1));
	points.push_back(vec2(1, 0));
	points.push_back(vec2(1, 1));
}
void Shape::createCircle() {
	points.push_back(vec2(0.5, 0.5));
}
void Shape::drawTriangle() {
	//ofDrawTriangle(tr_->getX() + tr_->getWidth() * points[0])
}
void Shape::drawRectangle() {

}
void Shape::drawCircle() {

}





void Shape::draw() {
	ofPushMatrix();
	ofSetColor(col);
	switch (shp) {
	case _TRIANGLE:
		drawTriangle();
		break;
	case _RECTANGLE:
		drawRectangle();
		break;
	case _CIRCLE:
		drawCircle();
		break;
	}
	ofPopMatrix();
}