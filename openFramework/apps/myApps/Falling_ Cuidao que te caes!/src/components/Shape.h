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
	bool noFill;

	void createTriangle();
	void createRectangle();
	void createCircle();
	void drawTriangle();
	void drawRectangle();
	void drawCircle();

public:
	static constexpr cmpId_type id = _SHAPE;
	Shape(shapeType shape, ofColor color, bool fill = true);
	virtual void initComponent();
	virtual void draw();
	inline void setAlpha(int alpha) { col.a = alpha; }
	inline int getAplha() { return col.a; }
	inline bool getFill() { return !noFill; }
	inline bool setFill(bool fill) { noFill = !fill; }
};