#ifndef SPACE_INVADERS_WINDOWCONTEXT_H
#define SPACE_INVADERS_WINDOWCONTEXT_H


#include <SFML/Graphics.hpp>
#include "WindowState.h"
#include "IntroWindowState.h"
#include "EndScreenWindowState.h"

class WindowContext {
private:
    sf::RenderWindow* window;
    sf::Event ev {};
    WindowState* windowState;
    const std::string TITLE = "SpaceInvaders";
    const std::string FONT = "cour.ttf";
public:
    WindowContext();
    ~WindowContext();
    void pollEvents();
    void handleInput();
    void render();
    bool running();
    void resetWindowState(WindowState* newWindowState);
};


#endif
