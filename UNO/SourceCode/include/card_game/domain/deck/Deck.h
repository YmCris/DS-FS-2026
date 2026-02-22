//
// Created by cristian on 2/17/26.
//

#ifndef SOURCECODE_DECK_H
#define SOURCECODE_DECK_H

#include "../../core/data_structures/stack/Stack.h"
#include "../card/Card.h"
#include "../../application/card_creator/CardCreator.h"

/**
* The Deck class header is the class responsible for be the deck (main or the discard)
* 
* @author YmCris
* @since 2/17/26
*/
class Deck final : public Stack<Card*>
{
public:
    // LIFETIME
    Deck(int players, bool flipModeActive, LinkedList<Card*>& list);
    void createDeck();
    void printCards();

private:
    // DATA MEMBERS
    int players_;
    bool flipModeActive_;
    CardCreator creator_;
};

#endif //SOURCECODE_DECK_H
