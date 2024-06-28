#include "headers/ScoreWindowState.h"

ScoreWindowState::ScoreWindowState(Player* player)
{
    this->setScoreText(std::to_string(player->getRecord()->getValue()));
    this->setScoreRectShape();
    this->setRecordTexts(*player->getRecord());
    this->setContinueText();
}

ScoreWindowState::~ScoreWindowState()
{
    delete this->scoreText;
    delete this->scoreRectShape;
    for (auto& record : this->recordTexts) {
        delete record;
    }
    delete this->continueText;
}

void ScoreWindowState::setScoreText(const std::string& playerScore)
{
    this->scoreText = new sf::Text();
    this->scoreText->setString("Score: " + playerScore);
    this->scoreText->setFont(*this->textFont);
    this->scoreText->setCharacterSize(30);
    this->scoreText->setFillColor(StaticManager::GREEN);
}

void ScoreWindowState::setScoreRectShape()
{
    this->scoreRectShape = new sf::RectangleShape(sf::Vector2f {1000, 550 });
    this->scoreRectShape->setFillColor(StaticManager::BLACK);
}

void ScoreWindowState::setRecordTexts(Record& playerRecord)
{
    Record::appendToFile(playerRecord);

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

        if (playerRecord == record) {
            recordText->setStyle(sf::Text::Bold);
        }

        this->recordTexts.emplace_back(recordText);
    }
}

void ScoreWindowState::setContinueText()
{
    this->continueText = new sf::Text();
    this->continueText->setString("Press enter to retry...");
    this->continueText->setFont(*this->textFont);
    this->continueText->setCharacterSize(30);
    this->continueText->setFillColor(StaticManager::GREEN);
}

WindowState *ScoreWindowState::update(sf::RenderWindow &window, sf::Event &ev)
{
    window.setMouseCursorVisible(false);

    if (ev.type == sf::Event::Closed) {
        return new EndScreenWindowState();
    }

    if (ev.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        return new EndScreenWindowState();
    }

    if (ev.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            return new IntroWindowState();
        }
    }

    return nullptr;
}

void ScoreWindowState::render(sf::RenderWindow &window)
{
    window.clear(StaticManager::BLACK);

    sf::FloatRect scoreBoxRect = this->scoreRectShape->getLocalBounds();
    this->scoreRectShape->setOrigin(scoreBoxRect.left + scoreBoxRect.width / 2.0f, scoreBoxRect.top + scoreBoxRect.height / 2.0f);
    this->scoreRectShape->setPosition((float) window.getSize().x / 2.0f, (float) window.getSize().y / 2.0f);
    window.draw(*this->scoreRectShape);

    sf::FloatRect continueHintTextRect = this->continueText->getLocalBounds();
    this->continueText->setOrigin(continueHintTextRect.left + continueHintTextRect.width / 2.0f, 0.f);
    this->continueText->setPosition(this->scoreRectShape->getPosition().x, (this->scoreRectShape->getPosition().y + scoreBoxRect.height / 2.0f));
    window.draw(*this->continueText);

    sf::FloatRect scoreTextRect = this->scoreText->getLocalBounds();
    this->scoreText->setOrigin(scoreTextRect.width + 25.f, 0.f);
    this->scoreText->setPosition(this->scoreRectShape->getPosition().x + scoreBoxRect.width / 2.0f, this->scoreRectShape->getPosition().y - scoreBoxRect.height / 2.0f);
    window.draw(*this->scoreText);

    float yOffset = scoreTextRect.height + 50.f;
    for (auto& recordText : this->recordTexts) {
        sf::FloatRect recordTextRect = recordText->getLocalBounds();
        recordText->setOrigin(recordTextRect.left + recordTextRect.width / 2.0f, 0.f);
        recordText->setPosition(this->scoreRectShape->getPosition().x, this->scoreRectShape->getPosition().y - scoreBoxRect.height / 2.0f + yOffset);
        yOffset += recordTextRect.height + 20.f;
        window.draw(*recordText);
    }

    window.display();
}
