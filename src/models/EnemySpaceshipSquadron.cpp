#include "headers/EnemySpaceshipSquadron.h"

EnemySpaceshipSquadron::EnemySpaceshipSquadron(vector<EnemySpaceship> enemySpaceships_)
{
    this->setEnemySpaceships(std::move(enemySpaceships_));
}

void EnemySpaceshipSquadron::setEnemySpaceships(vector<EnemySpaceship> enemySpaceships_)
{
    this->enemySpaceships = std::move(enemySpaceships_);
}

vector<EnemySpaceship> EnemySpaceshipSquadron::getEnemySpaceships()
{
    return this->enemySpaceships;
}
