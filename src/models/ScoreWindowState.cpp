#include "headers/ScoreWindowState.h"

WindowState *ScoreWindowState::update(sf::RenderWindow &window, sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            return new EndScreenWindowState();
        }
    }

    return nullptr;
}

void ScoreWindowState::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::Green);
    window.display();
}
