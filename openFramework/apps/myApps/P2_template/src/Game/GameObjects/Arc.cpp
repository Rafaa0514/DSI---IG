#include "Arc.h"
#include "Obstacle.h"
#include "Game.h"

Arc::Arc(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, dim) {
	// inicialización variables
	changeTime = 1.0f;
	elapsedTime = 0.0f;
	minMoney = 1;
	maxMoney = 50;
	money = ofRandom(minMoney, maxMoney);

	// marco
	glm::vec3 leftDim = glm::vec3(dim.x * 2, dim.y, dim.z * 2);
	glm::vec3 leftPos = glm::vec3(pos.x - dim.x / 2 - leftDim.x / 2, pos.y, pos.z);
	left = new Obstacle(g, leftPos, leftDim);
	left->transform.setParent(transform);
	g->addGameObject(left);

	glm::vec3 rightDim = glm::vec3(dim.x * 2, dim.y, dim.z * 2);
	glm::vec3 rightPos = glm::vec3(pos.x + dim.x / 2 + rightDim.x / 2, pos.y, pos.z);
	right = new Obstacle(g, rightPos, rightDim);
	right->transform.setParent(transform);
	g->addGameObject(right);

	glm::vec3 topDim = glm::vec3(dim.x + leftDim.x + rightDim.x, dim.y * 2, dim.z * 2);
	glm::vec3 topPos = glm::vec3(pos.x - leftDim.x / 2 + rightDim.x / 2, pos.y + dim.y / 2 + topDim.y / 2, pos.z);
	top = new Obstacle(g, topPos, topDim);
	top->transform.setParent(transform);
	g->addGameObject(top);


	// fbo
	ofEnableNormalizedTexCoords();
	ofDisableArbTex();
	myFbo.allocate(400, 400);
}

void Arc::update() {
	elapsedTime += ofGetLastFrameTime();
	if (elapsedTime >= changeTime) {
		// reset timer
		elapsedTime = 0;
		// cambiar dinero
		money = ofRandom(minMoney, maxMoney);
		// Actualizar fbo
		myFbo.begin(); {
			ofBackground(0, 0); // 0 brillo y 0 opacidad
			ofSetColor(0);
			ofDrawBitmapString(ofToString(money), 200, 200);

		} myFbo.end();
	}
}

void Arc::draw() {
	material.begin(); {
		myFbo.getTexture().bind(); {
			collider->draw();

		} myFbo.getTexture().unbind();

	} material.end();
}

void Arc::receiveCarCollision(Player* car) {
	car->addCoins(money);
	left->kill();
	right->kill();
	top->kill();
	kill();
}