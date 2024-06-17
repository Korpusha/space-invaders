#ifndef SPACE_INVADERS_INTROWINDOWSTATE_H
#define SPACE_INVADERS_INTROWINDOWSTATE_H


#include "WindowState.h"
#include "GameWindowState.h"

class IntroWindowState: public WindowState {
    void setup(sf::RenderWindow &window) override;
    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void render(sf::RenderWindow &window) override;
};


#endif
