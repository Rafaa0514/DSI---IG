#include "DRS.h"
#include "Player.h"

DRS::DRS(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, dim) {

    material.setDiffuseColor(ofColor::crimson);
}

void DRS::draw() {
    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void DRS::receiveCarCollision(Player* car) {
    car->activateDRS();
}