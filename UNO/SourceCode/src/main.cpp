#include <iostream>

#include "../include/card_game/application/match/Match.h"
#include "../include/card_game/domain/deck/Deck.h"

int main()
{
    MatchConfig config(false, true, true, true, true, true);
    Match* match = new Match(config, 5);
    match->deck().createCards();
    match->deck().printCards();

    match->createPlayer("Juan");
    match->createPlayer("Pepe");
    match->createPlayer("Rodrigo");
    match->createPlayer("Roberto");
    match->setCardsToPlayers();
    std::cout << "There are: " << match->players().getSize() << " players" <<
        std::endl;
    for (int i = 0; i < match->players().getSize(); ++i)
    {
        Player& player = match->players().getAt(i)->value();
        std::cout << "Player: " << i << ":" << std::endl;
        //std::cout << "Shuffle ptr: " << player.shuffle() << std::endl;
        for (int j = 0; j < player.shuffle().cards().getSize(); ++j)
        {
            std::cout << j << std::endl;
            Card* card = player.shuffle().cards().getAt(j)->value();
            std::cout << "Card: " << card << std::endl;
        }
    }


    //Deck deck(5, true, cards);

    return 0;
}
