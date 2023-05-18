#pragma once
#include "GameObject.h"

class Water : public GameObject {
private:
	ofPlanePrimitive plane;
	ofTexture texture;
public:
	Water(Game* g, glm::vec3 pos, glm::vec3 dim);

	void draw() override;

	void receiveCarCollision(Player* car) override;
};

