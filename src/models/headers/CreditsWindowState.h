#ifndef SPACE_INVADERS_CREDITSWINDOWSTATE_H
#define SPACE_INVADERS_CREDITSWINDOWSTATE_H


#include "WindowState.h"
#include "IntroWindowState.h"

class CreditsWindowState: public WindowState {
private:
    sf::Text* titleText;
    sf::Text* creditsText;
public:
    CreditsWindowState();
    ~CreditsWindowState() override;

    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void render(sf::RenderWindow &window) override;
};


#endif
