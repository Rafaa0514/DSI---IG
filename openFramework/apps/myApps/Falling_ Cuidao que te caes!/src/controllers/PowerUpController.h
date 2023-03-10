#pragma once
#include "../ecs/Controller.h"
#include "../components/Transform.h"
//#include "../components/PowerUpAnimator.h"
#include "../components/DisableOnExit.h"
//#include "../components/PowerUpComponent.h"
//#include "../components/Collider.h"
#include <functional>

using namespace std;

enum puType {
	wave,
	grapple,
	shield
};

class PowerUpController : public Controller {
public:
	PowerUpController(Manager* m) : Controller(m, 10, _grp_POWERUP) {}

	void waveFunc() {

	}
	void grappleFunc() {

	}
	void shieldFunc() {

	}

	virtual void generate() {
		Entity* e = mngr_->addEntity(group);
		e->addComponent<Transform>(Vector2D(0,0), 1, 1);
		//e->addComponent<PowerUpAnimator>();
		e->addComponent<DisableOnExit>();
		//e->addComponent<PowerUpComponent>((puType)ofRandom(3));
		//e->addComponent<Collider>();
	}

	virtual void onCollision(Entity* e, hdlrId_type player) {

	}
};