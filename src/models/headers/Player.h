#ifndef SPACE_INVADERS_PLAYER_H
#define SPACE_INVADERS_PLAYER_H


#include <utility>
#include "AllySpaceship.h"
#include "Record.h"

class Player {
private:
    std::string nickname;
    AllySpaceship *allySpaceship;
    Record *record;
    void setNickname(const std::string& nickname_);
    void setRecord();
public:
    const int inline static NICKNAME_MAX_LENGTH = 10;

    Player() = delete;
    Player(const std::string& nickname_, AllySpaceship *allySpaceship_);
    ~Player();

    void setAllySpaceship(AllySpaceship *allySpaceship_);

    std::string getNickname();
    AllySpaceship *getAllySpaceship();
    Record *getRecord();
};


#endif
