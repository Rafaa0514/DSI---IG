#include "Shape.h"

Shape::Shape(shapeType shape, ofColor color) : shp(shape), col(color) {
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
	points.push_back(vec2(0, 0));
	points.push_back(vec2(0, 1));
	points.push_back(vec2(1, 0));
	points.push_back(vec2(1, 1));
}
void Shape::drawTriangle() {
	ofDrawTriangle(tr_->getX() + tr_->getWidth() * points[0].x,
					tr_->getY() + tr_->getHeight() * points[0].y, 
					tr_->getX() + tr_->getWidth() * points[1].x,
					tr_->getY() + tr_->getHeight() * points[1].y,
					tr_->getX() + tr_->getWidth() * points[2].x,
					tr_->getY() + tr_->getHeight() * points[2].y);
}
void Shape::drawRectangle() {
	ofDrawRectangle(tr_->getX(), tr_->getY(),tr_->getWidth(), tr_->getHeight());
}
void Shape::drawCircle() {
	ofDrawEllipse(tr_->getX(), tr_->getY(), tr_->getWidth(), tr_->getHeight());
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