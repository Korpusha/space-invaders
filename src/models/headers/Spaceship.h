#ifndef SPACE_INVADERS_SPACESHIP_H
#define SPACE_INVADERS_SPACESHIP_H


#include "Entity.h"

class Spaceship: public Entity {
    using Entity::Entity;
protected:
    double velocity {};
    void setVelocity(double velocity_);
public:
    double getVelocity() const;
};


#endif
