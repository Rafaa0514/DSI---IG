#include "Coin.h"
#include "Player.h"
#include "Game.h"


Coin::Coin(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos, dim) {
    model.loadModel("../../src/resources/models/coin.FBX");
    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0, -20, 0);
    model.setScale(0.1, 0.1, 0.1);
}

Coin::~Coin(){
    
}


void Coin::update(){
    model.update();
}

void Coin::draw(){
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}

void Coin::receiveCarCollision(Player *car){
    car->addCoins(5);
    game->playSound(COIN_SFX);
    kill();
}

void Coin::receiveBulletCollision(GameObject *bullet){
    bullet->kill();
    kill();
    game->getPlayer()->addCoins(1000);
    game->playSound(COIN_SFX);
}
