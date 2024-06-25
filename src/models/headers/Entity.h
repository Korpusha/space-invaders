#ifndef SPACE_INVADERS_ENTITY_H
#define SPACE_INVADERS_ENTITY_H


#include "SFML/Graphics.hpp"
#include <iostream>
#include <utility>

class Entity {
protected:
    sf::Vector2f position = sf::Vector2f { 0.f, 0.f };
    float xVelocity = 0.f;
    float yVelocity = 0.f;
public:
//    Entity(const Entity& entity) = default;
    virtual ~Entity() = default;

    void setPosition(sf::Vector2f position_);
    void setXVelocity(float xVelocity_);
    void setYVelocity(float yVelocity_);
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    [[nodiscard]] sf::Vector2f getPosition() const;
    [[nodiscard]] float getXVelocity() const;
    [[nodiscard]] float getYVelocity() const;

    virtual void update();
    virtual void render(sf::RenderTarget& renderTarget);
};


#endif
