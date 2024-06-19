#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H


#include <iostream>
#include "SFML/Graphics.hpp"
#include "WindowContext.h"

class Game
{
private:
    WindowContext* windowContext = nullptr;
private:
    void setWindowContext();
    void update();
    void render();
    bool running();
public:
    Game();
    ~Game();
    void run();
};


#endif
