#include "Crane.h"
#include "Player.h"
#include "../Game.h"

// CLASE DEL PALO

Palo::Palo(Game* g, glm::vec3 pos, glm::vec3 dim, GameObject* father) : GameObject(g, pos, dim) {
    material.setDiffuseColor(ofColor::green);
    transform.setParent(father->transform);
}

void Palo::update() {
    
}

void Palo::draw() {
    material.begin();
    {
        collider->draw();
    }
    material.end();
}

// CLASE DEL GANCHO
Gancho::Gancho(Game* g, glm::vec3 pos, glm::vec3 dim, GameObject* father, float minY) : Barrier(g, pos, dim, minY) {
    transform.setParent(father->transform);
}

void Gancho::receiveCarCollision(Player* car) {
    car->setCoins();
}

// CLASE DE LA GRUA
Crane::Crane(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, dim) {
    material.setDiffuseColor(ofColor::green);


    glm::vec3 paloDim = glm::vec3(dim.x * 1.5, dim.y / 5, dim.z / 5);
    glm::vec3 paloPos = - glm::vec3(dim.x / 2 + paloDim.x / 2, - dim.y / 2 + paloDim.y / 2, 0);
    palo = new Palo(g, paloPos, paloDim, this);

    glm::vec3 ganchoDim = glm::vec3(paloDim.y, paloDim.x, paloDim.z);
    glm::vec3 ganchoPos = - glm::vec3(paloDim.x / 2 - ganchoDim.x/2, -200, 0);
    gancho = new Gancho(g, ganchoPos, ganchoDim, palo, paloPos.y - ganchoDim.y - paloDim.y / 2);

    g->addGameObject(palo);
    g->addGameObject(gancho);
}

void Crane::update() {
    // ROTAR TODO
    transform.rotate(0.2, 0, 1, 0);
}

void Crane::draw() {
    material.begin();
    {
        collider->draw();
    }
    material.end();
}