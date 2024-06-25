#ifndef SPACE_INVADERS_BOTGUN_H
#define SPACE_INVADERS_BOTGUN_H


#include "Gun.h"

class BotGun: public Gun {
    using Gun::Gun;
public:
    void update(const sf::RectangleShape& playableArea) override;
    void render(sf::RenderTarget& target) override;
};


#endif
