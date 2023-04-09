#pragma once
#include "../ecs/Component.h"
#include "../components/Shape.h"

class PowerUpAnimator : public Component {
private:
    float sizeDiff;
    int alpha;
    Transform* tr;
    Shape* shp;
    ofColor color;
public:
	static constexpr cmpId_type id = _POWERUP_ANIMATOR;

	PowerUpAnimator();

	virtual void initComponent();
    virtual void update();
    virtual void draw();
};