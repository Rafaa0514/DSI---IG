#pragma once
#include "Obstacle.h" 

class Bouncers : public Obstacle {
private:

public:
	Bouncers(Game* g, glm::vec3 pos, glm::vec3 dim);

	void receiveCarCollision(Player* car) override;
};