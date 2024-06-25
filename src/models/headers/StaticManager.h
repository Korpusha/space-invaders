#ifndef SPACE_INVADERS_STATICMANAGER_H
#define SPACE_INVADERS_STATICMANAGER_H


#include <SFML/Graphics.hpp>

class StaticManager {
private:
    inline static const std::string STATIC_PATH = R"(..\..\static\)";

    inline static const std::string FONTS = StaticManager::STATIC_PATH + R"(fonts\)";
    inline static const std::string FONT = "cour.ttf";

    inline static const std::string ASSETS = StaticManager::STATIC_PATH + R"(assets\)";
    inline static const std::string SPACE_INVADERS = "space_invaders.png";

    inline static const std::string SCORES = R"(..\..\src\scores.txt)";
public:
    inline static const sf::Color GREEN = sf::Color { 40, 180, 30 };
    inline static const sf::Color BLACK = sf::Color { 0, 0, 0 };

    static std::string getFont();

    static sf::Image getSpaceInvadersImage();
    static sf::Image getAllySpaceshipImage();

    static std::string getScores();
};


#endif
