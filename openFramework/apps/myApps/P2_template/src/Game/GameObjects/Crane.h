#pragma once
#include "Barrier.h"

class Palo : public GameObject {
private:

public:
	Palo(Game* g, glm::vec3 pos, glm::vec3 dim, GameObject* father);

	void update() override;
	void draw() override;
};

class Gancho : public Barrier {
public:
	Gancho(Game* g, glm::vec3 pos, glm::vec3 dim, GameObject* father, float minY);

	void receiveCarCollision(Player* car) override;
};


class Crane : public GameObject {
private:
	Palo* palo;
	Gancho* gancho;

public:
	Crane(Game* g, glm::vec3 pos, glm::vec3 dim);
	void update() override;
	void draw() override;
};
