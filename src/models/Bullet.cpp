#include "models/headers/Bullet.h"

Bullet::Bullet(RectangleShapeEntity *entity_, float yVelocity_)
{
    this->setEntity(entity_);
    this->getEntity()->setYVelocity(yVelocity_);
}

Bullet::Bullet(const Bullet& bullet)
{
    this->setEntity(new RectangleShapeEntity(*bullet.getEntity()));
    this->getEntity()->setYVelocity(bullet.getEntity()->getYVelocity());
}

Bullet::~Bullet()
{
    delete this->getEntity();
}

void Bullet::setEntity(RectangleShapeEntity *entity_)
{
    this->entity = entity_;
}

void Bullet::setPower(int power_)
{
    this->power = power_;
}

RectangleShapeEntity *Bullet::getEntity() const
{
    return this->entity;
}

int Bullet::getPower() const
{
    return this->power;
}

bool Bullet::hasPower() const
{
    return this->getPower() > 0;
}

void Bullet::update()
{
    this->getEntity()->update();
}

void Bullet::render(sf::RenderTarget &target)
{
    this->getEntity()->moveUp();
    this->getEntity()->render(target);
}

void Bullet::onHit()
{
    this->setPower(this->getPower() - 1);
}
