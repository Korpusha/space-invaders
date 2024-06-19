#ifndef SPACE_INVADERS_INTROWINDOWSTATE_H
#define SPACE_INVADERS_INTROWINDOWSTATE_H


#include "WindowState.h"
#include "GameWindowState.h"

class IntroWindowState: public WindowState {
protected:
    sf::Text* introText;
    sf::Text* inputText;
    std::string playerNickname;
public:
    IntroWindowState();
    ~IntroWindowState();
    WindowState* update(sf::RenderWindow &window, sf::Event& ev) override;
    void render(sf::RenderWindow &window) override;
    void appendNicknameChar(char inputChar);
    void eraseNicknameChar();
};


#endif
