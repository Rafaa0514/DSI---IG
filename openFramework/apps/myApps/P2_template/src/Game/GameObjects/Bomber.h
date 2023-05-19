#pragma once
#include "Bomb.h"

class Bomber : public GameObject {
private:
	ofCylinderPrimitive body;
	ofxAssimpModelLoader model;
	int direction;
	float minX, maxX;
	double elapsedTime, cooldown;
	void dropBomb();

public:
	Bomber(Game* g, glm::vec3 pos, glm::vec3 dim, float distance);
	void update() override;
	void draw() override;
	
};