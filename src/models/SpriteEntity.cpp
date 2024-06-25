#include "models/headers/SpriteEntity.h"

SpriteEntity::SpriteEntity(const std::string& textureFilePath)
{
    this->setTexture(textureFilePath);
    this->setSprite(new sf::Sprite(*this->getTexture()));
}

SpriteEntity::SpriteEntity(const sf::Image& image)
{
    this->setTexture(image);
    this->setSprite(new sf::Sprite(*this->getTexture()));
}

SpriteEntity::SpriteEntity(const SpriteEntity &spriteEntity)
{
    auto* t = new sf::Texture(*spriteEntity.getTexture());
    this->setTexture(*t);

    auto* s = new sf::Sprite(*spriteEntity.getSprite());
    this->setSprite(s);
}

SpriteEntity::~SpriteEntity()
{
    delete this->getSprite();
    delete this->getTexture();
}

void SpriteEntity::setSprite(sf::Sprite* sprite_)
{
    this->sprite = sprite_;
}

void SpriteEntity::setTexture(const sf::Texture& texture_)
{
    auto *t = new sf::Texture(texture_);
    this->texture = t;
}

void SpriteEntity::setTexture(const std::string &textureFilePath)
{
    auto *t = new sf::Texture();
    t->loadFromFile(textureFilePath);

    this->texture = t;
}

void SpriteEntity::setTexture(const sf::Image& image)
{
    auto *t = new sf::Texture();
    t->loadFromImage(image);

    this->texture = t;
}

sf::Sprite *SpriteEntity::getSprite() const
{
    return this->sprite;
}

sf::Texture *SpriteEntity::getTexture() const
{
    return this->texture;
}

void SpriteEntity::update()
{
    Entity::update();
}

void SpriteEntity::render(sf::RenderTarget& target)
{
    Entity::render(target);
    this->getSprite()->setPosition(this->getPosition());
    target.draw(*this->getSprite());
}
