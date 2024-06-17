#ifndef SPACE_INVADERS_PLAYER_H
#define SPACE_INVADERS_PLAYER_H


#include <utility>
#include "AllySpaceship.h"
#include "Record.h"

class Player {
private:
    string nickname;
    AllySpaceship *allySpaceship;
    Record<unsigned int> *record;
private:
    void setNickname(const string& nickname_);
    void setAllySpaceship(AllySpaceship *allySpaceship_);
    void setRecord(Record<unsigned int> *record_);
public:
    Player() = delete;
    Player(const string& nickname_, AllySpaceship *allySpaceship_, Record<unsigned int> *record_);
    ~Player();
    string getNickname();
    AllySpaceship *getAllySpaceship();
    Record<unsigned int> *getRecord();
};


#endif
