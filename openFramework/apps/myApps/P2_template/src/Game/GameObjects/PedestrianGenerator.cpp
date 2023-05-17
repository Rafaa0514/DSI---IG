#include "PedestrianGenerator.h"
#include "Pedestrian.h"
#include "Game.h"

PedestrianGenerator::PedestrianGenerator(Game* _g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, dim), deltaTime(0), timeOffset(5.00) {
	g = _g;
	addPedestrian();
}

PedestrianGenerator::~PedestrianGenerator() {

}

void PedestrianGenerator::update() {
	deltaTime += ofGetLastFrameTime();
	if (deltaTime >= timeOffset) {
		addPedestrian();
		deltaTime = 0;
	}
}

void PedestrianGenerator::draw() {

}

void PedestrianGenerator::addPedestrian() {
	Pedestrian* ped = new Pedestrian(g,
		transform.getPosition(), glm::vec3(50, 150, 50));
	g->addGameObject(ped);
}