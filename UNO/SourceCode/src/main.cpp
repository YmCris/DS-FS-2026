#include <iostream>
#include <ostream>

#include "../include/card_game/domain/deck/Deck.h"

int main()
{
    LinkedList<Card*> cards;

    Deck deck(5, true, cards);
    deck.printCards();
    deck.peek();
    Card* card = deck.pop();
    deck.printCards();

    return 0;
}
