
#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(Game *game, ofNode otherTransform)
    :GameObject(game, otherTransform.getGlobalPosition(), glm::vec3(10))
{
        transform.setGlobalOrientation(otherTransform.getGlobalOrientation());
    material.setEmissiveColor(ofColor::red);
    lifeTime = 0;
}

Bullet::~Bullet(){}

void Bullet::update(){
    transform.move(transform.getZAxis() * 100);
    lifeTime += ofGetLastFrameTime();
    if (lifeTime >= 1.5) kill();
};

void Bullet::draw(){
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
    
};

void Bullet::checkCollisions(){
    vector<GameObject*> collisions = game->getCollisions(this);
    for(auto c: collisions){
        c->receiveBulletCollision(this);
    }
}
