#include "headers/WindowState.h"

WindowState::WindowState()
{
    auto* font_ = new sf::Font();
    font_->loadFromFile(WindowState::getFontFolderPath() + WindowState::FONT);

    this->textFont = font_;
    this->schemeColorGreen = new sf::Color(40, 180, 30);
    this->schemeColorBlack = new sf::Color(0, 0, 0);
}

WindowState::~WindowState()
{
    delete this->textFont;
    delete this->schemeColorGreen;
    delete this->schemeColorBlack;
}

WindowState* WindowState::update(sf::RenderWindow &window, sf::Event& ev)
{
    return nullptr;
}

void WindowState::render(sf::RenderWindow &window)
{
    window.clear(*this->schemeColorBlack);
    window.display();
}

std::string WindowState::getFontFolderPath()
{
    return WindowState::STATIC_PATH + "fonts/";
}

std::string WindowState::getAssetsFolderPath()
{
    return WindowState::STATIC_PATH + "assets/";
}
