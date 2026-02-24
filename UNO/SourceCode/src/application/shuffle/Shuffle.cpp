//
// Created by cristian on 2/21/26.
//

#include "../../../include/card_game/application/shuffle/Shuffle.h"

#include <iostream>

#include "../../../include/card_game/core/utilities/Utilities.h"


// LIFETIME

// PUBLIC API
/**
 * This method only have to be used when create the deck
 */
Shuffle::Shuffle()
{
}

void Shuffle::organize()
{
    // 1. Check if the list have the 7 start elements
    /* card hierarchy
     *
     */
}

void Shuffle::addCard(Card* card)
{
    /*INSERTION SORT*/
    cards_.addLast(card);
}

Card* Shuffle::useCard(int position)
{
    return cards_.removeAt(position);
}

const DoubleLinkedList<Card*>& Shuffle::cards() const
{
    return cards_;
}

void Shuffle::printFront()
{
    Utilities utilities;
    for (int i = 0; i < cards_.getSize(); ++i)
    {
        std::cout << "   (" << i << ") " << utilities.valueToString(
                cards_.getAt(i)->value()->front().value())
            << " - " << utilities.colorToString(
                cards_.getAt(i)->value()->front().color()) << std::endl;
    }
}

void Shuffle::printBack()
{
    Utilities utilities;
    for (int i = 0; i < cards_.getSize(); ++i)
    {
        std::cout << "   (" << i << ") " << utilities.valueToString(
                cards_.getAt(i)->value()->back()->value())
            << " " << utilities.colorToString(
                cards_.getAt(i)->value()->back()->color()) << std::endl;
    }
}
