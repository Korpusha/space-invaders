#include "models/headers/MenuWindowState.h"

MenuWindowState::MenuWindowState()
{
    this->logoSprite = new SpriteEntity(StaticManager::getLogoImage());
    this->logoSprite->getSprite()->setScale(0.2, 0.2);

    sf::FloatRect logoSpriteRect = this->logoSprite->getSprite()->getLocalBounds();
    this->logoSprite->getSprite()->setOrigin(logoSpriteRect.left + logoSpriteRect.width / 2.f, logoSpriteRect.top);

    this->playText = new sf::Text();
    this->playText->setString("Play");
    this->playText->setFont(*this->textFont);
    this->playText->setCharacterSize(30);
    this->playText->setFillColor(StaticManager::GREEN);

    sf::FloatRect playTextRect = this->playText->getLocalBounds();
    this->playText->setOrigin(playTextRect.left + playTextRect.width / 2.f, playTextRect.top + playTextRect.height / 2.f);

    this->scoreboardText = new sf::Text();
    this->scoreboardText->setString("Scoreboard");
    this->scoreboardText->setFont(*this->textFont);
    this->scoreboardText->setCharacterSize(30);
    this->scoreboardText->setFillColor(StaticManager::GREEN);

    sf::FloatRect scoreboardTextRect = this->scoreboardText->getLocalBounds();
    this->scoreboardText->setOrigin(scoreboardTextRect.left + scoreboardTextRect.width / 2.f, scoreboardTextRect.top + scoreboardTextRect.height / 2.f);

    this->creditsText = new sf::Text();
    this->creditsText->setString("Credits");
    this->creditsText->setFont(*this->textFont);
    this->creditsText->setCharacterSize(30);
    this->creditsText->setFillColor(StaticManager::GREEN);

    sf::FloatRect creditsTextRect = this->creditsText->getLocalBounds();
    this->creditsText->setOrigin(creditsTextRect.left + creditsTextRect.width / 2.f, creditsTextRect.top + creditsTextRect.height / 2.f);

    this->exitText = new sf::Text();
    this->exitText->setString("Exit");
    this->exitText->setFont(*this->textFont);
    this->exitText->setCharacterSize(30);
    this->exitText->setFillColor(StaticManager::GREEN);

    sf::FloatRect exitTextRect = this->exitText->getLocalBounds();
    this->exitText->setOrigin(exitTextRect.left + exitTextRect.width / 2.f, exitTextRect.top + exitTextRect.height / 2.f);
}

MenuWindowState::~MenuWindowState()
{
    delete this->logoSprite;
    delete this->playText;
    delete this->scoreboardText;
    delete this->creditsText;
    delete this->exitText;
}

WindowState *MenuWindowState::update(sf::RenderWindow &window, sf::Event &ev)
{
    window.setMouseCursorVisible(true);

    if (ev.type == sf::Event::Closed) {
        return new EndScreenWindowState();
    }

    if (ev.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        return new EndScreenWindowState();
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f mouseCoords = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (this->playText->getGlobalBounds().contains(mouseCoords)) {
            return new IntroWindowState();
        }

        if (this->scoreboardText->getGlobalBounds().contains(mouseCoords)) {
            return new ViewScoreWindowState();
        }

        if (this->creditsText->getGlobalBounds().contains(mouseCoords)) {
            return new CreditsWindowState();
        }

        if (this->exitText->getGlobalBounds().contains(mouseCoords)) {
            return new EndScreenWindowState();
        }
    }

    return nullptr;
}

void MenuWindowState::render(sf::RenderWindow &window)
{
    window.clear(StaticManager::BLACK);

    this->logoSprite->getSprite()->setPosition((float) window.getSize().x / 2.f, 100.f);
    window.draw(*this->logoSprite->getSprite());

    this->playText->setPosition((float) window.getSize().x / 2.f,(float) window.getSize().y / 2.25f);
    window.draw(*this->playText);

    this->scoreboardText->setPosition((float) window.getSize().x / 2.f,(float) window.getSize().y / 2.f);
    window.draw(*this->scoreboardText);

    this->creditsText->setPosition((float) window.getSize().x / 2.f, (float) window.getSize().y / 1.75f);
    window.draw(*this->creditsText);

    this->exitText->setPosition((float) window.getSize().x / 2.f, (float) window.getSize().y / 1.25f);
    window.draw(*this->exitText);

    window.display();
}
