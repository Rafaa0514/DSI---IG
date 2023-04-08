#include "CollisionSystem.h"

void CollisionSystem::update() {
	if (collisionPwP()) {
		//MANDAR MENSAJE DE INTERCAMBIAR VELOCIDADES DE JUGADORES
		Vector2D v1 = tr1->getVelocity();
		Vector2D v2 = tr2->getVelocity();
		tr1->setVelocity(v2);
		tr2->setVelocity(v1);
	}

	collisionPwO(p1, pl1, pa1);
	collisionPwO(p2, pl2, pa2);
	collisionPwPU(p1, pab1);
	collisionPwPU(p2, pab2);

	collisionABwO();
	collisionABwP(tr1, p1);
	collisionABwP(tr2, p2);
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
	return false;
}


bool CollisionSystem::collisionABwO() {
	for (Entity* ab : abs) {
		if (ab->isAlive() && !ab->hasComponent<GrappleBehaviour>()) {
			Collider* abC = ab->getComponent<Collider>();
			for (Entity* ob : obs) {
				if (ob->isAlive() && ob->getComponent<Collider>()->collidesWith(abC)) {
					ob->setAlive(false);
					return true;
				}
			}
		}
	}
	return false;
}

bool CollisionSystem::collisionABwP(Transform* pt, Collider* p) {
	for (Entity* ab : abs) {
		if (ab->isAlive()) {
			if (ab->hasComponent<WaveBehaviour>()) {
				Collider* abC = ab->getComponent<Collider>();
				if (p->collidesWith(abC) && ab->getComponent<WaveBehaviour>()->getActor() != p->getEntity()) {
					Transform* abTr = abC->getEntity()->getComponent<Transform>();
					int direction = (pt->getX() - abTr->getX()) / std::abs(pt->getX() - abTr->getX());
					pt->setVelocity(Vector2D(direction * 800, 0));
					return true;
				}
			}

			/*else if (ab->hasComponent<GrappleBehaviour>()) {
				Collider* abC = ab->getComponent<Collider>();
				if (p->collidesWith(abC)) {
					
					return true;
				}
			}*/
		}
	}
	return false;
}