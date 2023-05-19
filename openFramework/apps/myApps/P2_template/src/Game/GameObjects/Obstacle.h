#pragma once
#include "GameObject.h"

class Obstacle : public GameObject {
protected:
	ofxAssimpModelLoader model;
	bool useModel;
public :
	Obstacle(Game* g, glm::vec3 pos, glm::vec3 dim, bool um = true);
	virtual ~Obstacle();

	void draw() override;
	void receiveCarCollision(Player* car) override;
	void receiveBulletCollision(GameObject* bullet) override;
};