#pragma once
#include "../ecs/Controller.h"

class ObstacleController : public Controller {
public:
	ObstacleController(Manager* mngr) : Controller(mngr, 3, _grp_OBSTACLE) {};
	virtual void generate() {
		Entity* e = mngr_->addEntity(group);
		//e->addComponent<Transform>();
	}

	virtual void onCollision(Entity* e, hdlrId_type player) {

	}
};

