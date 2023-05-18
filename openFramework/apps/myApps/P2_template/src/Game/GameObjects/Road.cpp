

#include "Road.h"
#include "Game.h"

Road::Road(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos){
    material.setDiffuseColor(ofColor::darkGrey);
    
    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);
    setLights(dim.z);
}
Road::~Road(){}

void Road::draw(){
    
    for (ofLight light : lights) light.enable();

    material.begin();
    {
        plane.draw();
    }
    material.end();
}


void Road::drawDebug(){
    plane.drawWireframe();
}

void Road::setLights(float dimZ) {
    for (int i = 0; i < 2; i++) {
        ofLight aux;
        aux.setPosition(200, 200, dimZ * (i + 1) / 4);
        aux.setDiffuseColor(ofColor::white);
        lights.push_back(aux);
    }
}