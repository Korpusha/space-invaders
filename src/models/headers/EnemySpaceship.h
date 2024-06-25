#ifndef SPACE_INVADERS_ENEMYSPACESHIP_H
#define SPACE_INVADERS_ENEMYSPACESHIP_H


#include "Spaceship.h"

enum EnemySpaceshipState {
    EnemySpaceshipMoveLeft,
    EnemySpaceshipMoveRight,
    EnemySpaceshipMoveDown,
};

class EnemySpaceship: public Spaceship<EnemySpaceshipState> {
public:
    enum Type {
        Mystery = 300,
        Top = 200,
        Middle = 100,
        Bottom = 50,
    };
    using Spaceship::Spaceship;
private:
    Type type;
public:
    EnemySpaceship(SpriteEntity* entity_, Gun *gun_, EnemySpaceshipState state_, Type type_):
        Spaceship<EnemySpaceshipState>(entity_, gun_, state_), type(type_) {};

    inline static const float X_VELOCITY = 10.f;
    inline static const float Y_VELOCITY = 15.f;
    inline static const float GUN_RELOAD_SEC = 1.f;

    void update();
    void render(sf::RenderTarget& renderTarget);

    [[nodiscard]] Type getType() const;
    [[nodiscard]] int getHitScore() const;
    [[nodiscard]] bool hasReachedRight(const sf::Shape& shape) const;
    [[nodiscard]] bool hasReachedLeft(const sf::Shape& shape) const;

    static sf::Image getEnemySpaceshipImage(EnemySpaceship::Type type);
};


#endif
