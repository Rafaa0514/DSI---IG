#include "CollisionSystem.h"

void CollisionSystem::update() {
	if (collisionPwP()) {
		//MANDAR MENSAJE DE INTERCAMBIAR VELOCIDADES DE JUGADORES
		Vector2D v1 = tr1->getVelocity();
		Vector2D v2 = tr2->getVelocity();
		tr1->setVelocity(v2);
		tr2->setVelocity(v1);

		if (std::abs(tr1->getCenter().getX() - tr2->getCenter().getX()) < p1->getRadious() + p2->getRadious()) {
			float centralPoint = (tr1->getCenter().getX() + tr2->getCenter().getX()) / 2;
			float orientation = tr1->getX() - tr2->getX();

			// tr1 a la derecha y tr2 a la izquierda
			if (orientation > 0) {
				tr1->setX(centralPoint);
				tr2->setX(centralPoint - tr2->getWidth());
			}
			// tr2 a la derecha y tr1 a la izquierda
			else {
				tr2->setX(centralPoint);
				tr1->setX(centralPoint - tr1->getWidth());
			}
		}
	}

	if (collisionPwO(p1)) {
		if(pl1->reduceLifes())
			pa1->startFlicker();
		ps1->applyPenalty();
		damage->play();
	}

	if (collisionPwO(p2)) {
		if (pl2->reduceLifes())
			pa2->startFlicker();	
		ps2->applyPenalty();
		damage->play();
	}


	if (collisionPwPU(p1, pab1)) powerUp->play();
	if (collisionPwPU(p2, pab2)) powerUp->play();

	collisionABwO();
	collisionABwP(tr1, p1);
	collisionABwP(tr2, p2);
}

bool CollisionSystem::collisionPwP() {
	return p1->collidesWith(p2) && p2->collidesWith(p1);
}

bool CollisionSystem::collisionPwO(Collider* p) {
	for (Entity* o : obs) {
		if (o->isAlive() && o->hasComponent<Collider>() && p->collidesWith(o->getComponent<Collider>())) {
			o->removeComponent<Collider>();
			o->getComponent<ObstacleAnimator>()->activate();
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
				if (ob->isAlive() && ob->hasComponent<Collider>() && ob->getComponent<Collider>()->collidesWith(abC)) {
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
		}
	}
	return false;
}