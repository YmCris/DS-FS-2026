//
// Created by cristian on 2/17/26.
//

#include "../../../include/card_game/domain/deck/Deck.h"

// PUBLIC API
Deck::Deck(const bool flipModeActive, const int players)
    : flipModeActive_(flipModeActive),
      players_(players)
{
}

LinkedList<Card> Deck::createCards(int players)
{
    if (flipModeActive_)
    {
        return createFlipCards(players);
    }

    return createNormalCards(players);
}

LinkedList<Card> Deck::createNormalCards(int player)
{
    LinkedList<Card> normalCards;

}

LinkedList<Card> Deck::createFlipCards(int player)
{

}

LinkedList<Card> Deck::shuffle(LinkedList<Card> cards)
{
}

Stack<Card> Deck::stackCards(LinkedList<Card> cards)
{
}

// DATA MEMBERS
void Deck::add(Card card)
{
}

Card Deck::remove()
{
}
