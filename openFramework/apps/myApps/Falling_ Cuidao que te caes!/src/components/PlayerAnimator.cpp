#include "PlayerAnimator.h"
#include "../ecs/Entity.h"

void PlayerAnimator::initComponent() {
    shape = ent_->getComponent<Shape>();
}
void PlayerAnimator::startFlicker() {
    flicking = true;
}

void PlayerAnimator::update() {
    if (flicking) {
        if (flickerTime > flickingElapsedTime) {
            flickingElapsedTime += ofGetLastFrameTime();
            if (flickerInterval > intervalElapsedTime) {
                intervalElapsedTime += ofGetLastFrameTime();
            }
            else {
                intervalElapsedTime = 0;
                shape->setAlpha((shape->getAplha() > 0) ? 0 : 255);
            }
        }
        else {
            flicking = false;
            flickingElapsedTime = 0;
            intervalElapsedTime = 0;
            shape->setAlpha(255);
        }
    }
}