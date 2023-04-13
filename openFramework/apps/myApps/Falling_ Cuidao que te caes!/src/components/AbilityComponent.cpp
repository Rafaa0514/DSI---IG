#include "AbilityComponent.h"

void AbilityComponent::initComponent() {
    tr = ent_->getComponent<Transform>();
}

void AbilityComponent::activate() {
    if (hasAbility()) {
        abilities[currentPU]();
        gameSFX[mySound]->play();
        currentPU = noPU;
    }
}