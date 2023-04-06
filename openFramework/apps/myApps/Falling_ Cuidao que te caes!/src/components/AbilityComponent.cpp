#include "AbilityComponent.h"

void AbilityComponent::initComponent() {
    tr = ent_->getComponent<Transform>();
}

void AbilityComponent::activate() {
    if (currentPU != noPU) {
        abilities[currentPU]();
        currentPU = noPU;
    }
}