#include "models/headers/StaticManager.h"

std::string StaticManager::getFont()
{
    return StaticManager::FONTS + StaticManager::FONT;
}

sf::Image StaticManager::getSpaceInvadersImage()
{
    sf::Image spaceInvadersImage;
    spaceInvadersImage.loadFromFile(StaticManager::ASSETS + StaticManager::SPACE_INVADERS);

    return spaceInvadersImage;
}

sf::Image StaticManager::getAllySpaceshipImage()
{
    sf::Image spaceInvadersImage = StaticManager::getSpaceInvadersImage();

    sf::Image allySpaceshipImage;
    allySpaceshipImage.create(11, 12);
    allySpaceshipImage.copy(spaceInvadersImage, 0, 0, sf::IntRect { 68, 4, 11, 12 });

    return allySpaceshipImage;
}

std::string StaticManager::getScores()
{
    return StaticManager::SCORES;
}
