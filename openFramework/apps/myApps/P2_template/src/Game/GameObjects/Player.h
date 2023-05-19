#pragma once
#include "ofMain.h"
#include "GameObject.h"
class Game;

// TODO add speed settings
#define MAX_SPEED 100.0f

enum PlayerState { NORMAL, TURBO, STUNNED, FALLING, PLANNING };

class Player : public GameObject{

    enum StunnedState { LEFT, RIGHT, STRAIGHT };

    float speed;
    bool bLight;
    glm::vec3 prevPos;
    int coins;

    float drsTime, drsElapsedTime;
    float planningTime, planningElsTime;

    PlayerState state;
    StunnedState st;
    int steers;
    
public:
    
    Player(Game *game);
    ~Player();
    
    void init(int numCoins = 0);
    void update() override;
    void draw() override;
    void drawDebug() override;
    void checkCollisions() override;
    float getSpeed();
    void setSpeed(float newS) { speed = newS; }
    
    void steerLeft();
    void steerRight();
    void accelerate();
    void toggleLight();
    void shoot();
    void brake();
    void stop();
    void addCoins(int n = 1);
    int getCoins();
    void setCoins(int n = 0) { coins = n; }

    inline PlayerState getPlayerState() { return state; }
    void setPlayerState(PlayerState value);
};