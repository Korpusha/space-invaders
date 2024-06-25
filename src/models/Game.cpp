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
        this->pollEvents();
        this->handleInput();
        this->render();
    }
}

void Game::pollEvents()
{
    this->windowContext->pollEvents();
}

void Game::handleInput()
{
    this->windowContext->handleInput();
}

void Game::render()
{
    this->windowContext->render();
}

bool Game::running()
{
    return this->windowContext->running();
}
