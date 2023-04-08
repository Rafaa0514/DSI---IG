#pragma once
#include "../ecs/Component.h"
#include "Transform.h"

class ShieldBehaviour : public Component {

private:
    Transform* tr;
    Transform* actorTr;
public:
    static constexpr cmpId_type id = _SHIELD;
    ShieldBehaviour(Transform* actTr);
    virtual void initComponent();
    virtual void update();
};