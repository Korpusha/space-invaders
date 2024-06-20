#ifndef SPACE_INVADERS_SCOREWINDOWSTATE_H
#define SPACE_INVADERS_SCOREWINDOWSTATE_H


#include "Player.h"
#include "WindowState.h"
#include "EndScreenWindowState.h"

class ScoreWindowState: public WindowState {
private:
    sf::Text* scoreText;
    sf::RectangleShape* scoreBox;
    std::vector<sf::Text*> recordTexts;
    sf::Text* continueHintText;
    std::vector<Record> recordScores;
public:
    explicit ScoreWindowState(Player* player);
    ~ScoreWindowState() override;
    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void render(sf::RenderWindow &window) override;
};


#endif
