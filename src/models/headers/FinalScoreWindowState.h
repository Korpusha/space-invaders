#ifndef SPACE_INVADERS_FINALSCOREWINDOWSTATE_H
#define SPACE_INVADERS_FINALSCOREWINDOWSTATE_H


#include "ScoreWindowState.h"
#include "MenuWindowState.h"
#include "EndScreenWindowState.h"
#include "Record.h"

class FinalScoreWindowState: public ScoreWindowState {
    using ScoreWindowState::ScoreWindowState;
private:
    sf::Text* scoreText;
    sf::Text* continueText;

    void setScoreText(const std::string& playerScore);
    void setContinueText();
public:
    explicit FinalScoreWindowState(Record& playerRecord);
    ~FinalScoreWindowState() override;

    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void render(sf::RenderWindow &window) override;
};


#endif
