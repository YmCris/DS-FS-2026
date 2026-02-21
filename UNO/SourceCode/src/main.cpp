#include <iostream>
#include <ostream>

#include "../include/card_game/application/card_creator/CardCreator.h"

int main()
{
    CardCreator* creator = new CardCreator(5);
    std::cout << "Normal cards" << std::endl;
    creator->createNormalFlipCards();
    //creator->createNormalCards();
    creator->printCards(creator->list());

    return 0;
}
