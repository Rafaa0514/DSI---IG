#pragma once
#include "GameObject.h"

class OilPuddle : public GameObject{
private:
	ofPlanePrimitive plane;

public:
	OilPuddle(Game* g, glm::vec3 pos, glm::vec3 dim);
	~OilPuddle();

	void draw() override;

	void receiveCarCollision(Player* car) override;
};