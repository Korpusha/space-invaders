#ifndef SPACE_INVADERS_APPWINDOW_H
#define SPACE_INVADERS_APPWINDOW_H


#include <SFML/Graphics.hpp>
#include "WindowState.h"
#include "IntroWindowState.h"

class AppWindow {
private:
    sf::RenderWindow* window;
    sf::Event ev {};
    WindowState* windowState;
public:
    AppWindow();
    ~AppWindow();
    void update();
    void render();
    bool running();
};


#endif
