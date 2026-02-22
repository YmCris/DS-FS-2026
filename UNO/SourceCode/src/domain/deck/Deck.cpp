//
// Created by cristian on 2/17/26.
//

#include "../../../include/card_game/domain/deck/Deck.h"

// PUBLIC API
Deck::Deck(int players, bool flipModeActive, LinkedList<Card*>& list) :
    Stack<Card*>(list),
    players_(players),
    flipModeActive_(flipModeActive),
    creator_(list, players)
{
    createDeck();
}

void Deck::createDeck()
{
    if (flipModeActive_)
    {
        creator_.createNormalFlipCards();
    }
    else
    {
        creator_.createNormalCards();
    }
}

void Deck::printCards()
{
    creator_.printCards();
}
