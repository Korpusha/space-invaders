#ifndef SPACE_INVADERS_MENUWINDOWSTATE_H
#define SPACE_INVADERS_MENUWINDOWSTATE_H


#include "SpriteEntity.h"
#include "WindowState.h"
#include "IntroWindowState.h"
#include "CreditsWindowState.h"
#include "EndScreenWindowState.h"

class MenuWindowState: public WindowState {
private:
    SpriteEntity* logoSprite;
    sf::Text* playText;
    sf::Text* creditsText;
    sf::Text* exitText;
public:
    MenuWindowState();
    ~MenuWindowState() override;

    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void render(sf::RenderWindow &window) override;
};


#endif
