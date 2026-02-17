//
// Created by cristian on 2/17/26.
//

#include "../../../include/card_game/domain/deck/Deck.h"

#include <bits/ranges_algo.h>

// PUBLIC API
Deck::Deck(const bool flipModeActive, const int players)
    : flipModeActive_(flipModeActive),
      players_(players)
{
}

LinkedList<Card> Deck::createCards(int players)
{
    for (int i = 0; i < static_cast<int>(CardsLimit::Zero); i++)
    {
        Card* card = new Card(CardColor::Green, CardValue::Eight);
    }
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
