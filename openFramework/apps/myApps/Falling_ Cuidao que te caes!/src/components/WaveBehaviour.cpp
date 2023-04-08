#include "WaveBehaviour.h"
#include "../ecs/Entity.h"

WaveBehaviour::WaveBehaviour(Entity* act) : actor(act), col(nullptr), tr(nullptr), increment(5) {}

void WaveBehaviour::initComponent() {
    tr = ent_->getComponent<Transform>();
    col = ent_->getComponent<Collider>();
}
void WaveBehaviour::update() {
    tr->setPosition(tr->getPosition() - Vector2D(increment / 2, increment / 2));
    tr->setWidth(tr->getWidth() + increment);
    tr->setHeight(tr->getHeight() + increment);
    col->setRadious(col->getRadious() + increment/2);
}