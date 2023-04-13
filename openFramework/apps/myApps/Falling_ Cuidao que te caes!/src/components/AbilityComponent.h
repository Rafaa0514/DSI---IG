#pragma once
#include <array>
#include "../ecs/Component.h"
#include "Transform.h"
#include "Shape.h"
#include "Collider.h"
#include "LifeTimeComponent.h"
#include "WaveBehaviour.h"
#include "GrappleBehaviour.h"
#include "ShieldBehaviour.h"

class AbilityComponent : public Component {
private:
    function<void(void)> abilities[3];
    Transform* tr;
    puType currentPU;

    array<ofSoundPlayer*, maxSound> gameSFX;
    sounds mySound;

public:
    static constexpr cmpId_type id = _ABILITY_COMPONENT;

    AbilityComponent(array<ofSoundPlayer*,maxSound> s) : currentPU(noPU), gameSFX(s) {
        abilities[wave] = [&]() {
            Entity* e = mngr_->addEntity(_grp_PUOBJECT);
            e->addComponent<Transform>(tr->getPosition(), tr->getWidth(), tr->getHeight());
            e->addComponent<Shape>(_CIRCLE, ofColor(255, 255, 0), false);
            e->addComponent<Collider>(tr->getWidth()/2);
            e->addComponent<LifeTimeComponent>(1);
            e->addComponent<WaveBehaviour>(getEntity());
            mySound = BOMB;
        };
        abilities[grapple] = [&]() {
            Entity* e = mngr_->addEntity(_grp_PUOBJECT);
            e->addComponent<Transform>(tr->getPosition() + Vector2D(0, 2 * tr->getHeight() / 6), tr->getWidth(), tr->getHeight() / 3);
            e->addComponent<Shape>(_RECTANGLE, ofColor(200, 0, 200));
            e->addComponent<LifeTimeComponent>(1.5);
            e->addComponent<GrappleBehaviour>(tr, (tr->getEntity() == mngr_->getHandler(_hdlr_DIESTRO)) ? 
                mngr_->getHandler(_hdlr_SINIESTRO)->getComponent<Transform>() : 
                mngr_->getHandler(_hdlr_DIESTRO)->getComponent<Transform>());
            mySound = GRAPPLE;
        };
        abilities[shield] = [&]() {
            Entity* e = mngr_->addEntity(_grp_PUOBJECT);
            e->addComponent<Transform>(tr->getPosition() - Vector2D(0, tr->getHeight() / 4), tr->getWidth(), tr->getHeight() / 2);
            e->addComponent<Shape>(_CIRCLE, ofColor(255, 100, 0), false);
            e->addComponent<Collider>(tr->getWidth());
            e->addComponent<LifeTimeComponent>(3);
            e->addComponent<ShieldBehaviour>(tr);
            mySound = SHIELD;
        };
    }

    virtual void initComponent();

    void activate();

    inline void pickPowerUp(puType pu) {
        if (!hasAbility()) currentPU = pu;
    }

    inline bool hasAbility() { return currentPU != noPU; }
};