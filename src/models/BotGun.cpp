#include "models/headers/BotGun.h"

void BotGun::update(const sf::RectangleShape& playableArea)
{
    Gun::update(playableArea);

    GunState newState = this->getState();
    switch (this->getState()) {
        case Reloaded:
            this->fireBullet();
            newState = GunState::Reloading;
            break;
        case Reloading:
            break;
    }

    if (this->getState() != newState) {
        this->setState(newState);
    }
}

void BotGun::render(sf::RenderTarget &target)
{
    Gun::render(target);
}
