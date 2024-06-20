#include "headers/GameWindowState.h"

GameWindowState::GameWindowState(const std::string &playerNickname)
{
    this->setPlayer(playerNickname);
}

void GameWindowState::setPlayer(const std::string &playerNickname)
{
    auto *allySpaceship = new AllySpaceship(GameWindowState::getAssetsFolderPath() + GameWindowState::ALLY_SPACESHIP_TEXTURE, Vector2f {0.f , 0.f });
    allySpaceship->getSprite()->scale(0.1, 0.1);
    this->player = new Player(playerNickname, allySpaceship);
}

WindowState *GameWindowState::update(sf::RenderWindow &window, sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            return new ScoreWindowState(this->player);
        }
    }

    return nullptr;
}

void GameWindowState::render(sf::RenderWindow &window)
{
    window.clear(*this->schemeColorBlack);
    window.display();
}
