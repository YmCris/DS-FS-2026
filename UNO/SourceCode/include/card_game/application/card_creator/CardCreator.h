//
// Created by cristian on 17/02/26.
//

#ifndef SOURCECODE_CARDCREATOR_H
#define SOURCECODE_CARDCREATOR_H
#include "../../core/data_structures/linked_list/LinkedList.h"
#include "../../core/enums/cards/CardsLimit.h"
#include "../../domain/card/Card.h"


class CardCreator
{
public:
    CardCreator(int players);
    // CREATORS

    void printCards();
    void createNormalCards();
    void createNormalFlipCards();
    void createFlipCards();

private:
    // RE UTILIZABLE
    void createNumbersCards();
    void createReverseCards();
    // NORMAL
    void createColorWildCards();
    void createNormalTheftCards();
    void createNormalSkipCards();
    // NORMAL FLIP
    void createNormalFlipTheftCards();
    // FLIP
    void createFlipTheftCards();
    void createFlipSkipCards();
    void createFlipWildColorCards();
    // AUXILIAR
    void createColorfulCard(CardsLimit cardLimit, CardValue cardValue);
    void createBlackCard(CardsLimit cardLimit, CardValue cardValue);

    LinkedList<Card*> list_;
    int players_ = 0;
    CardColor colors[4] = {
        CardColor::Red, CardColor::Yellow, CardColor::Blue, CardColor::Green
    };
};


#endif //SOURCECODE_CARDCREATOR_H
