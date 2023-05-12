#include "Dirt.h"
#include "Player.h"

Dirt::Dirt(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, glm::vec3(dim.x, dim.y, 100)) {
    material.setEmissiveColor(ofColor::forestGreen);

    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);
}

Dirt::~Dirt() {

}

void Dirt::draw() {
    material.begin();
    {
        plane.draw();
    }
    material.end();
}

void Dirt::receiveCarCollision(Player* car) {
    if (car->getSpeed() >= 4) car->brake();
}