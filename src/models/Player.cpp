#include "headers/Player.h"

Player::Player(const string& nickname_, AllySpaceship *allySpaceship_, Record<unsigned int> *record_)
{
    this->setNickname(nickname_);
    this->setAllySpaceship(allySpaceship_);
    this->setRecord(record_);
}

Player::~Player()
{
    delete this->allySpaceship;
    delete this->record;
}

void Player::setNickname(const string& nickname_)
{
    this->nickname = nickname_;
}

void Player::setAllySpaceship(AllySpaceship *allySpaceship_)
{
    this->allySpaceship = allySpaceship_;
}

void Player::setRecord(Record<unsigned int> *record_)
{
    this->record = record_;
}

string Player::getNickname()
{
    return this->nickname;
}

AllySpaceship *Player::getAllySpaceship()
{
    return this->allySpaceship;
}

Record<unsigned int> *Player::getRecord()
{
    return this->record;
}
