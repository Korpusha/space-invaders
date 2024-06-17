#include "headers/Spaceship.h"

void Spaceship::setVelocity(double velocity_)
{
    this->velocity = velocity_;
}

double Spaceship::getVelocity() const
{
    return this->velocity;
}
