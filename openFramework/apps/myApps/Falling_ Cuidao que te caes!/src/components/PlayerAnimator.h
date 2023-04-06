#pragma once
#include "../ecs/Component.h"
#include "Shape.h"

class PlayerAnimator : public Component {
private:
    float flickerTime, flickerInterval;
    bool flicking;
    float flickingElapsedTime, intervalElapsedTime;
    Shape* shape;
public:
    static constexpr cmpId_type id = _PLAYER_ANIMATOR;

    PlayerAnimator() : flickerInterval(0.15), flickerTime(1.5), flicking(false), flickingElapsedTime(0), intervalElapsedTime(0) {};
    virtual void initComponent();
    
    void startFlicker();

    virtual void update();
};