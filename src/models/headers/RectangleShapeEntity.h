#ifndef SPACE_INVADERS_RECTANGLESHAPEENTITY_H
#define SPACE_INVADERS_RECTANGLESHAPEENTITY_H


#include "Entity.h"

class RectangleShapeEntity: public Entity {
private:
    sf::RectangleShape* rectangleShape;
public:
    explicit RectangleShapeEntity(const sf::Vector2f &size);
    RectangleShapeEntity(const RectangleShapeEntity& rectangleShapeEntity);
    ~RectangleShapeEntity() override;

    void setRectangleShape(sf::RectangleShape *rectangleShape_);

    [[nodiscard]] sf::RectangleShape *getRectangleShape() const;

    void update() override;
    void render(sf::RenderTarget& target) override;
};


#endif
