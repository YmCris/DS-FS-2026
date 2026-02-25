//
// Created by cristian on 2/21/26.
//

#ifndef SOURCECODE_SHUFFLE_H
#define SOURCECODE_SHUFFLE_H

#include "../../core/data_structures/double_linked_list/DoubleLinkedList.h"
#include "../../domain/card/Card.h"


/**
* The Shuffle class header is the class responsible for 
* 
* @author YmCris
* @since 2/21/26
*/
class Shuffle
{
public:
    // LIFETIME
    Shuffle();

    // PUBLIC API
    void organize();
    void addCard(Card* card);
    Card* useCard(int position);
    [[nodiscard]] const DoubleLinkedList<Card*>& cards() const;
    void printFront();
    void printBack();

private:
    // DATA MEMBERS
    DoubleLinkedList<Card*> cards_;
};


#endif //SOURCECODE_SHUFFLE_H
