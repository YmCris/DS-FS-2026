//
// Created by cristian on 2/21/26.
//

#include "../../../include/card_game/application/shuffle/Shuffle.h"


// LIFETIME

// PUBLIC API
/**
 * This method only have to be used when create the deck
 */
void Shuffle::organize()
{
    // 1. Check if the list have the 7 start elements
    // 2. Insert
}

void Shuffle::addCard(Card* card)
{
    /*INSERTION SORT*/
}

Card* Shuffle::useCard(int position)
{
    return cards_.removeAt(position);
}

const DoubleLinkedList<Card*>& Shuffle::cards() const
{
    return cards_;
}

// HELPERS
