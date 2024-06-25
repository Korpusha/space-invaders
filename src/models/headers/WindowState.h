#ifndef SPACE_INVADERS_WINDOWSTATE_H
#define SPACE_INVADERS_WINDOWSTATE_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticManager.h"

class WindowState {
protected:
    sf::Font* textFont;
public:
    WindowState();
    virtual ~WindowState();

    virtual WindowState* update(sf::RenderWindow& window, sf::Event& ev);
    virtual void handleInput();
    virtual void render(sf::RenderWindow& window);
};


#endif
