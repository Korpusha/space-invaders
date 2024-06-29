#ifndef SPACE_INVADERS_VIEWSCOREWINDOWSTATE_H
#define SPACE_INVADERS_VIEWSCOREWINDOWSTATE_H


#include "ScoreWindowState.h"
#include "MenuWindowState.h"

class ViewScoreWindowState: public ScoreWindowState {
    using ScoreWindowState::ScoreWindowState;
public:
    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void render(sf::RenderWindow &window) override;
};


#endif
