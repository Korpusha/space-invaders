#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H


#include <iostream>
#include "SFML/Graphics.hpp"
#include "WindowContext.h"

class Game
{
private:
    WindowContext* windowContext = nullptr;
    void setWindowContext();
    void pollEvents();
    void handleInput();
    void render();
    bool running();
public:
    Game();
    ~Game();
    void run();
};


#endif
