#include "headers/WindowState.h"

WindowState::WindowState()
{
    auto* font_ = new sf::Font();
    font_->loadFromFile(StaticManager::getFont());

    this->textFont = font_;
}

WindowState::~WindowState()
{
    delete this->textFont;
}

WindowState* WindowState::update(sf::RenderWindow &window, sf::Event& ev)
{
    return nullptr;
}

void WindowState::handleInput()
{
}

void WindowState::render(sf::RenderWindow &window)
{
    window.clear(StaticManager::BLACK);
    window.display();
}
