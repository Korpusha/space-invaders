#include "headers/WindowContext.h"

WindowContext::WindowContext()
{
    // 1280x720
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), WindowContext::TITLE, sf::Style::Close);
    this->windowState = new IntroWindowState();
    this->ev = sf::Event {};

    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

WindowContext::~WindowContext()
{
    delete this->window;
    delete this->windowState;
}

void WindowContext::update()
{
    while (this->window->pollEvent(this->ev)) {
        if (this->ev.type == sf::Event::Closed) {
            this->resetWindowState(new EndScreenWindowState());
        }

        if (this->ev.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->resetWindowState(new EndScreenWindowState());
        }

        WindowState* newWindowState = this->windowState->update(*this->window, this->ev);
        if (newWindowState != nullptr) {
            this->resetWindowState(newWindowState);
        }
    }
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
    delete this->windowState;
    this->windowState = newWindowState;
}
