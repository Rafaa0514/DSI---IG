#include "Pit.h"
#include "Player.h"

Pit::Pit(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, dim) {
    material.setEmissiveColor(ofColor::white);
	cilindro.setParent(transform);
	cilindro.set(dim.x / 2, dim.y);
    collider->rotateDeg(90, 0, 0, 1);
}

void Pit::draw() {
    material.begin();
    {
        cilindro.draw();
    }
    material.end();
}

void Pit::receiveCarCollision(Player* car) {
    car->setPlayerState(PlayerState::FALLING);
}