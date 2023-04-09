#pragma once
#include "../ecs/Controller.h"
#include "../components/Transform.h"
#include "../components/PowerUpAnimator.h"
#include "../components/DisableOnExit.h"
#include "../components/PowerUpComponent.h"
#include "../components/Collider.h"
#include "../components/Shape.h"
#include <functional>

using namespace std;


class PowerUpController : public Controller {
private:
	bool spawn;
	double counter, intervalTime;
	ofColor cols[3];
public:
	PowerUpController(Manager* m) : Controller(m, 5, _grp_POWERUP), spawn(false), counter(0), intervalTime(10) {
		cols[0] = ofColor(255, 255, 0);
		cols[1] = ofColor(200, 0, 200);
		cols[2] = ofColor(255, 100, 0);
	}

	virtual void generate() {
		puType t = (puType)ofRandom(3);
		Entity* e = mngr_->addEntity(group);
		e->addComponent<Transform>(Vector2D(ofRandom(ofGetWidth() - 100.0f), -100.0f), 100, 100, 0, Vector2D(0,250));
		e->addComponent<Shape>(_CIRCLE, cols[t]);
		e->addComponent<PowerUpAnimator>();
		e->addComponent<DisableOnExit>();
		e->addComponent<PowerUpComponent>(t);
		e->addComponent<Collider>(55);
	}

	virtual void update() {
		if (!spawn) {
			counter += ofGetLastFrameTime();
			if (counter > intervalTime) {
				counter = 0;
				spawn = true;
			}
		}

		else Controller::addFrequently();
	}
};