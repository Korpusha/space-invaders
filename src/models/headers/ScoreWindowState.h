#ifndef SPACE_INVADERS_SCOREWINDOWSTATE_H
#define SPACE_INVADERS_SCOREWINDOWSTATE_H


#include <sstream>
#include "WindowState.h"
#include "EndScreenWindowState.h"
#include "Record.h"

class ScoreWindowState: public WindowState {
    using WindowState::WindowState;
protected:
    sf::RectangleShape* scoreRectShape;
    std::vector<sf::Text*> recordTexts;
    void setRecordTexts();
    void setScoreRectShape();
public:
    ScoreWindowState();
    ~ScoreWindowState() override;

    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void render(sf::RenderWindow &window) override;
};


#endif
