#include "Dirt.h"
#include "Player.h"

Dirt::Dirt(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, glm::vec3(dim.x, dim.y, 100)) {
    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);

    ofEnableNormalizedTexCoords();
    ofEnableAlphaBlending(); 
    ofDisableArbTex();
    
    ofImage img;
    img.load("dirt.jpg");

    texture = img.getTexture();
    texture.setTextureWrap( GL_REPEAT, GL_REPEAT );
    texture.generateMipmap();
    texture.setTextureMinMagFilter(GL_LINEAR_MIPMAP_LINEAR, GL_NEAREST);
}

Dirt::~Dirt() {

}

void Dirt::draw() {
    material.begin();
    {
        texture.bind();
            plane.mapTexCoords(0, 0, 1, 1);
            plane.draw();
        texture.unbind();
    }
    material.end();
}

void Dirt::receiveCarCollision(Player* car) {
    if (car->getSpeed() >= 5) car->setSpeed(4);
    if (car->getSpeed() >= 4) car->brake();
}