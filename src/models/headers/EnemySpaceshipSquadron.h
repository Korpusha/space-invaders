#ifndef SPACE_INVADERS_ENEMYSPACESHIPSQUADRON_H
#define SPACE_INVADERS_ENEMYSPACESHIPSQUADRON_H


#include <iostream>
#include <utility>
#include "EnemySpaceship.h"

using namespace std;

class EnemySpaceshipSquadron {
private:
    vector<EnemySpaceship> enemySpaceships;
private:
    void setEnemySpaceships(vector<EnemySpaceship> enemySpaceships_);
public:
    EnemySpaceshipSquadron() = delete;
    explicit EnemySpaceshipSquadron(vector<EnemySpaceship> enemySpaceships_);
    vector<EnemySpaceship> getEnemySpaceships();
};


#endif
