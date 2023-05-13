#pragma once
#include "GameObject.h"
class Dirt : public GameObject {
private:
	ofPlanePrimitive plane;
	ofTexture texture;

public:
	Dirt(Game* g, glm::vec3 pos, glm::vec3 dim);
	~Dirt();

	void draw() override;

	void receiveCarCollision(Player* car) override;
};