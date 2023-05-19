#ifndef MenuState_h
#define MenuState_h

#include "State.h"
#include "Game.h"

class MenuState: public State{
private:
    ofTrueTypeFont font;
    float titlePosX, titlePosY;
    float posX, posY;
    float alpha;
    bool increasing;
public:
    MenuState(Game* game);
    
    ~MenuState(){};
    
    void update() override;
    void draw() override;
    void next() override;
    void keyPressed(int key) override;
};
#endif 
