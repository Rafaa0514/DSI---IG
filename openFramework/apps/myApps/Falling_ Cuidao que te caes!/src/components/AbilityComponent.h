#pragma once
#include "../ecs/Component.h"
#include "Transform.h"
#include "Shape.h"
#include "Collider.h"
#include "LifeTimeComponent.h"
//#include "WaveBehaviour.h"
//#include "GrappleBehaviour.h"

class AbilityComponent : public Component {
private:
    function<void(void)> abilities[3];
    Transform* tr;
    puType currentPU;
public:
    static constexpr cmpId_type id = _ABILITY_COMPONENT;
    AbilityComponent() : currentPU(noPU) {
        abilities[wave] = [&]() {
            Entity* e = mngr_->addEntity();
            e->addComponent<Transform>(tr->getPosition(), tr->getWidth(), tr->getHeight());
            e->addComponent<Shape>(_CIRCLE, ofColor(255, 255, 0));
            e->addComponent<Collider>(10);
            e->addComponent<LifeTimeComponent>(2);
            //e->addComponent<WaveBehaviour>();
        };
        abilities[grapple] = [&]() {
            Entity* e = mngr_->addEntity();
            e->addComponent<Transform>(tr->getPosition(), tr->getWidth(), tr->getHeight() / 3);
            e->addComponent<Shape>(_RECTANGLE, ofColor(255, 255, 0));
            e->addComponent<LifeTimeComponent>(1);
            //e->addComponent<GrappleBehaviour>();
        };
        abilities[shield] = [&]() {
            Entity* e = mngr_->addEntity();
            e->addComponent<Transform>(tr->getPosition(), tr->getWidth(), tr->getHeight() / 3);
            e->addComponent<Shape>(_CIRCLE, ofColor(255, 255, 0));
            e->addComponent<Collider>(tr->getWidth());
            e->addComponent<LifeTimeComponent>(3);
        };
    }

    virtual void initComponent();

    void activate();

    inline void pickPowerUp(puType pu) {
        currentPU = pu;    
    }
};