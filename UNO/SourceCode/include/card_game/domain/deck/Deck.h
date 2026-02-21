//
// Created by cristian on 2/17/26.
//

#ifndef SOURCECODE_DECK_H
#define SOURCECODE_DECK_H

#include "../../core/data_structures/stack/Stack.h"
#include "../../core/enums/cards/CardsLimit.h"
#include "../card/Card.h"

/**
* The Deck class header is the class responsible for be the deck (main or the discard)
* 
* @author YmCris
* @since 2/17/26
*/
class Deck
{
public:
    // LIFETIME
    Deck(bool flipModeActive, int players);

    // PUBLIC API
    LinkedList<Card> createCards(int players);
    LinkedList<Card> shuffle(LinkedList<Card> cards);
    Stack<Card> stackCards(LinkedList<Card> cards);
    LinkedList<Card> createNormalCards(const int players);
    LinkedList<Card> createFlipCards(const int players);
    void add(Card card);
    Card remove();

private:
    // DATA MEMBERS
    Stack<Card> cards_;
    CardsLimit limit_;
    bool shuffled_ = false;
    int size = 0;
    bool flipModeActive_ = false;
    int players_ = 0;
};


#endif //SOURCECODE_DECK_H
