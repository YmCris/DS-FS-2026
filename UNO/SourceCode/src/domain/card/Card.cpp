//
// Created by cristian on 2/14/26.
//

#include "../../../include/card_game/domain/card/Card.h"

// CARD SIDE
Card::CardSide::CardSide(CardColor color, CardValue value) :
    color_(color),
    value_(value)
{
}

[[nodiscard]] CardColor Card::CardSide::color() const
{
    return color_;
}

[[nodiscard]] CardValue Card::CardSide::value() const
{
    return value_;
}

// CARD
Card::Card(CardSide front,
           std::optional<CardSide> back) :
    front_(front),
    back_(back)
{
}

Card::CardSide Card::front() const
{
    return front_;
}

std::optional<Card::CardSide> Card::back() const
{
    return back_;
}
