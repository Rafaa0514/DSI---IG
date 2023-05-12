#pragma once
#include "GameObject.h"
class Dirt : public GameObject {
private:
	ofPlanePrimitive plane;

public:
	Dirt(Game* g, glm::vec3 pos, glm::vec3 dim);
	~Dirt();

	void draw() override;
	/*void drawDebug() override {
		plane.drawWireframe();
	}*/

	void receiveCarCollision(Player* car) override;
};