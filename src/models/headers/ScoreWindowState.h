#ifndef SPACE_INVADERS_SCOREWINDOWSTATE_H
#define SPACE_INVADERS_SCOREWINDOWSTATE_H


#include "Player.h"
#include "WindowState.h"
#include "EndScreenWindowState.h"

class ScoreWindowState: public WindowState {
private:
    sf::Text* scoreText;
    sf::RectangleShape* scoreRectShape;
    std::vector<sf::Text*> recordTexts;
    sf::Text* continueText;

    void setScoreText(const std::string& playerScore);
    void setScoreRectShape();
    void setRecordTexts(Record& playerRecord);
    void setContinueText();
public:
    explicit ScoreWindowState(Player* player);
    ~ScoreWindowState() override;

    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void render(sf::RenderWindow &window) override;
};


#endif
