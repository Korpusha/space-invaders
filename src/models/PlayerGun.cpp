#include "models/headers/PlayerGun.h"

void PlayerGun::update(const sf::RectangleShape& playableArea)
{
    Gun::update(playableArea);

    GunState newState = this->getState();
    switch (this->getState()) {
        case Reloaded:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                this->fireBullet();
                newState = GunState::Reloading;
            }
            break;
        case Reloading:
            if (this->getReloadElapsedClock().getElapsedTime().asSeconds() >= this->getReloadSec()) {
                newState = GunState::Reloaded;
            }
            break;
    }

    if (this->getState() != newState) {
        this->setState(newState);
    }
}

void PlayerGun::render(sf::RenderTarget &target)
{
    Gun::render(target);
}
