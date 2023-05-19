#include "Barrier.h"

Barrier::Barrier(Game* g, glm::vec3 pos, glm::vec3 dim, float minimumY, bool um) :
	Obstacle(g, pos, dim, um), direction(1), maxY(pos.y), minY(minimumY) {
	int i = 0;
	if (um) {
		model.loadModel("../../src/resources/models/Barrier/fence.FBX");
		model.setRotation(0, 180, 1, 0, 0);
		model.setPosition(0, -20, 0);
		model.setScale(1, 1, 1);
	}
}

void Barrier::update() {
	transform.move(0, 5 * direction, 0);
	if (transform.getY() < minY) 
		direction = 1;
	else if (transform.getY() > maxY) 
		direction = -1;
}