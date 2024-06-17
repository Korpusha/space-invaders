#ifndef SPACE_INVADERS_GAMEWINDOWSTATE_H
#define SPACE_INVADERS_GAMEWINDOWSTATE_H


#include "WindowState.h"
#include "ScoreWindowState.h"

class GameWindowState: public WindowState {
    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void render(sf::RenderWindow &window) override;
};


#endif
