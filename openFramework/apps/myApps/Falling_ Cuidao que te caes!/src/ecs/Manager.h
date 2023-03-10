#pragma once
#include <vector>
#include <array>
#include "ecs.h"


class Manager {
private:
	std::array<std::vector<Entity*>, maxGroupId> entsByGroup_;

	std::array<Entity*, maxHdlrId> hdlrs_;

public:
	Manager();
	virtual ~Manager();
	Entity* addEntity(grpId_type gId = _grp_GENERAL);
	void refresh();
	void update();
	void draw();
	void keyPressed(char k);
	inline void setHandler(hdlrId_type hId, Entity* e) {
		hdlrs_[hId] = e;
	}
	inline Entity* getHandler(hdlrId_type hId) {
		return hdlrs_[hId];
	}
	void removeEntities(grpId_type gId);

	const std::vector<Entity*>& getEntities(grpId_type gId = _grp_GENERAL);
};

