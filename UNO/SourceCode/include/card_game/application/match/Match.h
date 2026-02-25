//
// Created by cristian on 2/22/26.
//

#ifndef SOURCECODE_MATCH_H
#define SOURCECODE_MATCH_H
#include "MatchConfig.h"
#include "../../core/data_structures/circular_list/CircularList.h"
#include "../../domain/deck/Deck.h"
#include "../../domain/player/Player.h"


/**
* The Match class header is the class responsible for 
* 
* @author YmCris
* @since 2/22/26
*/
class Match
{
public:
    // LIFETIME
    Match(MatchConfig config, int players);

    ~Match()
    {
        for (Card* card : ownedCards_)
            delete card;
    }

    // PUBLIC API
    void play();
    void putCard(Player player);
    void createPlayer(std::string name);
    void setCardsToPlayers();
    Card* seeTurnCard();
    CircularDoubleLinkedList<Player>& players();

    Deck& deck();
    Stack<Card*>& discardDeck();
    MatchConfig& config();

private:
    // HELPERS

    // DATA MEMBERS
    MatchConfig config_;
    std::vector<Card*> ownedCards_; // Save all
    LinkedList<Card*> discardCards_;
    // Save the cards to use in the discard deck

    Deck deck_;
    Stack<Card*> discardDeck_;
    CircularDoubleLinkedList<Player> players_;
    int theftAccumulation_ = 0;
};


#endif //SOURCECODE_MATCH_H
