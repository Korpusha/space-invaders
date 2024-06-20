#include "headers/ScoreWindowState.h"

ScoreWindowState::ScoreWindowState(Player* player)
{
    std::string playerScore = std::to_string(player->getRecord()->getValue());

    this->scoreText = new sf::Text();
    this->scoreText->setString("Score: " + playerScore);
    this->scoreText->setFont(*this->textFont);
    this->scoreText->setCharacterSize(30);
    this->scoreText->setFillColor(*this->schemeColorGreen);

    this->continueHintText = new sf::Text();
    this->continueHintText->setString("Press enter to continue...");
    this->continueHintText->setFont(*this->textFont);
    this->continueHintText->setCharacterSize(30);
    this->continueHintText->setFillColor(*this->schemeColorGreen);

    this->scoreBox = new sf::RectangleShape(Vector2f {1000, 550 });
    this->scoreBox->setFillColor(*this->schemeColorBlack);

    Record::appendToFile(*player->getRecord());
    this->recordScores = Record::loadFromFile();

    this->recordTexts = std::vector<sf::Text*> {};
    std::stringstream recordsStream;

    for (auto& i : this->recordScores) {
        auto* recordText = new Text();

        recordsStream << i;
        recordText->setString(recordsStream.str());
        recordsStream.str("");

        recordText->setFont(*this->textFont);
        recordText->setCharacterSize(30);
        recordText->setFillColor(*this->schemeColorGreen);

        if (*player->getRecord() == i) {
            recordText->setStyle(sf::Text::Bold);
        }

        this->recordTexts.emplace_back(recordText);
    }
}

WindowState *ScoreWindowState::update(sf::RenderWindow &window, sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            return new EndScreenWindowState();
        }
    }

    return nullptr;
}

void ScoreWindowState::render(sf::RenderWindow &window)
{
    // Background
    window.clear(*this->schemeColorBlack);

    // Score box
    sf::FloatRect scoreBoxRect = this->scoreBox->getLocalBounds();
    this->scoreBox->setOrigin(scoreBoxRect.left + scoreBoxRect.width / 2.0f, scoreBoxRect.top + scoreBoxRect.height / 2.0f);
    this->scoreBox->setPosition((float) window.getSize().x / 2.0f,(float) window.getSize().y / 2.0f);
    window.draw(*this->scoreBox);

    // Continue hint text
    sf::FloatRect continueHintTextRect = this->continueHintText->getLocalBounds();
    this->continueHintText->setOrigin(continueHintTextRect.left + continueHintTextRect.width / 2.0f, 0.f);
    this->continueHintText->setPosition(this->scoreBox->getPosition().x, (this->scoreBox->getPosition().y + scoreBoxRect.height / 2.0f));
    window.draw(*this->continueHintText);

    // Score text
    sf::FloatRect scoreTextRect = this->scoreText->getLocalBounds();
    this->scoreText->setOrigin(scoreTextRect.width + 25.f, 0.f);
    this->scoreText->setPosition(this->scoreBox->getPosition().x + scoreBoxRect.width / 2.0f, this->scoreBox->getPosition().y - scoreBoxRect.height / 2.0f);
    window.draw(*this->scoreText);

    // Record texts
    float yOffset = scoreTextRect.height + 50.f;
    for (auto& recordText : this->recordTexts) {
        sf::FloatRect recordTextRect = recordText->getLocalBounds();
        recordText->setOrigin(recordTextRect.left + recordTextRect.width / 2.0f, 0.f);
        recordText->setPosition(this->scoreBox->getPosition().x, this->scoreBox->getPosition().y - scoreBoxRect.height / 2.0f + yOffset);
        yOffset += recordTextRect.height + 20.f;
        window.draw(*recordText);
    }

    window.display();
}

ScoreWindowState::~ScoreWindowState()
{
    delete this->scoreText;
    for (auto& record : this->recordTexts) {
        delete record;
    }
    delete this->continueHintText;
    delete this->scoreBox;
}
