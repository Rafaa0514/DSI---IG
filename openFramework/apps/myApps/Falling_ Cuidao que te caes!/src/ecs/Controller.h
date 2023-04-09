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
	Controller(Manager* mngr, double spawnT, grpId_type gr) : mngr_(mngr), startTime(ofGetCurrentTime().getAsSeconds()), currentTime(startTime), spawnTime(spawnT), group(gr) {}

	virtual void generate() = 0;

	inline void addFrequently() {
		if (currentTime - startTime > spawnTime) {
			startTime = currentTime;
			generate();
		}
		currentTime = ofGetCurrentTime().getAsSeconds();
	}

	void destroyAll() {
		mngr_->removeEntities(group);
	}

	virtual void update() { }
};