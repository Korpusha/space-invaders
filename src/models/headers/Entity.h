#ifndef SPACE_INVADERS_ENTITY_H
#define SPACE_INVADERS_ENTITY_H


#include "SFML/Graphics.hpp"
#include <utility>

using namespace std;
using namespace sf;

class Entity {
protected:
    Sprite* sprite;
    Texture* texture;
    Vector2f position;
protected:
    void setSprite(Sprite* sprite_);
    void setTexture(const string& textureFilePath);
public:
    Entity() = delete;
    Entity(const string& textureFilePath, Vector2f position_);
    ~Entity();
    Sprite* getSprite();
    Texture* getTexture();
    Vector2f getPosition();
    void setPosition(Vector2f position_);
    virtual void update();
    virtual void render(RenderTarget& renderTarget);
};


#endif
