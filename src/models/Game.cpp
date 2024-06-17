#include "headers/Game.h"

Game::Game()
{
    this->setAppWindow();
    this->setPlayer();
}

Game::~Game()
{
    delete this->player;
    delete this->enemySpaceshipSquadron;
}

void Game::setAppWindow()
{
    this->appWindow = new AppWindow();
}

void Game::setPlayer()
{
    auto *allySpaceship = new AllySpaceship(Game::STATIC_FOLDER_PATH + R"(assets\spaceship\ally\ally_spaceship.png)", Vector2f {500.f, 500.f });
    allySpaceship->getSprite()->scale(0.1, 0.1);

    auto *record = new Record<unsigned int>("name", 20);

    this->player = new Player("player", allySpaceship, record);
}

void Game::run()
{
    while (this->running()) {
        this->update();
        this->render();
    }
}

void Game::update()
{
    this->appWindow->update();
}

void Game::render()
{
    this->appWindow->render();

    // ==================
    // == Introduction ==
    // ==================
//    {
//        this->window->clear(sf::Color::Black);
//
//        // Font
//        Font font;
//        if (!font.loadFromFile(Game::STATIC_FOLDER_PATH + "fonts/" + Game::DEFAULT_FONT)) {
//            cout << "Font wasn't found" << endl;
//        }
//
//        // Intro text
//        Text introductionText {};
//        introductionText.setString("Input the nickname and press enter to continue...");
//        introductionText.setFont(font);
//        introductionText.setFillColor(Color(16, 121, 30));
//        introductionText.setCharacterSize(36);
//        introductionText.setPosition(25.f, 0.f);
//
//        sf::FloatRect textRect = introductionText.getLocalBounds();
//        introductionText.setOrigin(textRect.left + textRect.width / 2.0f,
//                                   textRect.top + textRect.height / 2.0f);
//        introductionText.setPosition(sf::Vector2f(this->window->getSize().x / 2.0f,this->window->getSize().y / 3.0f));
//
//        this->window->draw(introductionText);
//
//        // Cursor
//        RectangleShape cursor(Vector2f(3.f, 36.f));
//        cursor.setPosition(Vector2f(25.f, 100.f));
//        this->window->draw(cursor);
//
//        this->window->display();
//    }
    // ==================
    // ==================
    // ==================
}

bool Game::running()
{
    return this->appWindow->running();
}
