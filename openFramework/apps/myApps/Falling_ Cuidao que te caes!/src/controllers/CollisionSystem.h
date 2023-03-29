#pragma once
#include "../components/Collider.h"
#include "../ecs/Manager.h"

class CollisionSystem {
private:
	Manager* mngr_;
	Collider* p1;
	Collider* p2;

	vector<Entity*> const& obs;
	vector<Entity*> const& pus;
public:
	CollisionSystem(Manager* mngr) : 
		mngr_(mngr), 
		p1(mngr->getHandler(_hdlr_DIESTRO)->getComponent<Collider>()), 
		p2 (mngr->getHandler(_hdlr_SINIESTRO)->getComponent<Collider>()), 
		obs(mngr->getEntities(_grp_OBSTACLE)), 
		pus(mngr->getEntities(_grp_POWERUP)) { }

	void update();

	bool collisionPwP();
	bool collisionPwO(Collider* p);
	bool collisionPwPU(Collider* p);
};

