#include "Bouncers.h"
#include "Player.h"

Bouncers::Bouncers(Game* g, glm::vec3 pos, glm::vec3 dim) : Obstacle(g, pos, dim) {
	model.loadModel("../../src/resources/models/bouncer.FBX");
	model.setRotation(0, 180, 1, 0, 0);
	model.setPosition(0, -75, 0);
	model.setScale(0.2, 0.2, 0.2);
}

void Bouncers::receiveCarCollision(Player* car) {
	if (car->getSpeed() > 0) car->setSpeed(-1 * car->getSpeed());
}