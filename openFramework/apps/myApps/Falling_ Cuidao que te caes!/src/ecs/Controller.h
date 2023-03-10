#pragma once
#include "Manager.h"
#include "Entity.h"
#include "../ofMain.h"
class Controller
{
protected:
	Manager* mngr_;
	double spawnTime, startTime, currentTime;
	grpId_type group;
public:
	Controller(Manager* mngr, double sT, grpId_type gr) : mngr_(mngr), startTime(ofGetCurrentTime().getAsSeconds()), currentTime(startTime), spawnTime(sT), group(gr) {}

	virtual void generate() = 0;
	inline void addFrequently() {
		if (currentTime - startTime > spawnTime) {
			startTime = currentTime;
			generate();
		}
		currentTime = ofGetCurrentTime().getAsSeconds();
	}
	virtual void onCollision(Entity* e, hdlrId_type player) = 0;
	void destroyAll() {
		mngr_->removeEntities(group);
	}
};

