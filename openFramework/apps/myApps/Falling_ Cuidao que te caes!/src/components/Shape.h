#pragma once
#include "../ecs/Component.h"
#include "Transform.h"



using namespace glm;

class Shape : public Component {
private:
	shapeType shp;
	ofColor col;
	vector<vec2> points; // puntos entre 0 y 1 para dibujar la figura relativa al transform
	Transform* tr_;

	void createTriangle();
	void createRectangle();
	void createCircle();
	void drawTriangle();
	void drawRectangle();
	void drawCircle();

public:
	static constexpr cmpId_type id = _SHAPE;
	Shape(shapeType shape, ofColor color);
	virtual void initComponent();
	virtual void draw();


};
