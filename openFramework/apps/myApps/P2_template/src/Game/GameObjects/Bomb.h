#pragma once
#include "GameObject.h"

class Explosion : public GameObject {
private:
    float lifeTime, elapsedTime;
public:
    Explosion(Game* g, glm::vec3 pos, glm::vec3 dim);

    void draw() override;
    void update() override;
    void receiveCarCollision(Player* car) override;
};


class Bomb : public GameObject {
private:
	void explode();
	ofxAssimpModelLoader model;

public:
	Bomb(Game* g, glm::vec3 pos, glm::vec3 dim);

	void draw() override;
	void update() override;
	void receiveCarCollision(Player* car) override;
};
