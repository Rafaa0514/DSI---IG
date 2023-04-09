#include "Shape.h"

Shape::Shape(shapeType shape, ofColor color, bool fill) : shp(shape), col(color), noFill(!fill) {
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
	ofTranslate(tr_->getX(), tr_->getY());
	ofDrawTriangle(tr_->getWidth() * points[0].x,
					tr_->getHeight() * points[0].y, 
					tr_->getWidth() * points[1].x,
					tr_->getHeight() * points[1].y,
					tr_->getWidth() * points[2].x,
					tr_->getHeight() * points[2].y);
}
void Shape::drawRectangle() {
	ofTranslate(tr_->getX(), tr_->getY());
	ofDrawRectangle(0, 0,tr_->getWidth(), tr_->getHeight());
}
void Shape::drawCircle() {
	ofTranslate(tr_->getCenter().getX(), tr_->getCenter().getY());
	ofDrawEllipse(0, 0, tr_->getWidth(), tr_->getHeight());
}

void Shape::draw() {
	ofSetColor(col);
	if (noFill) ofNoFill();

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

	if (noFill) ofFill();
}