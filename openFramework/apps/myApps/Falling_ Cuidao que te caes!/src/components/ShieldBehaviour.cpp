#include "ShieldBehaviour.h"

ShieldBehaviour::ShieldBehaviour(Transform* actTr) : actorTr(actTr) {}

void ShieldBehaviour::initComponent() {
    tr = ent_->getComponent<Transform>();
}

void ShieldBehaviour::update() {
    tr->setX(actorTr->getX());
}
