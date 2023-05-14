#include "Barrier.h"

Barrier::Barrier(Game* g, glm::vec3 pos, glm::vec3 dim, float minimumY) :
	Obstacle(g, pos, dim), direction(1), maxY(pos.y), minY(minimumY) {
	int i = 0;
}

void Barrier::update() {
	transform.move(0, 5 * direction, 0);
	if (transform.getY() < minY) 
		direction = 1;
	else if (transform.getY() > maxY) 
		direction = -1;
}