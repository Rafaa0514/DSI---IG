#include "Manager.h"
#include "Entity.h"

Manager::Manager() :
	hdlrs_(), entsByGroup_() {
	for (auto& groupEntities : entsByGroup_) {
		groupEntities.reserve(100);
	}
}
Manager::~Manager() {
	for (auto& ents : entsByGroup_) {
		for (auto e : ents)
			delete e;
	}
}

Entity* Manager::addEntity(grpId_type gId) {
	Entity* e = new Entity();
	e->setAlive(true);
	e->setContext(this);
	entsByGroup_[gId].push_back(e);
	return e;
}

void Manager::refresh() {
	for (grpId_type gId = 0; gId < maxGroupId; gId++) {
		auto& grpEnts = entsByGroup_[gId];
		grpEnts.erase(
			std::remove_if(grpEnts.begin(), grpEnts.end(),
				[](Entity* e) {
					if (e->isAlive()) {
						return false;
					}
					else {
						delete e;
						return true;
					}
				}),
			grpEnts.end());
	}
}

const std::vector<Entity*>& Manager::getEntities(grpId_type gId) {
	return entsByGroup_[gId];
}

void Manager::update() {
	for (auto& ents : entsByGroup_) {
		auto n = ents.size();
		for (auto i = 0u; i < n; i++)
			ents[i]->update();
	}
}
void Manager::draw() {
	for (auto& ents : entsByGroup_) {
		auto n = ents.size();
		for (auto i = 0u; i < n; i++) {
			ofPushMatrix();
			ents[i]->draw();
			ofPopMatrix();
		}
	}
}
void Manager::keyPressed(char k) {
	for (auto& ents : entsByGroup_) {
		auto n = ents.size();
		for (auto i = 0u; i < n; i++)
			ents[i]->keyPressed(k);
	}
}
void Manager::keyReleased(char k) {
	for (auto& ents : entsByGroup_) {
		auto n = ents.size();
		for (auto i = 0u; i < n; i++)
			ents[i]->keyReleased(k);
	}
}
void Manager::removeEntities(grpId_type gId) {
	for (Entity* e : entsByGroup_[gId]) {
		e->setAlive(false);
	}
}
