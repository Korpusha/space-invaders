#ifndef SPACE_INVADERS_WINDOWSTATE_H
#define SPACE_INVADERS_WINDOWSTATE_H


#include <SFML/Graphics.hpp>
#include <iostream>

class WindowState {
public:
    virtual ~WindowState();
    virtual void setup(sf::RenderWindow& window);
    virtual WindowState* update(sf::RenderWindow& window, sf::Event& ev);
    virtual void render(sf::RenderWindow& window);
};


#endif
