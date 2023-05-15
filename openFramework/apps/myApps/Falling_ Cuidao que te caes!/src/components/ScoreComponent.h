#pragma once
#include "../ecs/Component.h"

const int SCORE_LEFT_X = 20;
const int SCORE_RIGHT_X = 1920 - 20;
const int SCORE_Y = 100;

class ScoreComponent : public Component {
private:
    int score;
    int scoreIncrease;
    int scorePenalty;
    float counter, increaseInterval;
    ofColor color;
    int posX;
    ofTrueTypeFont font;
    bool stop;

public:
    static constexpr cmpId_type id = _SCORE;
    ScoreComponent();

    virtual void initComponent();
    virtual void update();
    virtual void draw();

    inline void applyPenalty() { score -= scorePenalty; }
    inline void stopCounting() { stop = true; }

    inline int getScore() { return score; }
};