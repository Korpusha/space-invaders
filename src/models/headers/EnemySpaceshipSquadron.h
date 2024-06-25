#ifndef SPACE_INVADERS_ENEMYSPACESHIPSQUADRON_H
#define SPACE_INVADERS_ENEMYSPACESHIPSQUADRON_H


#include <cmath>
#include "EnemySpaceship.h"
#include "StaticManager.h"
#include "BotGun.h"

using namespace std;

class EnemySpaceshipSquadron {
protected:
    std::vector<std::vector<EnemySpaceship*>*> enemySpaceshipsMatrix {};
    EnemySpaceshipState state;
    EnemySpaceshipState previousState;
    float actionTimeframeSec = 0.5;
    sf::Clock nonActionTimeframeClock;
public:
    EnemySpaceshipSquadron(const vector<EnemySpaceship::Type>& columnTemplate, unsigned int columnSize,
                           float xStep, float yStep, const sf::RectangleShape& playableArea);
    ~EnemySpaceshipSquadron();

    void setState(EnemySpaceshipState state_);
    void setPreviousState(EnemySpaceshipState previousState_);
    void setNonActionTimeframeClock();

    [[nodiscard]] std::vector<std::vector<EnemySpaceship*>*> getEnemySpaceshipsMatrix() const;
    [[nodiscard]] EnemySpaceshipState getState() const;
    [[nodiscard]] EnemySpaceshipState getPreviousState() const;
    [[nodiscard]] float getActionTimeframeSec() const;
    [[nodiscard]] sf::Clock getNonActionTimeframeClock() const;
    [[nodiscard]] bool isDefeated() const;

    void update(const sf::RectangleShape& playableArea);
    void render(sf::RenderTarget& target);
};


#endif
