#include "Obstacle.h"
#include "Player.h"

Obstacle::Obstacle(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, dim) {
	material.setEmissiveColor(ofColor::orangeRed);
}

Obstacle::~Obstacle() {

}

void Obstacle::draw() {
    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void Obstacle::receiveCarCollision(Player* car) {
	car->stop();
}


void Obstacle::receiveBulletCollision(GameObject* bullet) {
    this->kill();
    bullet->kill();
}