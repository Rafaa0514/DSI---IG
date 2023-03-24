#include "Collider.h"

void Collider::initComponent() {
	tr = ent_->getComponent<Transform>();
}

bool Collider::collidesWith(Collider* other) {
	return (this->tr->getCenter() - other->tr->getCenter()).magnitude() <= this->radious + other->radious;
}