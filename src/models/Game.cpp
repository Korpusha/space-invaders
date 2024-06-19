#include "headers/Game.h"

Game::Game()
{
    this->setWindowContext();
}

Game::~Game()
{
    delete this->windowContext;
}

void Game::setWindowContext()
{
    this->windowContext = new WindowContext();
}

void Game::run()
{
    while (this->running()) {
        this->update();
        this->render();
    }
}

void Game::update()
{
    this->windowContext->update();
}

void Game::render()
{
    this->windowContext->render();
}

bool Game::running()
{
    return this->windowContext->running();
}
