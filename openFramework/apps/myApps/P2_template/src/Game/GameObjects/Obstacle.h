#pragma once
#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Obstacle : public GameObject {
protected:
	ofxAssimpModelLoader model;
public :
	Obstacle(Game* g, glm::vec3 pos, glm::vec3 dim);
	virtual ~Obstacle();

	void draw() override;
	void receiveCarCollision(Player* car) override;
	void receiveBulletCollision(GameObject* bullet) override;
};