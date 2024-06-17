#include "headers/WindowState.h"

WindowState::~WindowState() = default;

void WindowState::setup(sf::RenderWindow &window) {};

WindowState* WindowState::update(sf::RenderWindow &window, sf::Event& ev)
{
    return nullptr;
}

void WindowState::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::White);
    window.display();
}
