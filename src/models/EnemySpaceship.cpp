#include "headers/EnemySpaceship.h"

void EnemySpaceship::update()
{
    EnemySpaceshipState newState = this->getState();
    switch (this->getState()) {
        case EnemySpaceshipMoveLeft:
            this->getEntity()->moveLeft();
            break;
        case EnemySpaceshipMoveRight:
            this->getEntity()->moveRight();
            break;
        case EnemySpaceshipMoveDown:
            this->getEntity()->moveDown();
            break;
    }

    if (this->getState() != newState) {
        this->setState(newState);
    }

    this->getEntity()->update();
}

void EnemySpaceship::render(sf::RenderTarget &renderTarget)
{
    this->getEntity()->render(renderTarget);

    this->getGun()->getEntity()->setPosition(this->getEntity()->getPosition());
    this->getGun()->render(renderTarget);
}

sf::Image EnemySpaceship::getEnemySpaceshipImage(EnemySpaceship::Type type)
{
    sf::Image spaceInvadersImage = StaticManager::getSpaceInvadersImage();
    sf::Image enemySpaceshipImage = sf::Image {};

    switch (type) {
        case EnemySpaceship::Mystery:
            enemySpaceshipImage.create(11, 8);
            enemySpaceshipImage.copy(spaceInvadersImage, 0, 0, sf::IntRect {
                3, 4, 11, 8
            });
            break;
        case EnemySpaceship::Top:
            enemySpaceshipImage.create(10, 10);
            enemySpaceshipImage.copy(spaceInvadersImage, 0, 0, sf::IntRect {
                4, 20, 10, 10
            });
            break;
        case EnemySpaceship::Middle:
            enemySpaceshipImage.create(11, 8);
            enemySpaceshipImage.copy(spaceInvadersImage, 0, 0, sf::IntRect {
                3, 4, 11, 8
            });
            break;
        case EnemySpaceship::Bottom:
        default:
            enemySpaceshipImage.create(11, 10);
            enemySpaceshipImage.copy(spaceInvadersImage, 0, 0, sf::IntRect {
                4, 36, 11, 10
            });
            break;
    }

    return enemySpaceshipImage;
}

EnemySpaceship::Type EnemySpaceship::getType() const
{
    return this->type;
}

int EnemySpaceship::getHitScore() const
{
    return this->getType();
}

bool EnemySpaceship::hasReachedRight(const sf::Shape& shape) const
{
    return (this->getEntity()->getSprite()->getGlobalBounds().left + this->getEntity()->getSprite()->getGlobalBounds().getSize().x) >
           (shape.getPosition().x + shape.getGlobalBounds().width / 2.f);
}

bool EnemySpaceship::hasReachedLeft(const sf::Shape& shape) const
{
    return this->getEntity()->getSprite()->getGlobalBounds().left <
           (shape.getPosition().x - shape.getGlobalBounds().width / 2.f);
}
