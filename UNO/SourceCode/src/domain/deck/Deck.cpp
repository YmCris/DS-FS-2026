//
// Created by cristian on 2/17/26.
//

#include "../../../include/card_game/domain/deck/Deck.h"

// PUBLIC API
Deck::Deck(int players, bool flipModeActive, //I1 LinkedList<Card*>& list,
           std::vector<Card*>& ownedCards) :
    Stack<Card*>(cards_),
    players_(players),
    flipModeActive_(flipModeActive),
    creator_(cards_, players, ownedCards)
{
}

void Deck::createCards()
{
    if (flipModeActive_)
    {
        creator_.createNormalFlipCards();
        return;
    }

    creator_.createNormalCards();
}

void Deck::printCards()
{
    creator_.printCards();
}
