#include "Pedestrian.h"
#include "Player.h"
#include "Game.h"

Pedestrian::Pedestrian(Game *game, glm::vec3 pos, glm::vec3 dim, bool turn): GameObject(game, pos, dim){
    model.loadModel("../../src/resources/models/Pedestrian/astroBoy_walk.dae");
    
    collider->move(0, dim.y/2 - 25, 0);
    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0, -25, 0);
    model.setScale(0.25, 0.25, 0.25);
    model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
    model.playAllAnimations();
    
    transform.rotateDeg(90, 0, 1, 0);
    speed = 6;
    bTurned = false;

    canTurn = turn;
    lifeTime = 0.0;
}
Pedestrian::~Pedestrian(){
    
}

void Pedestrian::update() {
    model.update();
    transform.move(transform.getZAxis() * -speed);
    bTurned = false;
    lifeTime += ofGetLastFrameTime();
    if (lifeTime >= 5.5) kill();
};
void Pedestrian::draw(){
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();    
};
void Pedestrian::receiveCarCollision(Player *car) {
    kill();
    game->doScream();
    car->addCoins(100);
};

void Pedestrian::receiveBulletCollision(GameObject *bullet) {
    kill();
    bullet->kill();
    game->doScream();
    game->getPlayer()->addCoins(100);
 
};

void Pedestrian::turn(){
    if(!bTurned){
        transform.rotateDeg(180, 0, 1, 0);
        transform.move(transform.getZAxis() * -speed);
        bTurned = true;
    }
}


void Pedestrian::checkCollisions(){
    vector<GameObject*> collisions = game->getCollisions(this);
    for(auto c: collisions){
        c->receivePedestrianCollision(this);
    }
}
