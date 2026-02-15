//
// Created by cristian on 2/14/26.
//

#include "../../../include/card_game/domain/card/Card.h"

// LIFETIME
Card::Card(const CardColor color, const CardValue value) :
    color_(color),
    value_(value)
{
}

// PUBLIC API
CardColor Card::color() const
{
    return color_;
}

CardValue Card::value() const
{
    return value_;
}
