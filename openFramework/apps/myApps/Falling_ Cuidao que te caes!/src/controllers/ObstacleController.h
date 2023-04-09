#pragma once
#include "../ecs/Controller.h"
#include "../components/Transform.h"
#include "../components/Collider.h"
#include "../components/Shape.h"
#include "../components/ObstacleAnimator.h"

class ObstacleController : public Controller {
private:
	double counter, intervalTime;
public:
	ObstacleController(Manager* mngr) : Controller(mngr, 3, _grp_OBSTACLE), counter(0), intervalTime(10) {};

	virtual void generate() {
		Entity* e = mngr_->addEntity(group);
		e->addComponent<Transform>(Vector2D(ofRandom(ofGetWidth() - 100.0f), -100.0f), 100, 100, 0, Vector2D(0,250)); // POS ALEATORIA (x, -HEIGHT),
		e->addComponent<Shape>(_TRIANGLE, ofColor(255, 255, 255));
		e->addComponent<ObstacleAnimator>();
		e->addComponent<Collider>(50);
	}

	virtual void update() {
		Controller::addFrequently();

		counter += ofGetLastFrameTime();
		if (counter >= intervalTime) {
			if (spawnTime > 0.5) spawnTime -= 0.2;
			counter = 0;
		}
	}
};

