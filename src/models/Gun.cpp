#include <utility>

#include "models/headers/Gun.h"

Gun::Gun(RectangleShapeEntity *entity_, Bullet* bullet_, float reloadSec_)
{
    this->setEntity(entity_);
    this->setBullet(bullet_);
    this->setReloadSec(reloadSec_);
    this->setState(GunState::Reloaded);
}

Gun::~Gun()
{
    delete this->getEntity();
    delete this->getBullet();
    for (Bullet* bulletFired : this->getBulletsFired()) {
        delete bulletFired;
    }
}

void Gun::setEntity(RectangleShapeEntity *entity_)
{
    this->entity = entity_;
}

void Gun::setBullet(Bullet *bullet_)
{
    this->bullet = bullet_;
}

void Gun::setState(GunState state_)
{
    this->state = state_;
}

void Gun::setReloadSec(float reloadSec_)
{
    this->reloadSec = reloadSec_;
}

void Gun::setReloadElapsedClock()
{
    this->reloadElapsedClock.restart();
}

void Gun::setBulletsFired(std::vector<Bullet*> bulletsFired_)
{
    this->bulletsFired = std::move(bulletsFired_);
}

void Gun::fireBullet()
{
    std::vector<Bullet*> bulletsFiredNew = std::vector<Bullet*> { this->getBulletsFired() };
    auto* bulletFired = this->createBullet();
    bulletFired->getEntity()->setPosition(this->getEntity()->getPosition());
    bulletsFiredNew.emplace_back(bulletFired);

    this->setBulletsFired(bulletsFiredNew);
    this->setReloadElapsedClock();
}

RectangleShapeEntity *Gun::getEntity()
{
    return this->entity;
}

Bullet *Gun::getBullet()
{
    return this->bullet;
}

Bullet *Gun::createBullet()
{
    return new Bullet(*this->getBullet());
}

GunState Gun::getState()
{
    return this->state;
}

float Gun::getReloadSec() const
{
    return this->reloadSec;
}

sf::Clock Gun::getReloadElapsedClock() const
{
    return this->reloadElapsedClock;
}

std::vector<Bullet*> Gun::getBulletsFired()
{
    return this->bulletsFired;
}

void Gun::update(const sf::RectangleShape& playableArea)
{
    std::vector<Bullet*> bulletsFiredNew = std::vector<Bullet*> {};
    for (Bullet* bulletFired : this->getBulletsFired()) {
        if (
                bulletFired->hasPower() &&
                bulletFired->getEntity()->getPosition().y >= (playableArea.getPosition().y - playableArea.getLocalBounds().height / 2.f) &&
                bulletFired->getEntity()->getPosition().y + bulletFired->getEntity()->getRectangleShape()->getLocalBounds().height <= (playableArea.getPosition().y + playableArea.getLocalBounds().height / 2.f)
        ) {
            bulletFired->update();
            bulletsFiredNew.emplace_back(bulletFired);
        }
    }
    this->setBulletsFired(bulletsFiredNew);
}

void Gun::render(sf::RenderTarget &target)
{
    this->getEntity()->render(target);

    for (Bullet* bulletFired : this->getBulletsFired()) {
        bulletFired->render(target);
    }
}
