//
// Created by cristian on 2/18/26.
//

#include "../../../include/card_game/domain/card/ColorWildCard.h"

// LIFETIME
ColorWildCard::ColorWildCard(
    const CardColor color,
    const CardValue value,
    const bool flip
) :
    Card(color, value, flip)
{
}

// PUBLIC API
