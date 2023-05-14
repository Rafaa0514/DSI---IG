#include "Pit.h"
#include "Player.h"

Pit::Pit(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, dim) {
    material.setEmissiveColor(ofColor::white);
	cilindro.setParent(transform);
	cilindro.rotate(0, 0, 0, 0);
	cilindro.set(dim.x / 2, dim.y);
}

void Pit::draw() {
    material.begin();
    {
        cilindro.draw();
    }
    material.end();
}

void Pit::receiveCarCollision(Player* car) {
	car->setFalling(true);
}