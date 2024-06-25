#ifndef SPACE_INVADERS_GAMEWINDOWSTATE_H
#define SPACE_INVADERS_GAMEWINDOWSTATE_H


#include "WindowState.h"
#include "ScoreWindowState.h"
#include "Record.h"
#include "Player.h"
#include "EnemySpaceshipSquadron.h"
#include "PlayerGun.h"
#include "Bullet.h"
#include "StaticManager.h"

class GameWindowState: public WindowState {
    using WindowState::WindowState;
private:
    void setPlayableArea(sf::RenderWindow &window);
    void setPlayer(const std::string& playerNickname);
    void setEnemySpaceshipSquadron();
    void setScoreText();
    [[nodiscard]] AllySpaceship* getAllySpaceship() const;
protected:
    sf::RectangleShape* playableArea;
    Player* player {};
    EnemySpaceshipSquadron* enemySpaceshipSquadron {};
    sf::Text* scoreText;
public:
    explicit GameWindowState(const std::string& playerNickname, sf::RenderWindow &window);
    ~GameWindowState() override;

    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void handleInput() override;
    void render(sf::RenderWindow &window) override;
};


#endif
