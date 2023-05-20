#include "Player.h"
#include "Game.h"
#include "Bullet.h"

Player::Player(Game *game):GameObject(game, glm::vec3(100)){
    // Material
    material.setDiffuseColor(ofColor::blue);

    // Estados y contador
    state = NORMAL;
    st = LEFT;
    steers = 0;
    coins = 0;
    speed = 0;
    bLight = false;

    // Tiempos
    drsTime = 1.5f;
    drsElapsedTime = 0.0f;
    planningTime = 0.5f;
    planningElsTime = 0.0f;
}

Player::~Player(){}

void Player::init(int numCoins){
    // Posicion y orientacion inicial
    transform.setPosition(0, 0, 0);
    transform.setOrientation(glm::vec3{0,0,0});
    // Variables al estado inicial
    speed = 0;
    state = NORMAL;
    st = LEFT;
    coins = numCoins;
}

void Player::update(){

    switch (state) {
        // Si no tengo ningun estado simnplemente me muevo
        case NORMAL:
            prevPos = transform.getPosition();
            transform.move(transform.getZAxis() * speed);
            if (speed > MAX_SPEED) speed = MAX_SPEED;
            else if (speed < 0) accelerate();
        break;

        // Si tengo activado el DRS voy mas rapido y cuento el tiempo
        case TURBO:
            speed = MAX_SPEED / 4;
            prevPos = transform.getPosition();
            transform.move(transform.getZAxis() * speed);
            drsElapsedTime += ofGetLastFrameTime();
            if (drsElapsedTime >= drsTime) {
                drsElapsedTime = 0.0f;
                state = NORMAL;
            }
        break;

        // Si he resbalado con el aceite
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

        // Si me tengo que caer
        case FALLING:
            transform.move(0, -10, 0);
            if (transform.getY() < -750) { init(getCoins()); state = NORMAL; }
        break;

        // Si estoy en el agua
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

void Player::setPlayerState(PlayerState value) {
    if (state != value) {
        state = value;
        
        switch (value) {
            case TURBO: game->playSound(TURBO_SFX); break;
            case STUNNED: game->playSound(OIL_SFX); break;
            case FALLING: game->playSound(PIT_SFX); break;
        }
    }
}