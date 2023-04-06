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

	collisionPwO(p1, pl1, pa1);
	collisionPwO(p2, pl2, pa2);
	collisionPwPU(p1, pab1);
	collisionPwPU(p2, pab2);
}

bool CollisionSystem::collisionPwP() {
	return p1->collidesWith(p2) && p2->collidesWith(p1);
}

bool CollisionSystem::collisionPwO(Collider* p, LifeComponent* pl, PlayerAnimator* pa) {
	for (Entity* o : obs) {
		if (o->isAlive() && p->collidesWith(o->getComponent<Collider>())) {
			if (pl->reduceLifes()) 
				pa->startFlicker();
			o->setAlive(false);
			return true;
		}
	}
	return false;
}

bool CollisionSystem::collisionPwPU(Collider* p, AbilityComponent* pab) {
	for (Entity* pu : pus) {
		if (pu->isAlive() && p->collidesWith(pu->getComponent<Collider>())) {
			pab->pickPowerUp(pu->getComponent<PowerUpComponent>()->getType());
			pu->setAlive(false);
			return true;
		}
	}
}