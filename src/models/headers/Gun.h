#ifndef SPACE_INVADERS_GUN_H
#define SPACE_INVADERS_GUN_H


#include <iostream>
#include <vector>
#include "RectangleShapeEntity.h"
#include "Bullet.h"
#include "StaticManager.h"

enum GunState {
    Reloading,
    Reloaded,
};

class Gun {
protected:
    RectangleShapeEntity* entity;
    Bullet* bullet;
    GunState state;
    float reloadSec = 1.f;
    sf::Clock reloadElapsedClock;
    std::vector<Bullet*> bulletsFired;
public:
    explicit Gun(RectangleShapeEntity* entity_, Bullet* bullet_, float reloadSec_);
    ~Gun();

    void setEntity(RectangleShapeEntity* entity_);
    void setBullet(Bullet* bullet_);
    void setState(GunState state_);
    void setReloadSec(float reloadSec_);
    void setReloadElapsedClock();
    void setBulletsFired(std::vector<Bullet*> bulletsFired_);
    void fireBullet();

    [[nodiscard]] RectangleShapeEntity* getEntity();
    [[nodiscard]] Bullet* getBullet();
    [[nodiscard]] Bullet* createBullet();
    [[nodiscard]] GunState getState();
    [[nodiscard]] float getReloadSec() const;
    [[nodiscard]] sf::Clock getReloadElapsedClock() const;
    [[nodiscard]] std::vector<Bullet*> getBulletsFired();

    virtual void update(const sf::RectangleShape& playableArea);
    virtual void render(sf::RenderTarget& target);
};


#endif
