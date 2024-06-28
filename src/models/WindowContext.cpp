#include "headers/WindowContext.h"

WindowContext::WindowContext()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), WindowContext::TITLE, sf::Style::Close);
    this->windowState = new MenuWindowState();
    this->ev = sf::Event {};

    sf::Image icon = EnemySpaceship::getEnemySpaceshipImage(EnemySpaceship::Type::Middle);

    this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

WindowContext::~WindowContext()
{
    delete this->window;
    delete this->windowState;
}

void WindowContext::pollEvents()
{
    while (this->window->pollEvent(this->ev)) {
        WindowState* newWindowState = this->windowState->update(*this->window, this->ev);
        if (newWindowState != nullptr) {
            this->resetWindowState(newWindowState);
        }
    }
}

void WindowContext::handleInput()
{
    this->windowState->handleInput();
}

void WindowContext::render()
{
    this->windowState->render(*this->window);
}

bool WindowContext::running()
{
    return this->window->isOpen();
}

void WindowContext::resetWindowState(WindowState* newWindowState)
{
    this->windowState = newWindowState;
}
