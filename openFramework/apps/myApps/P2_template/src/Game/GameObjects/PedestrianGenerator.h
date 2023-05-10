#pragma once
#include "GameObject.h"

class Game;
class PedestrianGenerator : public GameObject{
private:
	double deltaTime;
	double timeOffset;
	Game* g;

	void addPedestrian();
public:
	PedestrianGenerator(Game* g, glm::vec3 pos, glm::vec3 dim);
	virtual ~PedestrianGenerator();

	void update() override;
	void draw() override;
};