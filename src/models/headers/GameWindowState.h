#ifndef SPACE_INVADERS_GAMEWINDOWSTATE_H
#define SPACE_INVADERS_GAMEWINDOWSTATE_H


#include "WindowState.h"
#include "ScoreWindowState.h"
#include "Record.h"

class GameWindowState: public WindowState {
protected:
    Player* player {};
public:
    using WindowState::WindowState;
    explicit GameWindowState(const std::string& playerNickname);
    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void render(sf::RenderWindow &window) override;
    void setPlayer(const std::string& playerNickname);
};


#endif
