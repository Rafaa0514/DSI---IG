#include "Barrier.h"

Barrier::Barrier(Game* g, glm::vec3 pos, glm::vec3 dim) :
	Obstacle(g, pos, dim), direction(-1) {}

void Barrier::update() {
	transform.move(0, 5 * direction, 0);
	if (transform.getY() < 0) direction = 1;
	else if (transform.getY() > 500) direction = -1;
}