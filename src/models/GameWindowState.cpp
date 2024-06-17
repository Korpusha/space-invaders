#include "headers/GameWindowState.h"

WindowState *GameWindowState::update(sf::RenderWindow &window, sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            return new ScoreWindowState();
        }
    }

    return nullptr;
}

void GameWindowState::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::Red);
    window.display();
}
