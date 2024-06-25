#include "headers/Spaceship.h"
#include "headers/AllySpaceship.h"
#include "headers/EnemySpaceship.h"

template class Spaceship<AllySpaceshipState>;
template class Spaceship<EnemySpaceshipState>;

template<typename State>
Spaceship<State>::Spaceship(SpriteEntity* entity_, Gun *gun_, State state_)
{
    this->setEntity(entity_);
    this->setGun(gun_);
    this->setState(state_);
}

template<typename State>
void Spaceship<State>::setEntity(SpriteEntity *entity_)
{
    this->entity = entity_;
}

template<typename State>
void Spaceship<State>::setGun(Gun *gun_)
{
    this->gun = gun_;
}

template<typename State>
void Spaceship<State>::setLives(int lives_)
{
    this->lives = lives_;
}

template<typename State>
void Spaceship<State>::setState(State state_)
{
    this->state = state_;
}

template<typename State>
SpriteEntity *Spaceship<State>::getEntity() const
{
    return this->entity;
}

template<typename State>
Gun *Spaceship<State>::getGun() const
{
    return this->gun;
}

template<typename State>
int Spaceship<State>::getLives() const
{
    return this->lives;
}

template<typename State>
State Spaceship<State>::getState() const
{
    return this->state;
}

template<typename State>
bool Spaceship<State>::isAlive() const
{
    return this->getLives() > 0;
}

template<typename State>
void Spaceship<State>::onHit()
{
    this->setLives(this->getLives() - 1);
}
