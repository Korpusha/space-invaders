#ifndef SPACE_INVADERS_ALLYSPACESHIP_H
#define SPACE_INVADERS_ALLYSPACESHIP_H


#include "Spaceship.h"
#include "EnemySpaceshipSquadron.h"
#include "Record.h"

enum AllySpaceshipState {
    AllySpaceshipMoveLeft,
    AllySpaceshipMoveRight,
    AllySpaceshipStayStill,
};

class AllySpaceship: public Spaceship<AllySpaceshipState> {
    using Spaceship<AllySpaceshipState>::Spaceship;
public:
    inline static const float X_VELOCITY = 10.f;
    inline static const float GUN_RELOAD_SEC = 2.f;

    void update();
    void handleInput(const sf::RectangleShape& playableArea, const EnemySpaceshipSquadron& enemySpaceshipSquadron, Record& record);
    void render(sf::RenderTarget& renderTarget);
};


#endif
