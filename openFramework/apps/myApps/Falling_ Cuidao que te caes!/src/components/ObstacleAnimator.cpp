#include "ObstacleAnimator.h"

ObstacleAnimator::ObstacleAnimator() : shp(nullptr), col(100, 100, 100) { }

void ObstacleAnimator::initComponent() {
    shp = ent_->getComponent<Shape>();
}

void ObstacleAnimator::activate() {
    shp->setColor(col);
}