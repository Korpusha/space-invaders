#include "headers/IntroWindowState.h"

void IntroWindowState::setup(sf::RenderWindow &window)
{
    // Font
    sf::Font font;
    if (!font.loadFromFile(R"(..\..\static\fonts\cour.ttf)")) {
        std::cout << "Font wasn't found" << std::endl;
    }

    // Intro text
    sf::Text introductionText {};
    introductionText.setString("Input the nickname and press enter to continue...");
    introductionText.setFont(font);
    introductionText.setFillColor(sf::Color(16, 121, 30));
    introductionText.setCharacterSize(36);
}

WindowState* IntroWindowState::update(sf::RenderWindow& window, sf::Event& ev)
{
    if (ev.type == sf::Event::TextEntered) {
        if (ev.text.unicode < 128) {
            std::cout << ev.text.unicode << std::endl;
        }
    }

    if (ev.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            return new GameWindowState();
        }
    }

    return nullptr;
}

void IntroWindowState::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);

    // Intro text
//    introductionText.setPosition(25.f, 0.f);
//    sf::FloatRect textRect = introductionText.getLocalBounds();
//    introductionText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
//    introductionText.setPosition(sf::Vector2f((float) window.getSize().x / 2.0f,(float) window.getSize().y / 3.0f));
//    window.draw(introductionText);

    // Cursor
    sf::RectangleShape cursor(sf::Vector2f(3.f, 36.f));
    cursor.setPosition(sf::Vector2f(25.f, 100.f));
    window.draw(cursor);

    window.display();
}
