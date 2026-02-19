//
// Created by cristian on 2/14/26.
//

#include "../../../include/card_game/domain/card/Card.h"

// LIFETIME
Card::Card(CardColor color, CardValue value, bool flip) :
    color_(color),
    value_(value),
    flip_(flip)
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

bool Card::isFlip() const
{
    return flip_;
}

void Card::setIsFlip(const bool flip)
{
    flip_ = flip;
}

Card* Card::reverseCard() const
{
    return reverseCard_;
}

void Card::setReverseCard(Card* reverseCard)
{
    reverseCard_ = reverseCard;
}

Card* Card::currentCardSide() const
{
    return currentCardSide_;
}

void Card::setCurrentCardSide(Card* currentCardSide)
{
    currentCardSide_ = currentCardSide;
}
