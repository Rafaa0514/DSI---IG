#include "DRS.h"
#include "Player.h"

DRS::DRS(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, dim) {
    model.loadModel("../../src/resources/models/DRS/drs.FBX");
    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0,-20,0);
    model.setScale(0.1, 0.1, 0.1);
}

void DRS::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}

void DRS::receiveCarCollision(Player* car) {
    car->setPlayerState(PlayerState::TURBO);
}