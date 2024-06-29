#include "models/headers/ViewScoreWindowState.h"

WindowState *ViewScoreWindowState::update(sf::RenderWindow &window, sf::Event &ev) {
    if (ev.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            return new MenuWindowState();
        }
    }

    return ScoreWindowState::update(window, ev);
}

void ViewScoreWindowState::render(sf::RenderWindow &window)
{
    window.clear(StaticManager::BLACK);
    ScoreWindowState::render(window);
    window.display();

}
