#ifndef SPACE_INVADERS_ENDSCREENWINDOWSTATE_H
#define SPACE_INVADERS_ENDSCREENWINDOWSTATE_H


#include "WindowState.h"

class EndScreenWindowState: public WindowState {
    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void render(sf::RenderWindow &window) override;
};


#endif
