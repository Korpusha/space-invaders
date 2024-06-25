#include "headers/Entity.h"

void Entity::setPosition(sf::Vector2f position_)
{
    this->position = position_;
}

void Entity::setXVelocity(float xVelocity_)
{
    this->xVelocity = xVelocity_;
}

void Entity::setYVelocity(float yVelocity_)
{
    this->yVelocity = yVelocity_;
}

void Entity::moveRight()
{
    this->setPosition(sf::Vector2f { this->getPosition().x + this->getXVelocity(), this->getPosition().y });
}

void Entity::moveLeft()
{
    this->setPosition(sf::Vector2f { this->getPosition().x - this->getXVelocity(), this->getPosition().y });
}

void Entity::moveUp()
{
    this->setPosition(sf::Vector2f { this->getPosition().x, this->getPosition().y - this->getYVelocity() });
}

void Entity::moveDown()
{
    this->setPosition(sf::Vector2f { this->getPosition().x, this->getPosition().y + this->getYVelocity() });
}

sf::Vector2f Entity::getPosition() const
{
    return this->position;
}

float Entity::getXVelocity() const
{
    return this->xVelocity;
}

float Entity::getYVelocity() const
{
    return this->yVelocity;
}

void Entity::update()
{
    this->setPosition(this->getPosition());
}

void Entity::render(sf::RenderTarget& target)
{
}
