#ifndef SPACE_INVADERS_SPACESHIP_H
#define SPACE_INVADERS_SPACESHIP_H


#include "SpriteEntity.h"
#include "Gun.h"

template<typename State>
class Spaceship {
private:
    State state;
protected:
    SpriteEntity* entity;
    Gun* gun;
    unsigned int lives = 1;
public:
    Spaceship(SpriteEntity* entity_, Gun* gun_, State state_, unsigned int lives);

    void setEntity(SpriteEntity* entity_);
    void setGun(Gun* gun_);
    void setLives(unsigned int lives_);
    void setState(State state_);

    [[nodiscard]] SpriteEntity* getEntity() const;
    [[nodiscard]] Gun* getGun() const;
    [[nodiscard]] int getLives() const;
    [[nodiscard]] State getState() const;
    [[nodiscard]] bool isAlive() const;

    virtual void onHit();
};


#endif
