#ifndef SPACE_INVADERS_SPRITEENTITY_H
#define SPACE_INVADERS_SPRITEENTITY_H


#include "Entity.h"

class SpriteEntity: public Entity {
protected:
    sf::Sprite* sprite;
    sf::Texture* texture;

    void setSprite(sf::Sprite* sprite_);
    void setTexture(const sf::Texture& texture_);
    void setTexture(const std::string& textureFilePath);
    void setTexture(const sf::Image& image);
public:
    explicit SpriteEntity(const std::string& textureFilePath);
    explicit SpriteEntity(const sf::Image& image);
    SpriteEntity(const SpriteEntity& spriteEntity);
    ~SpriteEntity() override;

    [[nodiscard]] sf::Sprite* getSprite() const;
    [[nodiscard]] sf::Texture* getTexture() const;

    void update() override;
    void render(sf::RenderTarget& renderTarget) override;
};


#endif
