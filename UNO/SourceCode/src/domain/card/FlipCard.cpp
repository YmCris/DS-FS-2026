//
// Created by cristian on 2/18/26.
//

#include "../../../include/card_game/domain/card/FlipCard.h"

public
:
// LIFETIME

// PUBLIC API

private
:
// HELPERS

// DATA MEMBERS
FlipCard::FlipCard(const CardColor color, const CardValue value,
                   const bool flip) : Card(color, value, flip)
{
}
