#include "models/headers/CreditsWindowState.h"

CreditsWindowState::CreditsWindowState()
{
    this->titleText = new sf::Text();
    this->titleText->setString("Credits");
    this->titleText->setFont(*this->textFont);
    this->titleText->setCharacterSize(30);
    this->titleText->setFillColor(StaticManager::GREEN);

    sf::FloatRect titleTextRect = this->titleText->getGlobalBounds();
    this->titleText->setOrigin(titleTextRect.left + titleTextRect.width / 2.0f, titleTextRect.top + titleTextRect.height / 2.0f);

    this->creditsText = new sf::Text();
    this->creditsText->setString("Korpusha");
    this->creditsText->setFont(*this->textFont);
    this->creditsText->setCharacterSize(30);
    this->creditsText->setFillColor(StaticManager::GREEN);
    this->creditsText->setStyle(sf::Text::Bold);

    sf::FloatRect creditsTextRect = this->creditsText->getGlobalBounds();
    this->creditsText->setOrigin(creditsTextRect.left + creditsTextRect.width / 2.0f, creditsTextRect.top + creditsTextRect.height / 2.0f);
}

CreditsWindowState::~CreditsWindowState()
{
    delete this->titleText;
    delete this->creditsText;
}

WindowState *CreditsWindowState::update(sf::RenderWindow &window, sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        return new IntroWindowState();
    }

    return nullptr;
}

void CreditsWindowState::render(sf::RenderWindow &window)
{
    window.setMouseCursorVisible(false);

    window.clear(StaticManager::BLACK);

    this->titleText->setPosition((float) window.getSize().x / 2.0f,(float) window.getSize().y / 3.0f);
    window.draw(*this->titleText);

    this->creditsText->setPosition((float) window.getSize().x / 2.0f,(float) window.getSize().y / 2.0f);
    window.draw(*this->creditsText);

    window.display();
}
