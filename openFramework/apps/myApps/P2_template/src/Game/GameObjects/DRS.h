#pragma once
#include "GameObject.h"

class DRS : public GameObject {
private:
	ofxAssimpModelLoader model;
public:
	DRS(Game* g, glm::vec3 pos, glm::vec3 dim);
	void draw() override;
	void receiveCarCollision(Player* car) override;
};

