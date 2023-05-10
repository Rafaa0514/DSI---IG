#include "OilPuddle.h"
#include "Player.h"

OilPuddle::OilPuddle(Game* g, glm::vec3 pos, glm::vec3 dim) : GameObject(g, pos) {
	material.setEmissiveColor(ofColor::sandyBrown);

    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);


    // Para poner la textura
    // Cargar la imagen como ofImage
    // ofTexture texture = img.getTexture();
    // Más info en el ejemplo del github del profe carpeta example3Dsimple
}

OilPuddle::~OilPuddle() {
    
}

void OilPuddle::draw() {
    material.begin();
    {
        plane.draw();
    }
    material.end();
}

void OilPuddle::receiveCarCollision(Player* car) {
    car->setStunned(true);
}