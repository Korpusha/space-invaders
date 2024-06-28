#include "headers/AllySpaceship.h"

void AllySpaceship::update()
{
}

void AllySpaceship::handleInput(const sf::RectangleShape& playableArea, const EnemySpaceshipSquadron& enemySpaceshipSquadron, Record& record)
{
    for (std::vector<EnemySpaceship*>* enemySpaceships : enemySpaceshipSquadron.getEnemySpaceshipsMatrix()) {
        for (EnemySpaceship* enemySpaceship : *enemySpaceships) {
            for (Bullet* enemyBullet : enemySpaceship->getGun()->getBulletsFired()) {
                if (enemyBullet->getEntity()->getRectangleShape()->getGlobalBounds().intersects(this->getEntity()->getSprite()->getGlobalBounds())) {
                    this->onHit();
                    enemyBullet->onHit();
                }
            }
        }
    }

    std::vector<std::vector<EnemySpaceship*>*> enemySpaceshipsMatrix = enemySpaceshipSquadron.getEnemySpaceshipsMatrix();
    for (std::vector<EnemySpaceship*>* enemySpaceships : enemySpaceshipsMatrix) {
        for (EnemySpaceship* enemySpaceship : *enemySpaceships) {
            for (auto playerBullet : this->getGun()->getBulletsFired()) {
                if (enemySpaceship->getEntity()->getSprite()->getGlobalBounds().intersects(playerBullet->getEntity()->getRectangleShape()->getGlobalBounds())) {
                    enemySpaceship->onHit();
                    playerBullet->onHit();
                    record.setValue(record.getValue() + enemySpaceship->getHitScore());
                }
            }

            if (enemySpaceship->getEntity()->getPosition().y > this->getEntity()->getPosition().y) {
                this->setLives(0);
            }
        }
    }

    bool hasNotReachedRightBorder =
            (this->getEntity()->getPosition().x + this->getEntity()->getSprite()->getGlobalBounds().getSize().x / 2.f) <
            (playableArea.getPosition().x + playableArea.getSize().x / 2.f);
    bool hasNotReachedLeftBorder =
            (this->getEntity()->getPosition().x - this->getEntity()->getSprite()->getGlobalBounds().getSize().x / 2.f) >
            (playableArea.getPosition().x - playableArea.getSize().x / 2.f);

    AllySpaceshipState newState = this->getState();
    switch (this->getState()) {
        case AllySpaceshipState::AllySpaceshipMoveLeft:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && hasNotReachedLeftBorder) {
                this->getEntity()->moveLeft();
            } else {
                newState = AllySpaceshipState::AllySpaceshipStayStill;
            }
            break;
        case AllySpaceshipState::AllySpaceshipMoveRight:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && hasNotReachedRightBorder) {
                this->getEntity()->moveRight();
            } else {
                newState = AllySpaceshipState::AllySpaceshipStayStill;
            }
            break;
        case AllySpaceshipState::AllySpaceshipStayStill:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                newState = AllySpaceshipState::AllySpaceshipMoveLeft;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                newState = AllySpaceshipState::AllySpaceshipMoveRight;
            }
            break;
    }

    if (this->getState() != newState) {
        this->setState(newState);
    }

    this->getGun()->update(playableArea);
    this->getEntity()->update();
}

void AllySpaceship::render(sf::RenderTarget &renderTarget)
{
    this->getGun()->getEntity()->setPosition(this->getEntity()->getPosition());
    this->getGun()->render(renderTarget);
    this->getEntity()->render(renderTarget);
}
