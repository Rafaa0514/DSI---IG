#pragma once
#include "../ecs/Controller.h"
#include "../components/Transform.h"
#include "../components/Collider.h"
#include "../components/Shape.h"

class ObstacleController : public Controller {
public:
	ObstacleController(Manager* mngr) : Controller(mngr, 1, _grp_OBSTACLE) {};
	virtual void generate() {
		Entity* e = mngr_->addEntity(group);
		e->addComponent<Transform>(Vector2D(ofRandom(ofGetWidth()), -100.0f), 100, 100, 0, Vector2D(0,250)); // POS ALEATORIA (x, -HEIGHT),
		e->addComponent<Shape>(_TRIANGLE, ofColor(0,0,0));
		e->addComponent<Collider>(50);
	}

	virtual void onCollision(Entity* e, hdlrId_type player) {

	}
};

