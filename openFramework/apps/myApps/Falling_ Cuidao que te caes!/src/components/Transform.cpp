#include "Transform.h"

// Individual members of Vector2D Getters and Setters 

// Returns position X
float Transform::getX() { return position.getX(); }

// Returns position Y
float Transform::getY() { return position.getY(); }

// Returns width
int Transform::getWidth() { return width; }

// Returns height
int Transform::getHeight() { return height; }

// Returns velocity X
float Transform::getVelX() { return velocity.getX(); }

// Returns velocity Y
float Transform::getVelY() { return velocity.getY(); }

// Sets position X
void Transform::setX(float x) {position.setX(x); };

// Sets position Y
void Transform::setY(float y) { position.setY(y); };

// Sets width
void Transform::setWidth(float w) { width = w; };

// Sets height
void Transform::setHeight(float h) { height = h; };

// Sets velocity X
void Transform::setVelX(float velx) { velocity.setX(velx); };

// Sets velocity Y
void Transform::setVelY(float vely) { velocity.setY(vely); };

// Adds inserted value to rotation
void Transform::addRotation(float rot) { rotation += rot; };


// Updates position based on velocity and deltaTime
void Transform::update() { 
	velocity.rotate(rotation).normalize();
	position = position + velocity * ofGetLastFrameTime();
};