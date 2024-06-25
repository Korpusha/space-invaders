#include "models/headers/RectangleShapeEntity.h"

RectangleShapeEntity::RectangleShapeEntity(const sf::Vector2f &size)
{
    this->setRectangleShape(new sf::RectangleShape(size));
}

RectangleShapeEntity::RectangleShapeEntity(const RectangleShapeEntity &rectangleShapeEntity)
{
    auto* r = new sf::RectangleShape(rectangleShapeEntity.getRectangleShape()->getSize());
    r->setFillColor(rectangleShapeEntity.getRectangleShape()->getFillColor());

    this->setRectangleShape(r);
}

RectangleShapeEntity::~RectangleShapeEntity()
{
    delete this->rectangleShape;
}

void RectangleShapeEntity::setRectangleShape(sf::RectangleShape *rectangleShape_)
{
    this->rectangleShape = rectangleShape_;
}

sf::RectangleShape *RectangleShapeEntity::getRectangleShape() const
{
    return this->rectangleShape;
}

void RectangleShapeEntity::update()
{
    Entity::update();
}

void RectangleShapeEntity::render(sf::RenderTarget& target)
{
    Entity::render(target);
    this->getRectangleShape()->setPosition(this->getPosition());
    target.draw(*this->getRectangleShape());
}
