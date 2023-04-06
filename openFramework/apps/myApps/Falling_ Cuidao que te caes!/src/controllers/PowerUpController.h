#pragma once
#include "../ecs/Controller.h"
#include "../components/Transform.h"
//#include "../components/PowerUpAnimator.h"
#include "../components/DisableOnExit.h"
#include "../components/PowerUpComponent.h"
#include "../components/Collider.h"
#include "../components/Shape.h"
#include <functional>

using namespace std;


class PowerUpController : public Controller {
public:
	PowerUpController(Manager* m) : Controller(m, 1, _grp_POWERUP) {}

	void waveFunc() {

	}
	void grappleFunc() {

	}
	void shieldFunc() {

	}

	virtual void generate() {
		Entity* e = mngr_->addEntity(group);
		e->addComponent<Transform>(Vector2D(ofRandom(ofGetWidth()), -100.0f), 100, 100, 0, Vector2D(0,250));
		//e->addComponent<PowerUpAnimator>();
		e->addComponent<Shape>(_CIRCLE, ofColor(255, 255, 0));
		e->addComponent<DisableOnExit>();
		e->addComponent<PowerUpComponent>((puType)ofRandom(3));
		e->addComponent<Collider>(55);
	}

	virtual void onCollision(Entity* e, hdlrId_type player) {

	}
};