#include "headers/GameWindowState.h"

using namespace std;

GameWindowState::GameWindowState(const std::string &playerNickname, sf::RenderWindow &window)
{
    this->setPlayableArea(window);
    this->setPlayer(playerNickname);
    this->setEnemySpaceshipSquadron();
    this->setScoreText();
    this->setPlayerLives();
}

GameWindowState::~GameWindowState()
{
    delete this->playableArea;
    delete this->scoreText;
    delete this->enemySpaceshipSquadron;
    delete this->playerLives;
}

void GameWindowState::setPlayableArea(sf::RenderWindow &window)
{
    this->playableArea = new sf::RectangleShape(sf::Vector2f { 800, 800 });
    this->playableArea->setFillColor(StaticManager::BLACK);
    this->playableArea->setOutlineColor(StaticManager::GREEN);
    this->playableArea->setOutlineThickness(2);

    sf::FloatRect playableAreaRect = this->playableArea->getLocalBounds();
    this->playableArea->setOrigin(playableAreaRect.left + playableAreaRect.width / 2.f, playableAreaRect.top + playableAreaRect.height / 2.f);
    this->playableArea->setPosition((float) window.getSize().x / 2.f,(float) window.getSize().y / 2.f);
}

void GameWindowState::setPlayer(const std::string &playerNickname)
{
    this->player = new Player(playerNickname, this->getAllySpaceship());
}

void GameWindowState::setEnemySpaceshipSquadron()
{
    this->enemySpaceshipSquadron = new EnemySpaceshipSquadron(
            std::vector<EnemySpaceship::Type> {
                EnemySpaceship::Type::Top,
                EnemySpaceship::Type::Middle,
                EnemySpaceship::Type::Middle,
                EnemySpaceship::Type::Bottom,
                EnemySpaceship::Type::Bottom,
            },
            8, 70, 50, *this->playableArea
    );
}

void GameWindowState::setScoreText()
{
    this->scoreText = new sf::Text();
    this->scoreText->setFont(*this->textFont);
    this->scoreText->setCharacterSize(30);
    this->scoreText->setFillColor(StaticManager::GREEN);
}

void GameWindowState::setPlayerLives()
{
    this->playerLives = new sf::Text();
    this->playerLives->setFont(*this->textFont);
    this->playerLives->setCharacterSize(30);
    this->playerLives->setFillColor(StaticManager::GREEN);
}

AllySpaceship* GameWindowState::getAllySpaceship() const
{
    auto* allySpaceshipSpriteEntity = new SpriteEntity(StaticManager::getAllySpaceshipImage());
    sf::FloatRect allySpaceshipRect = allySpaceshipSpriteEntity->getSprite()->getLocalBounds();
    allySpaceshipSpriteEntity->getSprite()->setOrigin(allySpaceshipRect.left + allySpaceshipRect.width / 2.f, 0.f);
    allySpaceshipSpriteEntity->getSprite()->setScale(sf::Vector2f { 4.f, 4.f });
    allySpaceshipSpriteEntity->getSprite()->setColor(StaticManager::GREEN);
    allySpaceshipSpriteEntity->setPosition(sf::Vector2f {
            this->playableArea->getPosition().x,
            this->playableArea->getPosition().y + (this->playableArea->getLocalBounds().height / 2.f) - allySpaceshipSpriteEntity->getSprite()->getGlobalBounds().height - 30.f
    });
    allySpaceshipSpriteEntity->setXVelocity(AllySpaceship::X_VELOCITY);

    auto* bullet = new Bullet(new RectangleShapeEntity(sf::Vector2f { 5.f, 20.f }), 5.f);
    bullet->getEntity()->getRectangleShape()->setFillColor(StaticManager::GREEN);

    auto *gun = new PlayerGun(
        new RectangleShapeEntity(sf::Vector2f { 0.f, 0.f }),
        bullet,
        AllySpaceship::GUN_RELOAD_SEC
    );

    return new AllySpaceship(allySpaceshipSpriteEntity, gun, AllySpaceshipState::AllySpaceshipStayStill, AllySpaceship::LIVES_DEFAULT);
}

WindowState *GameWindowState::update(sf::RenderWindow &window, sf::Event &ev)
{
    window.setMouseCursorVisible(false);

    if (ev.type == sf::Event::Closed) {
        return new EndScreenWindowState();
    }

    if (ev.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        return new EndScreenWindowState();
    }

    this->player->getAllySpaceship()->update();
    if (this->enemySpaceshipSquadron->isDefeated() || !this->player->getAllySpaceship()->isAlive()) {
        Record::appendToFile(*this->player->getRecord());
        return new FinalScoreWindowState(*this->player->getRecord());
    }
    return nullptr;
}

void GameWindowState::handleInput()
{
    this->enemySpaceshipSquadron->update(*this->playableArea);
    this->player->getAllySpaceship()->handleInput(*this->playableArea, *this->enemySpaceshipSquadron, *this->player->getRecord());
}

void GameWindowState::render(sf::RenderWindow &window)
{
    window.clear(StaticManager::BLACK);

    window.draw(*this->playableArea);

    this->enemySpaceshipSquadron->render(window);

    this->player->getAllySpaceship()->render(window);

    this->scoreText->setString("Score: " + std::to_string(this->player->getRecord()->getValue()));
    this->scoreText->setPosition(this->playableArea->getPosition().x - this->playableArea->getSize().x / 2.f,
                                 this->playableArea->getPosition().y + this->playableArea->getSize().y / 2.f);
    window.draw(*this->scoreText);

    this->playerLives->setString("x" + std::to_string(this->player->getAllySpaceship()->getLives()));
    sf::FloatRect playerLivesRect = this->playerLives->getGlobalBounds();
    this->playerLives->setPosition(this->playableArea->getPosition().x + this->playableArea->getSize().x / 2.f - playerLivesRect.getSize().x,
                                   this->playableArea->getPosition().y + this->playableArea->getSize().y / 2.f);
    window.draw(*this->playerLives);

    window.display();
}
