#pragma once
#ifndef ENTITY_H_
#define ENTITY_H_

#include <iostream>
#include <array>
#include <vector>
#include "Component.h"
#include "Manager.h"


class Entity {
private:
	bool alive_;
	Manager* mngr_;
	std::vector<Component*> currCmps_;
	std::array<Component*, maxComponentId> cmps_;
public:
	Entity() : mngr_(nullptr), cmps_(), currCmps_(), alive_() {
		currCmps_.reserve(maxComponentId);
	}
	virtual ~Entity() {
		for (auto c : currCmps_) {
			delete c;
		}
	}
	inline void setContext(Manager* mngr) { mngr_ = mngr; }
	inline bool isAlive() { return alive_; }
	inline void setAlive(bool alive) { alive_ = alive; }
	template<typename T, typename ...Ts>
	inline T* addComponent(Ts&& ...args) {
		T* c = new T(std::forward<Ts>(args)...);
		removeComponent<T>();
		currCmps_.push_back(c);
		cmps_[T::id] = c;
		c->setContext(this, mngr_);
		c->initComponent();
		return c;
	}
	template<typename T>
	inline void removeComponent() {
		if (cmps_[T::id] != nullptr) {
			auto iter = std::find(currCmps_.begin(),
				currCmps_.end(),
				cmps_[T::id]);
			currCmps_.erase(iter);
			delete cmps_[T::id];
			cmps_[T::id] = nullptr;
		}
	}
	template<typename T>
	inline T* getComponent() {
		return static_cast<T*>(cmps_[T::id]);
	}
	template<typename T>
	inline bool hasComponent() {
		return cmps_[T::id] != nullptr;
	}
	inline void update() {
		auto n = currCmps_.size();
		for (auto i = 0u; i < n; i++)
			currCmps_[i]->update();
	}
	inline void draw() {
		auto n = currCmps_.size();
		for (auto i = 0u; i < n; i++)
			currCmps_[i]->draw();
	}
	inline void keyPressed(char k) {
		auto n = currCmps_.size();
		for (auto i = 0u; i < n; i++)
			currCmps_[i]->keyPressed(k);
	}
};


#endif // !ENTITY_H_