#include "headers/Entity.h"

Entity::Entity(const string& textureFilePath, Vector2f position_)
{
    this->setTexture(textureFilePath);
    auto *s = new Sprite (*this->texture);

    this->setSprite(s);
    this->setPosition(position_);
}

Entity::~Entity()
{
    delete this->getTexture();
}

void Entity::setSprite(Sprite* sprite_)
{
    this->sprite = sprite_;
}

void Entity::setTexture(const string &textureFilePath)
{
    auto *t = new Texture;
    t->loadFromFile(textureFilePath);

    this->texture = t;
}

void Entity::setPosition(Vector2f position_)
{
    this->position = position_;
}

Sprite* Entity::getSprite()
{
    return this->sprite;
}

Texture* Entity::getTexture()
{
    return this->texture;
}

Vector2f Entity::getPosition()
{
    return this->position;
}

void Entity::update()
{
    this->setPosition(this->position);
}

void Entity::render(RenderTarget& target)
{
    target.draw(*this->getSprite());
}
