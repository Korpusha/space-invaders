#ifndef SPACE_INVADERS_PLAYERGUN_H
#define SPACE_INVADERS_PLAYERGUN_H


#include "Gun.h"

class PlayerGun: public Gun {
    using Gun::Gun;
public:
    void update(const sf::RectangleShape& playableArea) override;
    void render(sf::RenderTarget& target) override;
};


#endif
