#include "models/headers/FinalScoreWindowState.h"

FinalScoreWindowState::FinalScoreWindowState(Record& playerRecord)
{
    this->setScoreText(std::to_string(playerRecord.getValue()));
    this->setScoreRectShape();
    this->setRecordTexts();
    this->setContinueText();
}

FinalScoreWindowState::~FinalScoreWindowState()
{
    delete this->scoreText;
    delete this->continueText;
}

void FinalScoreWindowState::setScoreText(const std::string& playerScore)
{
    this->scoreText = new sf::Text();
    this->scoreText->setString("Score: " + playerScore);
    this->scoreText->setFont(*this->textFont);
    this->scoreText->setCharacterSize(30);
    this->scoreText->setFillColor(StaticManager::GREEN);
}

void FinalScoreWindowState::setContinueText()
{
    this->continueText = new sf::Text();
    this->continueText->setString("Press enter to retry...");
    this->continueText->setFont(*this->textFont);
    this->continueText->setCharacterSize(30);
    this->continueText->setFillColor(StaticManager::GREEN);
}

WindowState *FinalScoreWindowState::update(sf::RenderWindow &window, sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            return new MenuWindowState();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            return new EndScreenWindowState();
        }
    }

    return ScoreWindowState::update(window, ev);
}

void FinalScoreWindowState::render(sf::RenderWindow &window)
{
    window.clear(StaticManager::BLACK);
    ScoreWindowState::render(window);

    sf::FloatRect scoreBoxRect = this->scoreRectShape->getLocalBounds();

    sf::FloatRect continueHintTextRect = this->continueText->getLocalBounds();
    this->continueText->setOrigin(continueHintTextRect.left + continueHintTextRect.width / 2.0f, 0.f);
    this->continueText->setPosition(this->scoreRectShape->getPosition().x, (this->scoreRectShape->getPosition().y + scoreBoxRect.height / 2.0f));
    window.draw(*this->continueText);

    sf::FloatRect scoreTextRect = this->scoreText->getLocalBounds();
    this->scoreText->setOrigin(scoreTextRect.width + 25.f, 0.f);
    this->scoreText->setPosition(this->scoreRectShape->getPosition().x + scoreBoxRect.width / 2.0f, this->scoreRectShape->getPosition().y - scoreBoxRect.height / 2.0f);
    window.draw(*this->scoreText);

    window.display();
}
