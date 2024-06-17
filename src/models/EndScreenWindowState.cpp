#include "headers/EndScreenWindowState.h"

WindowState *EndScreenWindowState::update(sf::RenderWindow &window, sf::Event &ev)
{
    window.close();
    return nullptr;
}

void EndScreenWindowState::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);
    window.display();
}
