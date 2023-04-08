#pragma once
#include "../ecs/Component.h"
#include "Transform.h"
#include "Collider.h"

class WaveBehaviour : public Component {
private:
    Collider* col;
    Transform* tr;

    Entity* actor;    
    float increment;
public:
    static constexpr cmpId_type id = _WAVE;
    WaveBehaviour(Entity* act);
    virtual void initComponent();
    virtual void update();
    inline Entity* getActor() { return actor; }
};

