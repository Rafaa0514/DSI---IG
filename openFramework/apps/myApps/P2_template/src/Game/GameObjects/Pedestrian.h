
#ifndef Person_h
#define Person_h

#include "GameObject.h"

#include "ofxAssimpModelLoader.h"

class Pedestrian : public GameObject{
    float speed = -5;
    bool bTurned;
    bool canTurn;

public:
    Pedestrian(Game *game, glm::vec3 pos, glm::vec3 dim, bool turn = false);
    ~Pedestrian();
    
    void update() override;
    void draw() override;
    void receiveCarCollision(Player *car) override;
    void receiveBulletCollision(GameObject *bullet) override;
    
    void checkCollisions() override;
    void turn();
    ofxAssimpModelLoader model;

    bool getCanTurn() { return canTurn; }
};


#endif /* Person_h */
