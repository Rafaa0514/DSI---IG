#include "CollisionSystem.h"

void CollisionSystem::update() {
	if (collisionPwP()) {
		//MANDAR MENSAJE DE INTERCAMBIAR VELOCIDADES DE JUGADORES
		Transform* tr1 = p1->getEntity()->getComponent<Transform>();
		Transform* tr2 = p2->getEntity()->getComponent<Transform>();
		Vector2D v1 = tr1->getVelocity();
		Vector2D v2 = tr2->getVelocity();
		tr1->setVelocity(v2);
		tr2->setVelocity(v1);
	}

	collisionPwO(p1);
	collisionPwO(p2);
	collisionPwPU(p1);
	collisionPwPU(p2);
}

bool CollisionSystem::collisionPwP() {
	return p1->collidesWith(p2) && p2->collidesWith(p1);
}

bool CollisionSystem::collisionPwO(Collider* p) {
	for (Entity* o : obs) {
		if (o->isAlive() && p->collidesWith(o->getComponent<Collider>())) {
			// LE QUITAMOS AL JUGADOR UNA VIDA
			o->setAlive(false);
			return true;
		}
	}
	return false;
}

bool CollisionSystem::collisionPwPU(Collider* p) {
	for (Entity* pu : pus) {
		if (pu->isAlive() && p->collidesWith(pu->getComponent<Collider>())) {
			// APLICAMOS EL POWER UP
			pu->setAlive(false);
			return true;
		}
	}
}