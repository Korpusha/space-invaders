#ifndef SPACE_INVADERS_WINDOWSTATE_H
#define SPACE_INVADERS_WINDOWSTATE_H


#include <SFML/Graphics.hpp>
#include <iostream>

class WindowState {
protected:
    sf::Font* textFont;
    sf::Color* schemeColorGreen;
    sf::Color* schemeColorBlack;
    inline static const std::string STATIC_PATH = R"(..\..\static\)";
    inline static const std::string FONT = "cour.ttf";
    inline static const std::string ALLY_SPACESHIP_TEXTURE = "ally_spaceship.png";
    inline static const std::string ENEMY_SPACESHIP_TEXTURE = "enemy_spaceship.png";
public:
    WindowState();
    virtual ~WindowState();
    virtual WindowState* update(sf::RenderWindow& window, sf::Event& ev);
    virtual void render(sf::RenderWindow& window);
    static std::string getFontFolderPath();
    static std::string getAssetsFolderPath();
};


#endif
