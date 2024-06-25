#ifndef SPACE_INVADERS_INTROWINDOWSTATE_H
#define SPACE_INVADERS_INTROWINDOWSTATE_H


#include "WindowState.h"
#include "GameWindowState.h"

class IntroWindowState: public WindowState {
private:
    sf::Text* introText;
    sf::Text* inputText;
    std::string playerNickname;

    void appendNicknameChar(char inputChar);
    void eraseNicknameChar();
public:
    IntroWindowState();
    ~IntroWindowState() override;

    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void render(sf::RenderWindow &window) override;
};


#endif
