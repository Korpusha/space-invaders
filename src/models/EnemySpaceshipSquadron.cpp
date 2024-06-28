#include "headers/EnemySpaceshipSquadron.h"

EnemySpaceshipSquadron::EnemySpaceshipSquadron(const vector<EnemySpaceship::Type> &columnTemplate,
                                               unsigned int columnNum, float xStep, float yStep,
                                               const sf::RectangleShape& playableArea)
{
    float xPlayableAreaPadding = 50;
    float yPlayableAreaPadding = 40;

    float xPlayableAreaPos = playableArea.getGlobalBounds().left + xPlayableAreaPadding;
    float yPlayableAreaPos = playableArea.getGlobalBounds().top + yPlayableAreaPadding;

    this->enemySpaceshipsMatrix = std::vector<std::vector<EnemySpaceship*>*> {};
    this->state = EnemySpaceshipState::EnemySpaceshipMoveRight;

    for (int i = 0; i < columnNum; ++i) {
        this->enemySpaceshipsMatrix.push_back(new std::vector<EnemySpaceship*>());

        for (int j = 0; j < columnTemplate.size(); ++j) {
            auto* enemySpaceshipEntity = new SpriteEntity(EnemySpaceship::getEnemySpaceshipImage(columnTemplate[j]));
            sf::FloatRect enemySpaceshipRect = enemySpaceshipEntity->getSprite()->getLocalBounds();
            enemySpaceshipEntity->getSprite()->setOrigin(enemySpaceshipRect.left + enemySpaceshipRect.width / 2.f,
                                                         enemySpaceshipRect.top - enemySpaceshipRect.height);
            enemySpaceshipEntity->getSprite()->setScale(sf::Vector2f { 4.f, 4.f });
            enemySpaceshipEntity->getSprite()->setColor(StaticManager::GREEN);
            enemySpaceshipEntity->setPosition(sf::Vector2f {
                    (xPlayableAreaPos + (xStep * (float) i)),
                    (yPlayableAreaPos + (yStep * (float) j))
            });
            enemySpaceshipEntity->setXVelocity(EnemySpaceship::X_VELOCITY);
            enemySpaceshipEntity->setYVelocity(EnemySpaceship::Y_VELOCITY);

            auto* bullet = new Bullet(new RectangleShapeEntity(sf::Vector2f { 2.f, 20.f }),
                                      -6.f);
            bullet->getEntity()->getRectangleShape()->setFillColor(StaticManager::GREEN);

            auto *gun = new BotGun(
                new RectangleShapeEntity(sf::Vector2f { 0.f, 0.f }),
                bullet,
                EnemySpaceship::GUN_RELOAD_SEC
            );

            auto* enemySpaceship = new EnemySpaceship(enemySpaceshipEntity, gun, this->state,
                                                      columnTemplate[j], EnemySpaceship::LIVES_DEFAULT);

            this->enemySpaceshipsMatrix[i]->push_back(enemySpaceship);
        }
    }
}

EnemySpaceshipSquadron::~EnemySpaceshipSquadron()
{
    for (const vector<EnemySpaceship*>* enemySpaceships : this->getEnemySpaceshipsMatrix()) {
        for (EnemySpaceship* enemySpaceship : *enemySpaceships) {
            delete enemySpaceship;
        }
        delete enemySpaceships;
    }
}

void EnemySpaceshipSquadron::setState(EnemySpaceshipState state_)
{
    this->state = state_;
}

void EnemySpaceshipSquadron::setPreviousState(EnemySpaceshipState previousState_)
{
    this->previousState = previousState_;
}

void EnemySpaceshipSquadron::setNonActionTimeframeClock()
{
    this->nonActionTimeframeClock.restart();
}

std::vector<std::vector<EnemySpaceship*>*> EnemySpaceshipSquadron::getEnemySpaceshipsMatrix() const
{
    return this->enemySpaceshipsMatrix;
}

EnemySpaceshipState EnemySpaceshipSquadron::getState() const
{
    return this->state;
}

EnemySpaceshipState EnemySpaceshipSquadron::getPreviousState() const
{
    return this->previousState;
}

float EnemySpaceshipSquadron::getActionTimeframeSec() const
{
    return this->actionTimeframeSec;
}

sf::Clock EnemySpaceshipSquadron::getNonActionTimeframeClock() const
{
    return this->nonActionTimeframeClock;
}

bool EnemySpaceshipSquadron::isDefeated() const
{
    return this->getEnemySpaceshipsMatrix().empty();
}

