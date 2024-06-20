#ifndef SPACE_INVADERS_PLAYER_H
#define SPACE_INVADERS_PLAYER_H


#include <utility>
#include "AllySpaceship.h"
#include "Record.h"

class Player {
private:
    string nickname;
    AllySpaceship *allySpaceship;
    Record *record;
    void setNickname(const string& nickname_);
    void setRecord();
public:
    Player() = delete;
    Player(const string& nickname_, AllySpaceship *allySpaceship_);
    ~Player();
    string getNickname();
    AllySpaceship *getAllySpaceship();
    Record *getRecord();
    void setAllySpaceship(AllySpaceship *allySpaceship_);
};


#endif
