#pragma once
#include "GameObject.h"
#include "Player.h"

class Arco : public GameObject {
private:
	ofFbo myFbo;
	float changeTime, elapsedTime;
	int money, maxMoney, minMoney;
	GameObject* left;
	GameObject* right;
	GameObject* top;

	ofTrueTypeFont font;
	float posX, posY;

public:
	Arco(Game* g, glm::vec3 pos, glm::vec3 dim);

	void update() override;
	void draw() override;
	void receiveCarCollision(Player* car) override;
};

