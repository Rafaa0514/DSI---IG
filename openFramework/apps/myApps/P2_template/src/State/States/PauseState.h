#pragma once
#include "State.h"
#include "Game.h"

class PauseState : public State {
private:
    ofTrueTypeFont font;
    float posX, posY;

public:
    PauseState(Game* g);
    void update() override;
    void draw() override;
    void next() override;
    void keyPressed(int key) override;
};