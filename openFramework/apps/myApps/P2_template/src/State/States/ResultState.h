#ifndef ResultState_h
#define ResultState_h

#include "State.h"
class Game;

class ResultState: public State{
private:
    ofTrueTypeFont font;

    float titlePosX, titlePosY;
    float posX, posY;
    float alpha;
    bool increasing;

public:
    ResultState(Game *game);
    
    ~ResultState();
    
    void update();
    void draw();
    void next();
    void keyPressed(int key) override;
};

#endif /* ResultState_h */
