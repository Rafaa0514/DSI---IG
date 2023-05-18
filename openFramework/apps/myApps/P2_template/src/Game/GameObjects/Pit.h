#pragma once
#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Pit : public GameObject {
private:
	ofCylinderPrimitive cilindro;
	ofxAssimpModelLoader model;

public:
	Pit(Game* g, glm::vec3 pos, glm::vec3 dim);

	void draw() override;
	void receiveCarCollision(Player* car) override;
};