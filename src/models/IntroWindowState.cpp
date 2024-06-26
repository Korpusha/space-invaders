#include "headers/IntroWindowState.h"

IntroWindowState::IntroWindowState()
{
    this->introText = new sf::Text();
    this->introText->setString("Input the nickname and press enter to continue...");
    this->introText->setFont(*this->textFont);
    this->introText->setCharacterSize(30);
    this->introText->setFillColor(StaticManager::GREEN);

    this->inputText = new sf::Text();
    this->inputText->setFont(*this->textFont);
    this->inputText->setCharacterSize(30);
    this->inputText->setFillColor(StaticManager::GREEN);
    this->inputText->setStyle(sf::Text::Bold);
}

IntroWindowState::~IntroWindowState()
{
    delete this->introText;
    delete this->inputText;
}

WindowState* IntroWindowState::update(sf::RenderWindow& window, sf::Event& ev)
{
    window.setMouseCursorVisible(false);

    if (ev.type == sf::Event::Closed) {
        return new EndScreenWindowState();
    }

    if (ev.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        return new MenuWindowState();
    }

    if (ev.type == sf::Event::TextEntered) {
        char inputChar = static_cast<char>(ev.text.unicode);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
            this->eraseNicknameChar();
        } else {
            this->appendNicknameChar(inputChar);
        }
        this->inputText->setString(this->playerNickname);
    }

    if (ev.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !this->playerNickname.empty()) {
            return new GameWindowState(this->playerNickname, window);
        }
    }

    return nullptr;
}

void IntroWindowState::render(sf::RenderWindow &window)
{
    window.clear(StaticManager::BLACK);

    sf::FloatRect introTextRect = this->introText->getLocalBounds();
    this->introText->setOrigin(introTextRect.left + introTextRect.width / 2.0f, introTextRect.top + introTextRect.height / 2.0f);
    this->introText->setPosition((float) window.getSize().x / 2.0f,(float) window.getSize().y / 3.0f);
    window.draw(*this->introText);

    sf::FloatRect playerInputRect = this->introText->getLocalBounds();
    this->inputText->setOrigin(playerInputRect.left + playerInputRect.width / 2.0f, playerInputRect.top + playerInputRect.height / 2.0f);
    this->inputText->setPosition((float) window.getSize().x / 2.0f, (float) (window.getSize().y / 2.5));
    window.draw(*this->inputText);

    window.display();
}

void IntroWindowState::appendNicknameChar(char inputChar)
{
    if (std::isalnum(inputChar) && this->playerNickname.size() < Player::NICKNAME_MAX_LENGTH) {
        this->playerNickname += inputChar;
    }
}

void IntroWindowState::eraseNicknameChar()
{
    if (!this->playerNickname.empty()) {
        this->playerNickname.erase(this->playerNickname.size() - 1, 1);
    }
}
