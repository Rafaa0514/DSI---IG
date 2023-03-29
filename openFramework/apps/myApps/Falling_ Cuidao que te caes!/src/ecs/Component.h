#pragma once
#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <cassert>
#include "ecs.h"
class Entity;
class Manager;

class Component {
protected:
	Entity* ent_;
	Manager* mngr_;
public: 
	Component() {}  
	virtual ~Component() {}
	inline void setContext(Entity* ent, Manager* mngr) {
		ent_ = ent;
		mngr_ = mngr;
	}
	virtual void initComponent() { }
	virtual void update() { }
	virtual void draw() { }
	virtual void keyPressed(char k) { }
	virtual void keyReleased(char k) { }
	inline Entity* getEntity() { return ent_; }
};

#endif