#pragma once
#include "GameObject.h"
#include "Player.h"

class Arc : public GameObject {
private:
	ofFbo myFbo;
	float changeTime, elapsedTime;
	int money, maxMoney, minMoney;
	GameObject* left;
	GameObject* right;
	GameObject* top;

public:
	Arc(Game* g, glm::vec3 pos, glm::vec3 dim);

	void update() override;
	void draw() override;
	void receiveCarCollision(Player* car) override;
};

