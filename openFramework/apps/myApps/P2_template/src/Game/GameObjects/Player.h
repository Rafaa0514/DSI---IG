#ifndef Player_h
#define Player_h

#include "ofMain.h"
#include "GameObject.h"
class Game;

// TODO add speed settings
#define MAX_SPEED 100

class Player : public GameObject{

    enum StunnedState { LEFT, RIGHT, STRAIGHT};
    
    ofLight faro;
    float speed;
    bool bLight;
    glm::vec3 prevPos;
    int coins;
    bool stunned;

    StunnedState st;
    int steers;
    
public:
    
    Player(Game *game);
    ~Player();
    
    void init();
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

    inline bool getStunned() { return stunned; }
    inline void setStunned(bool value) { 
        if (!stunned) { 
            stunned = value; 
            steers = 0;
            speed /= 2;
        } 
    }
};

#endif 
