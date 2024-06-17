#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H


#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "EnemySpaceshipSquadron.h"
#include "AppWindow.h"

using namespace sf;
using namespace std;

class Game
{
private:
    AppWindow* appWindow = nullptr;
    Player* player = nullptr;
    EnemySpaceshipSquadron* enemySpaceshipSquadron = nullptr;
private:
    const string DEFAULT_TITLE = "SpaceInvaders";
    const string STATIC_FOLDER_PATH = R"(..\..\static\)";
    const string DEFAULT_FONT = "cour.ttf";
private:
    void setAppWindow();
    void setPlayer();
    void update();
    void render();
    bool running();
public:
    Game();
    ~Game();
    void run();
};


#endif
