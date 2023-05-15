#include "Arc.h"
#include "Obstacle.h"
#include "Game.h"

Arco::Arco(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, dim) {
	// inicialización variables
	changeTime = 1.0f;
	elapsedTime = 0.0f;
	minMoney = 1;
	maxMoney = 50;
	money = ofRandom(minMoney, maxMoney);

	// marco
	 glm::vec3 leftDim = glm::vec3(dim.x / 5, dim.y, dim.z * 10);
	 glm::vec3 leftPos = glm::vec3(pos.x - dim.x / 2 - leftDim.x / 2, pos.y, pos.z);
	 left = new Obstacle(g, leftPos, leftDim);
	 //left->transform.setParent(transform);
	 g->addGameObject(left);

	 glm::vec3 rightDim = glm::vec3(dim.x / 5, dim.y, dim.z * 10);
	 glm::vec3 rightPos = glm::vec3(pos.x + dim.x / 2 + rightDim.x / 2, pos.y, pos.z);
	 right = new Obstacle(g, rightPos, rightDim);
	 //right->transform.setParent(transform);
	 g->addGameObject(right);

	 glm::vec3 topDim = glm::vec3(dim.x + leftDim.x + rightDim.x, dim.y / 5, dim.z * 10);
	 glm::vec3 topPos = glm::vec3(pos.x - leftDim.x / 2 + rightDim.x / 2, pos.y + dim.y / 2 + topDim.y / 2, pos.z);
	 top = new Obstacle(g, topPos, topDim);
	 //top->transform.setParent(transform);
	 g->addGameObject(top);

	// Fuente
	font.load("AovelSansRounded.ttf", 75);
	posX = 200 - font.getStringBoundingBox(ofToString(money), 0, 0).getWidth() / 2;
	posY = 200 - font.getStringBoundingBox(ofToString(money), 0, 0).getHeight() / 2;

	// fbo
	ofEnableNormalizedTexCoords();
    ofEnableAlphaBlending(); 
	ofDisableArbTex();
	myFbo.allocate(400, 400);
}

void Arco::update() {
	elapsedTime += ofGetLastFrameTime();
	if (elapsedTime >= changeTime) {
		// reset timer
		elapsedTime = 0;
		// cambiar dinero
		money = ofRandom(minMoney, maxMoney);

		// Actualizar fbo
		myFbo.begin(); {
    		//ofEnableAlphaBlending(); 
			//ofBackground(255, 0); // 0 brillo y 0 opacidad
			ofClear(0);
			ofSetColor(255,255,255);
			font.drawString(ofToString(money), posX, posY);

		} myFbo.end();
	}
}

void Arco::draw() {
	material.begin(); {
		myFbo.getTexture().bind(); {
			collider->draw();

		} myFbo.getTexture().unbind();

	} material.end();
}

void Arco::receiveCarCollision(Player* car) {
	car->addCoins(money);
	left->kill();
	right->kill();
	top->kill();
	kill();
}