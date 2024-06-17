#ifndef SPACE_INVADERS_SCOREWINDOWSTATE_H
#define SPACE_INVADERS_SCOREWINDOWSTATE_H


#include "WindowState.h"
#include "EndScreenWindowState.h"

class ScoreWindowState: public WindowState {
    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void render(sf::RenderWindow &window) override;
};


#endif
