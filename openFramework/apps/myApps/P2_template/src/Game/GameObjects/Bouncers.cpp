#include "Bouncers.h"
#include "Player.h"

Bouncers::Bouncers(Game* g, glm::vec3 pos, glm::vec3 dim) : Obstacle(g, pos, dim) {
	material.setEmissiveColor(ofColor::aqua);

}

void Bouncers::receiveCarCollision(Player* car) {
	if (car->getSpeed() > 0) car->setSpeed(-1 * car->getSpeed());
}