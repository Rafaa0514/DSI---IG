#pragma once
#include "Obstacle.h"

class Barrier : public Obstacle {
private:
	int direction;
	float minY, maxY;
public:
	Barrier(Game* g, glm::vec3 pos, glm::vec3 dim, float minimumY);
	void update() override;
};

