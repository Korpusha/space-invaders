#ifndef SPACE_INVADERS_BULLET_H
#define SPACE_INVADERS_BULLET_H


#include "RectangleShapeEntity.h"
#include "Entity.h"

class Bullet {
protected:
    RectangleShapeEntity* entity;
    int power = 1;
public:
    Bullet() = default;
    Bullet(RectangleShapeEntity* entity_, float yVelocity_);
    Bullet(const Bullet& bullet);
    ~Bullet();

    void setEntity(RectangleShapeEntity* entity_);
    void setPower(int power_);

    [[nodiscard]] RectangleShapeEntity* getEntity() const;
    [[nodiscard]] int getPower() const;
    [[nodiscard]] bool hasPower() const;

    void update();
    void render(sf::RenderTarget& target);
    void onHit();
};


#endif
