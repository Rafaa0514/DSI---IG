#include "Bomb.h"
#include "Game.h"
#include "Player.h"

// Clase de la explosion
Explosion::Explosion(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, dim){
    elapsedTime = 0.0f;
    lifeTime = 0.75f;
}

void Explosion::draw() {

}

void Explosion::update() {
    elapsedTime += ofGetLastFrameTime();
    if (elapsedTime >= lifeTime) kill();
}

void Explosion::receiveCarCollision(Player* car) {
    car->transform.rotate(180, 0, 1, 0);
    kill();
}

// Clase de la bomba
Bomb::Bomb(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, dim) {
    material.setEmissiveColor(ofColor::red);
}

void Bomb::update() {
    transform.move(0, -5, 0);
    if (transform.getY() < 0) explode();
}

void Bomb::draw() {
    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void Bomb::explode() {
    auto exp = new Explosion(game, transform.getPosition(), collider->getSize() * 10);
    game->addGameObject(exp);
    
    kill();
}

void Bomb::receiveCarCollision(Player* car) {
    car->init(car->getCoins());
    kill();
}