#include "headers/Player.h"

Player::Player(const string& nickname_, AllySpaceship *allySpaceship_)
{
    this->setNickname(nickname_);
    this->setAllySpaceship(allySpaceship_);
    this->setRecord();
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

void Player::setRecord()
{
    this->record = new Record(this->getNickname(), 0);
}

string Player::getNickname()
{
    return this->nickname;
}

AllySpaceship *Player::getAllySpaceship()
{
    return this->allySpaceship;
}

Record *Player::getRecord()
{
    return this->record;
}
