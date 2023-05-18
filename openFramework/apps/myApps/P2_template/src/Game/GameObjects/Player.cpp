#include "Player.h"
#include "Game.h"
#include "Bullet.h"

Player::Player(Game *game):GameObject(game, glm::vec3(100)){
    
    material.setDiffuseColor(ofColor::blue);
    
    faro.setParent(transform);
    faro.setDiffuseColor(ofColor::yellow);
    faro.setSpotlight();
    faro.move(0, 0, 50);
    faro.rotateDeg(-200, 1, 0, 0);
    state = NORMAL;
    st = LEFT;
    steers = 0;

    drsTime = 1.5f;
    drsElapsedTime = 0.0f;
    planningTime = 0.5f;
    planningElsTime = 0.0f;
}

Player::~Player(){}

void Player::init(int numCoins){
    transform.setPosition(0, 0, 0);
    transform.setOrientation(glm::vec3{0,0,0});
    speed = 0;
    bLight = false;
    state = NORMAL;
    st = LEFT;
    coins = numCoins;
}

void Player::update(){

    switch (state) {
        case NORMAL:
            prevPos = transform.getPosition();
            transform.move(transform.getZAxis() * speed);
            if (speed > MAX_SPEED) speed = MAX_SPEED;
            else if (speed < 0) accelerate();
        break;

        case TURBO:
            speed = MAX_SPEED / 4;
            prevPos = transform.getPosition();
            transform.move(transform.getZAxis() * speed);
            drsElapsedTime += ofGetLastFrameTime();
            if (drsElapsedTime >= drsTime) {
                drsElapsedTime = 0.0f;
                state = NORMAL;
                speed = 5;
            }
        break;

        case STUNNED:
            steers++;
            switch (st)
            {
            case Player::LEFT:
                steerLeft();
                if (steers >= 15) { st = RIGHT; steers = 0; }
                break;
            case Player::RIGHT:
                steerRight();
                if (steers >= 30) { st = STRAIGHT; steers = 0; }
                break;
            case Player::STRAIGHT:
                steerLeft();
                if (steers >= 15) { st = LEFT; state = NORMAL; steers = 0; }
                break;
            }
            prevPos = transform.getPosition();
            transform.move(transform.getZAxis() * speed);
        break;

        case FALLING:
            transform.move(0, -10, 0);
            if (transform.getY() < -750) { init(getCoins()); state = NORMAL; }
        break;

        case PLANNING:
            prevPos = transform.getPosition();
            transform.move(transform.getZAxis() * speed);
            planningElsTime += ofGetLastFrameTime();
            if (planningElsTime >= planningTime) {
                planningElsTime = 0.0f;
                state = NORMAL;
            }
        break;
    }
}

void Player::draw(){
    
    faro.draw();
    if(bLight)
        faro.enable();
    else
        faro.disable();
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void Player::drawDebug(){
    collider->drawDebug();
    
    transform.transformGL();
    ofDrawAxis(100);
    transform.restoreTransformGL();
}

void Player::checkCollisions(){
    vector<GameObject*> collisions = game->getCollisions(this);
    for(auto c: collisions){
        c->receiveCarCollision(this);
    }
}

void Player::steerLeft(){
    if (state != PLANNING) transform.rotateDeg(1, 0, 2, 0);
    else transform.rotateDeg(-4, 0, 1, 0);
}
void Player::steerRight(){
    if (state != PLANNING) transform.rotateDeg(-1, 0, 2, 0);
    else transform.rotateDeg(4, 0, 1, 0);
}
void Player::accelerate(){
    speed += 0.1;
}
void Player::brake(){
    if (speed == 0.1) stop();
    else speed -= 0.1;
}

void Player::stop(){
    speed = 0;
    transform.setPosition(prevPos);
}

void Player::toggleLight(){
    bLight = !bLight;
}

float Player::getSpeed(){
    return speed;
}

void Player::addCoins(int n){
    coins += n;
}

int Player::getCoins(){
    return coins;
}
void Player::shoot(){
    if (coins > 0) {
        game->addGameObject(new Bullet(game, transform));
        --coins;
    }
}