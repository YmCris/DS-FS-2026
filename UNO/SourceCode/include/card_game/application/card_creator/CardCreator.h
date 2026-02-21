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
    CardCreator(LinkedList<Card*>& originalList, int players);

    // CREATORS
    void printCards(LinkedList<Card*>& list);
    void createNormalCards();
    void createNormalFlipCards();


    LinkedList<Card*>& list();
    LinkedList<Card*>& flip();

private:
    // RE UTILIZABLE
    void createNumbersCards(LinkedList<Card*>& list, CardColor color[]);
    void createReverseCards(LinkedList<Card*>& list, CardColor color[]);
    // NORMAL
    void createColorWildCards();
    void createNormalTheftCards();
    void createNormalSkipCards(CardColor color[]);
    // NORMAL FLIP
    void createNormalFlipTheftCards();
    void createFlipChangeCards(LinkedList<Card*>& list);
    // FLIP
    void createFlipTheftCards();
    void createFlipSkipCards();
    void createFlipWildColorCards();

    void createFlipCards();
    void addFlipCards();

    // AUXILIAR
    void createColorfulCard(LinkedList<Card*>& list,
                            CardColor colors[], CardsLimit cardLimit,
                            CardValue cardValue);
    void createBlackCard(LinkedList<Card*>& list, CardsLimit cardLimit,
                         CardValue cardValue);

    // DATA
    int players_ = 0;

    LinkedList<Card*> list_;
    LinkedList<Card*> flip_;

    CardColor normalColors_[4] = {
        CardColor::Red, CardColor::Yellow, CardColor::Blue, CardColor::Green
    };

    CardColor flipColors_[4] = {
        CardColor::Pink, CardColor::Turquoise, CardColor::Orange,
        CardColor::Violet
    };
};


#endif //SOURCECODE_CARDCREATOR_H
