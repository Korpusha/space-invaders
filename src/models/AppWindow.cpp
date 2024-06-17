#include "headers/AppWindow.h"

AppWindow::AppWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1280, 1024), "SpaceInvaders", sf::Style::Close);
    this->windowState = new IntroWindowState();
    this->ev = sf::Event {};

    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

AppWindow::~AppWindow()
{
    delete this->window;
    delete this->windowState;
}

void AppWindow::update()
{
    while (this->window->pollEvent(this->ev)) {
        if (this->ev.type == sf::Event::Closed) {
            this->window->close();
        }

        if (this->ev.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                this->window->close();
            }
        }

        WindowState* newWindowState = this->windowState->update(*this->window, this->ev);
        if (newWindowState != nullptr) {
            delete this->windowState;
            this->windowState = newWindowState;
            this->windowState->setup(*this->window);
        }
    }
}

void AppWindow::render()
{
    this->windowState->render(*this->window);
}

bool AppWindow::running()
{
    return this->window->isOpen();
}
