#include "headers/ScoreWindowState.h"

ScoreWindowState::ScoreWindowState()
{
    this->setScoreRectShape();
    this->setRecordTexts();
}

ScoreWindowState::~ScoreWindowState()
{
    delete this->scoreRectShape;
    for (auto& record : this->recordTexts) {
        delete record;
    }
}

void ScoreWindowState::setScoreRectShape()
{
    this->scoreRectShape = new sf::RectangleShape(sf::Vector2f { 1000, 550 });
    this->scoreRectShape->setFillColor(StaticManager::BLACK);
}

void ScoreWindowState::setRecordTexts()
{
    this->recordTexts = std::vector<sf::Text*> {};
    std::stringstream recordsStream;

    for (auto& record : Record::loadFromFile()) {
        auto* recordText = new sf::Text();

        recordsStream << record;
        recordText->setString(recordsStream.str());
        recordsStream.str("");

        recordText->setFont(*this->textFont);
        recordText->setCharacterSize(30);
        recordText->setFillColor(StaticManager::GREEN);

        this->recordTexts.emplace_back(recordText);
    }
}

WindowState *ScoreWindowState::update(sf::RenderWindow &window, sf::Event &ev)
{
    window.setMouseCursorVisible(false);

    if (ev.type == sf::Event::Closed) {
        return new EndScreenWindowState();
    }

    return nullptr;
}

void ScoreWindowState::render(sf::RenderWindow &window)
{
    sf::FloatRect scoreBoxRect = this->scoreRectShape->getLocalBounds();
    this->scoreRectShape->setOrigin(scoreBoxRect.left + scoreBoxRect.width / 2.0f, scoreBoxRect.top + scoreBoxRect.height / 2.0f);
    this->scoreRectShape->setPosition((float) window.getSize().x / 2.0f, (float) window.getSize().y / 2.0f);
    window.draw(*this->scoreRectShape);

    float yOffset = 50.f;
    for (auto& recordText : this->recordTexts) {
        sf::FloatRect recordTextRect = recordText->getLocalBounds();
        recordText->setOrigin(recordTextRect.left + recordTextRect.width / 2.0f, 0.f);
        recordText->setPosition(this->scoreRectShape->getPosition().x, this->scoreRectShape->getPosition().y - scoreBoxRect.height / 2.0f + yOffset);
        yOffset += recordTextRect.height + 20.f;
        window.draw(*recordText);
    }
}
