#pragma once
#include "../components/Collider.h"
#include "../components/ObstacleAnimator.h"
#include "../components/LifeComponent.h"
#include "../components/PlayerAnimator.h"
#include "../components/AbilityComponent.h"
#include "../components/ScoreComponent.h"
#include "../components/PowerUpComponent.h"
#include "../components/GrappleBehaviour.h"
#include "../components/WaveBehaviour.h"
#include "../ecs/Manager.h"

class CollisionSystem {
private:
	Manager* mngr_;
	Transform* tr1;
	Transform* tr2;
	Collider* p1;
	Collider* p2;
	LifeComponent* pl1;
	LifeComponent* pl2;
	PlayerAnimator* pa1;
	PlayerAnimator* pa2;
	AbilityComponent* pab1;
	AbilityComponent* pab2;
	ScoreComponent* ps1;
	ScoreComponent* ps2;


	vector<Entity*> const& obs;
	vector<Entity*> const& pus;
	vector<Entity*> const& abs;
public:
	CollisionSystem(Manager* mngr) : 
		mngr_(mngr),
		p1(mngr->getHandler(_hdlr_DIESTRO)->getComponent<Collider>()), 
		p2 (mngr->getHandler(_hdlr_SINIESTRO)->getComponent<Collider>()),
		tr1(mngr->getHandler(_hdlr_DIESTRO)->getComponent<Transform>()),
		tr2(mngr->getHandler(_hdlr_SINIESTRO)->getComponent<Transform>()),
		pl1(mngr->getHandler(_hdlr_DIESTRO)->getComponent<LifeComponent>()),
		pl2(mngr->getHandler(_hdlr_SINIESTRO)->getComponent<LifeComponent>()),
		pa1(mngr->getHandler(_hdlr_DIESTRO)->getComponent<PlayerAnimator>()),
		pa2(mngr->getHandler(_hdlr_SINIESTRO)->getComponent<PlayerAnimator>()),
		pab1(mngr->getHandler(_hdlr_DIESTRO)->getComponent<AbilityComponent>()),
		pab2(mngr->getHandler(_hdlr_SINIESTRO)->getComponent<AbilityComponent>()),
		ps1(mngr->getHandler(_hdlr_DIESTRO)->getComponent<ScoreComponent>()),
		ps2(mngr->getHandler(_hdlr_SINIESTRO)->getComponent<ScoreComponent>()),
		obs(mngr->getEntities(_grp_OBSTACLE)), 
		pus(mngr->getEntities(_grp_POWERUP)),
		abs(mngr->getEntities(_grp_PUOBJECT)) { }

	void update();

	bool collisionPwP();
	bool collisionPwO(Collider* p);
	bool collisionPwPU(Collider* p, AbilityComponent* pab);
	bool collisionABwO();
	bool collisionABwP(Transform* pt, Collider* p);
};

