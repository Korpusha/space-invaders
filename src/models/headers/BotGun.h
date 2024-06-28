#ifndef SPACE_INVADERS_BOTGUN_H
#define SPACE_INVADERS_BOTGUN_H


#include "Gun.h"

class BotGun: public Gun {
    using Gun::Gun;
public:
    BotGun(RectangleShapeEntity *entity_, Bullet* bullet_, float reloadSec_): Gun(entity_, bullet_, reloadSec_)
    {
        this->setState(GunState::Reloading);
    };

    void update(const sf::RectangleShape& playableArea) override;
    void render(sf::RenderTarget& target) override;
};


#endif
