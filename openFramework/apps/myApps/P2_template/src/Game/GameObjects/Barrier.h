#pragma once
#include "Obstacle.h"
class Barrier : public Obstacle {
private:
	int direction;
public:
	Barrier(Game* g, glm::vec3 pos, glm::vec3 dim);
	void update() override;
};

