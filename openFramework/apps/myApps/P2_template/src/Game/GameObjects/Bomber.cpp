#include "Bomber.h"
#include "Bomb.h"
#include "Game.h"

Bomber::Bomber(Game* g, glm::vec3 pos, glm::vec3 dim, float distance) : GameObject(g, pos, dim) {
	body.setParent(transform);
	body.rotate(-90, 1, 0, 0);
	body.rotate(90, 0, 1, 0);
	collider->rotate(-90, 1, 0, 0);
	collider->rotate(90, 0, 1, 0);
	body.set(dim.x / 2, dim.y);
	direction = 1;
	minX = pos.x; maxX = pos.x + distance;
	elapsedTime = 0; cooldown = 3.5;
}

void Bomber::update() {
    transform.move(direction*5, 0, 0);
    if (transform.getX() < minX) direction = 1;
    else if (transform.getX() > maxX) direction = -1;
    
    elapsedTime += ofGetLastFrameTime();
    if (elapsedTime >= cooldown) {
        elapsedTime = 0;
        dropBomb();
    }
}

void Bomber::draw() {
	material.begin();
	{
		body.draw();
	}
	material.end();
}

void Bomber::dropBomb() {
	Bomb* b = new Bomb(game, transform.getPosition(), glm::vec3(125, 125, 125));
    game->addGameObject(b);
}