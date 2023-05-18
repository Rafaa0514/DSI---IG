#include "Obstacle.h"
#include "Player.h"

Obstacle::Obstacle(Game* g, glm::vec3 pos, glm::vec3 dim, bool um) : GameObject(g, pos, dim), useModel(um) {
    if (um) {
        model.loadModel("../../src/resources/models/obstacle.FBX");
        model.setRotation(0, 180, 1, 0, 0);
        model.setPosition(0, -dim.y / 2, 0);
        model.setScale(0.7, 0.5, 0.7);
    }
    else material.setEmissiveColor(ofColor::orangeRed);
}

Obstacle::~Obstacle() {

}

void Obstacle::draw() {
    if (useModel) {
        transform.transformGL();
        model.drawFaces();
        transform.restoreTransformGL();
    }
    else {
        material.begin();
        {
            collider->draw();
        }
        material.end();
    }
}

void Obstacle::receiveCarCollision(Player* car) {
	car->stop();
}


void Obstacle::receiveBulletCollision(GameObject* bullet) {
    this->kill();
    bullet->kill();
}