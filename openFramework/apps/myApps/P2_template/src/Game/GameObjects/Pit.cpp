#include "Pit.h"
#include "Player.h"

Pit::Pit(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, dim) {
	cilindro.setParent(transform);
	cilindro.set(dim.x / 2, dim.y);
    collider->rotateDeg(90, 0, 0, 1);

    model.loadModel("../../src/resources/models/pit.FBX");
    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0, -20, 0);
    model.setScale(1, 1, 1);
}

void Pit::draw() {
    /*material.begin();
    {
        cilindro.draw();
    }
    material.end();*/

    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}

void Pit::receiveCarCollision(Player* car) {
    car->setPlayerState(PlayerState::FALLING);
}