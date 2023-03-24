#pragma once
#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "../ecs/Component.h"
#include "../utils/Vector2D.h"
#include "../ecs/Entity.h"

class Transform : public Component
{
private:
	Vector2D position;
	int width, height;
	float rotation;
	Vector2D velocity;

public:
	static const cmpId id = cmpId::_TRANSFORM;

	// Constructor
	Transform(Vector2D p, int w, int h, float r = 0, Vector2D v = Vector2D()) : Component(), position(p), width(w), height(h), rotation(r), velocity(v) {};

	// Returns position
	inline Vector2D getPosition() { return position; };
	// Returns rotation
	inline float getRotation() { return rotation; };
	// Returns velocity
	inline Vector2D getVelocity() { return velocity; };

	inline Vector2D getCenter() { return position + (Vector2D(width, height) / 2); }

	// Returns position X
	float getX();
	// Returns position Y
	float getY();
	// Returns width
	int getWidth();
	// Returns height
	int getHeight();
	// Returns velocity X
	float getVelX();
	// Returns velocity Y
	float getVelY();

	// Sets position
	inline void setPosition(Vector2D p) { position = p; };
	// Sets rotation
	inline void setRotation(float r) { rotation = r; };
	// Sets velocity
	inline void setVelocity(Vector2D v) { velocity = v; };

	// Sets position X
	void setX(float x);
	// Sets position Y
	void setY(float y);
	// Sets width
	void setWidth(float w);
	// Sets height
	void setHeight(float h);
	// Sets velocity X
	void setVelX(float velx);
	// Sets velocity Y
	void setVelY(float vely);

	// Adds inserted value to rotation
	void addRotation(float rot);

	// Updates position based on velocity and deltaTime
	virtual void update();
};

#endif