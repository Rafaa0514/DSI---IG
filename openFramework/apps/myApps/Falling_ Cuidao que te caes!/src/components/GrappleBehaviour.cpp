#include "GrappleBehaviour.h"
#include "../ecs/Entity.h"

GrappleBehaviour::GrappleBehaviour(Transform* act, Transform* trg): actorTr(act), targetTr(trg), tr(nullptr), grappleSpeed(350) {}

void GrappleBehaviour::initComponent() {
    tr = ent_->getComponent<Transform>();
}

void GrappleBehaviour::update() {
    if (targetTr->getX() > ofGetWidth() * 1.5) {
        ent_->setAlive(false);
    }
    else {
        float direction = targetTr->getX() - actorTr->getX();

        direction /= std::abs(direction);
        targetTr->setVelX(grappleSpeed * -direction);

        if (direction > 0) {
            tr->setWidth(targetTr->getX() - (actorTr->getX() + actorTr->getWidth()));
            tr->setX(actorTr->getX() + actorTr->getWidth());
        }
        else {
            tr->setWidth(actorTr->getX() - (targetTr->getX() + targetTr->getWidth()));
            tr->setX(actorTr->getX() - tr->getWidth());
        }

        if (tr->getWidth() < 50) ent_->setAlive(false);
    }
}