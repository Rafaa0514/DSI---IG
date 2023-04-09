#pragma once
#include "../ecs/Component.h"
#include "Shape.h"

class ObstacleAnimator : public Component {
private:
    Shape* shp;
    ofColor col;
public:
    static constexpr cmpId_type id = _OBSTACLE_ANIMATOR;
    ObstacleAnimator();
    virtual void initComponent();
    void activate();
};

