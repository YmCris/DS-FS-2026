//
// Created by cristian on 2/18/26.
//

#include "../../../include/card_game/domain/card/NumberCard.h"

#include <stdexcept>

// LIFETIME
NumberCard::NumberCard(CardColor color, CardValue value, bool flip)
    : Card(color, value, flip)
{
}

// PUBLIC API
CardValue NumberCard::play() const
{
    return value();
}

bool NumberCard::isPlayable(const Card& card) const
{
    return color() == card.color() ||
        value() == card.value();
}

void NumberCard::flip()
{
    if (!isFlip())
        throw std::logic_error("You can't flip, this card is no flip");

    if (reverseCard() == nullptr)
        throw std::logic_error("You can't flip, revers card is nullptr");

    if (currentCardSide() == this)
    {
        setCurrentCardSide(reverseCard());
    }
    else
    {
    }
}
