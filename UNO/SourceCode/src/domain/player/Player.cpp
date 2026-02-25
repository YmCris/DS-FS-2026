//
// Created by cristian on 2/22/26.
//

#include "../../../include/card_game/domain/player/Player.h"

// LIFETIME
Player::Player(const std::string& name) :
    blocked_(false),
    hasCards_(true),
    name_(name)
{
}

// PUBLIC API

bool Player::blocked() const
{
    return blocked_;
}

bool Player::hadCards() const
{
    return hasCards_;
}

void Player::setSayUno(bool say)
{
    sayUno_ = say;
}

bool Player::sayUno()
{
    return sayUno_;
}

Shuffle& Player::shuffle()
{
    return shuffle_;
}

std::string Player::name()
{
    return name_;
}