void EnemySpaceshipSquadron::update(const sf::RectangleShape &playableArea)
{
    std::vector<std::vector<EnemySpaceship*>*> enemySpaceshipsMatrix_ = this->getEnemySpaceshipsMatrix();
    if (enemySpaceshipsMatrix_.empty()) return;

    std::vector<std::vector<EnemySpaceship*>*> enemySpaceshipsMatrixNew = std::vector<std::vector<EnemySpaceship*>*> {};

    for (int i = 0; i < enemySpaceshipsMatrix_.size(); ++i) {
        auto* enemySpaceshipsNew = new std::vector<EnemySpaceship*>();
        for (EnemySpaceship* enemySpaceship : *enemySpaceshipsMatrix_[i]) {
            if (enemySpaceship->isAlive()) {
                enemySpaceshipsNew->emplace_back(enemySpaceship);
                enemySpaceship->setState(this->getState());
                enemySpaceship->getGun()->update(playableArea);
            }
        }

        if (!enemySpaceshipsNew->empty()) {
            enemySpaceshipsMatrixNew.push_back(enemySpaceshipsNew);
        } else {
            delete enemySpaceshipsNew;
        }
    }

    this->enemySpaceshipsMatrix = std::move(enemySpaceshipsMatrixNew);

    if (this->getNonActionTimeframeClock().getElapsedTime().asMilliseconds() < (int) (this->getActionTimeframeSec() * 1000)) {
        return;
    }

    std::vector<std::vector<EnemySpaceship*>> outermostEnemySpaceshipsMatrix = std::vector<std::vector<EnemySpaceship*>> {
            *this->getEnemySpaceshipsMatrix()[0],
            *this->getEnemySpaceshipsMatrix()[this->getEnemySpaceshipsMatrix().size() - 1],
    };

    bool hasReachedRightBorder = false;
    bool hasReachedLeftBorder = false;

    for (const std::vector<EnemySpaceship*>& enemySpaceships : outermostEnemySpaceshipsMatrix) {
        for (EnemySpaceship* enemySpaceship : enemySpaceships) {
            hasReachedRightBorder = enemySpaceship->hasReachedRight(playableArea);
            hasReachedLeftBorder = enemySpaceship->hasReachedLeft(playableArea);
        }

        if (hasReachedRightBorder || hasReachedLeftBorder) {
            break;
        }
    }

    EnemySpaceshipState currentState = this->getState();
    EnemySpaceshipState newState = this->getState();

    switch (currentState) {
        case EnemySpaceshipMoveLeft:
            if (hasReachedLeftBorder) {
                newState = EnemySpaceshipState::EnemySpaceshipMoveDown;
            }
            break;
        case EnemySpaceshipMoveRight:
            if (hasReachedRightBorder) {
                newState = EnemySpaceshipState::EnemySpaceshipMoveDown;
            }
            break;
        case EnemySpaceshipMoveDown:
            if (this->getPreviousState() == EnemySpaceshipState::EnemySpaceshipMoveRight) {
                newState = EnemySpaceshipState::EnemySpaceshipMoveLeft;
            } else if (this->getPreviousState() == EnemySpaceshipState::EnemySpaceshipMoveLeft) {
                newState = EnemySpaceshipState::EnemySpaceshipMoveRight;
            }
            break;
    }

    if (currentState != newState) {
        this->setPreviousState(currentState);
        this->setState(newState);

    }

    // Get one front row enemy spaceship and set its gun state as reloaded.
    int randomEnemySpaceshipColumnIndex = 0;
    if (enemySpaceshipsMatrix_.size() - 1) {
        randomEnemySpaceshipColumnIndex = rand() % ((int) enemySpaceshipsMatrix_.size() - 1);
    }

    std::vector<EnemySpaceship*> randEnemySpaceshipColumn = *this->getEnemySpaceshipsMatrix()[randomEnemySpaceshipColumnIndex];
    randEnemySpaceshipColumn[randEnemySpaceshipColumn.size() - 1]->getGun()->setState(GunState::Reloaded);

    for (std::vector<EnemySpaceship*>* enemySpaceships : this->getEnemySpaceshipsMatrix()) {
        for (EnemySpaceship* enemySpaceship : *enemySpaceships) {
            enemySpaceship->setState(this->getState());
            enemySpaceship->update();
        }
    }

    this->setNonActionTimeframeClock();
}

void EnemySpaceshipSquadron::render(sf::RenderTarget &target)
{
    for (auto & enemySpaceships : this->getEnemySpaceshipsMatrix()) {
        for (EnemySpaceship* enemySpaceship : *enemySpaceships) {
            enemySpaceship->render(target);
        }
    }
}
