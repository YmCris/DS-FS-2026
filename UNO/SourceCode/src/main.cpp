#include <iostream>

#include "../include/card_game/application/card_creator/CardCreator.h"
#include "../include/card_game/core/data_structures/linked_list/LinkedList.h"

int main()
{
    CardCreator* creator = new CardCreator(3);
    creator->createNormalCards();
    creator->printCards();
    return 0;
}
