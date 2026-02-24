//
// Created by cristian on 2/22/26.
//

#include "../../../include/card_game/application/match/Match.h"

#include <iostream>

// LIFETIME
Match::Match(MatchConfig config, int players) :
    config_(config),
    deck_(players, config.flip(), ownedCards_),
    discardDeck_(discardCards_)
{
}

// PUBLIC API
void Match::play()
{
    // Put the initial card in discard deck
}

void Match::putCard(Player player)
{
}

void Match::createPlayer(std::string name)
{
    Player player(name);
    players_.addFirst(player);
}

void Match::setCardsToPlayers()
{
    for (int i = 0; i < players_.getSize(); ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            players_.getAt(i)->value().shuffle().addCard(deck_.pop());
        }
    }
}

Card* Match::seeTurnCard()
{
    return discardDeck_.peek();
}

CircularDoubleLinkedList<Player>& Match::players()
{
    return players_;
}

Deck& Match::deck()
{
    return deck_;
}

Stack<Card*>& Match::discardDeck()
{
    return discardDeck_;
}
