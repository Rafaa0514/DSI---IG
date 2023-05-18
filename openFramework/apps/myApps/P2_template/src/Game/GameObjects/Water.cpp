#include "Water.h"
#include "Player.h"

Water::Water(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos, glm::vec3(dim.x, dim.z, dim.y)) {
    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);

    ofEnableNormalizedTexCoords();
    ofEnableAlphaBlending();
    ofDisableArbTex();

    ofImage img;
    img.load("water.jpg");

    texture = img.getTexture();
    texture.setTextureWrap(GL_REPEAT, GL_REPEAT);
    texture.generateMipmap();
    texture.setTextureMinMagFilter(GL_LINEAR_MIPMAP_LINEAR, GL_NEAREST);
}


void Water::draw() {
    material.begin();
    {
        texture.bind();

        plane.mapTexCoords(0, 0, 1, 1);
        plane.draw();

        texture.unbind();
    }
    material.end();
}


void Water::receiveCarCollision(Player* car) {
    car->setPlayerState(PLANNING);
}