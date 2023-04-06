#pragma once
#include "../components/Collider.h"
#include "../components/LifeComponent.h"
#include "../components/PlayerAnimator.h"
#include "../components/AbilityComponent.h"
#include "../components/PowerUpComponent.h"
#include "../ecs/Manager.h"

class CollisionSystem {
private:
	Manager* mngr_;
	Collider* p1;
	Collider* p2;
	LifeComponent* pl1;
	LifeComponent* pl2;
	PlayerAnimator* pa1;
	PlayerAnimator* pa2;
	AbilityComponent* pab1;
	AbilityComponent* pab2;

	vector<Entity*> const& obs;
	vector<Entity*> const& pus;
public:
	CollisionSystem(Manager* mngr) : 
		mngr_(mngr), 
		p1(mngr->getHandler(_hdlr_DIESTRO)->getComponent<Collider>()), 
		p2 (mngr->getHandler(_hdlr_SINIESTRO)->getComponent<Collider>()),
		pl1(mngr->getHandler(_hdlr_DIESTRO)->getComponent<LifeComponent>()),
		pl2(mngr->getHandler(_hdlr_SINIESTRO)->getComponent<LifeComponent>()),
		pa1(mngr->getHandler(_hdlr_DIESTRO)->getComponent<PlayerAnimator>()),
		pa2(mngr->getHandler(_hdlr_SINIESTRO)->getComponent<PlayerAnimator>()),
		pab1(mngr->getHandler(_hdlr_DIESTRO)->getComponent<AbilityComponent>()),
		pab2(mngr->getHandler(_hdlr_SINIESTRO)->getComponent<AbilityComponent>()),
		obs(mngr->getEntities(_grp_OBSTACLE)), 
		pus(mngr->getEntities(_grp_POWERUP)) { }

	void update();

	bool collisionPwP();
	bool collisionPwO(Collider* p, LifeComponent* pl, PlayerAnimator* pa);
	bool collisionPwPU(Collider* p, AbilityComponent* pab);
};

