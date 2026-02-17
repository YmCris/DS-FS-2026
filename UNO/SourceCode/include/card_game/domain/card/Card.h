//
// Created by cristian on 2/14/26.
//

#ifndef SOURCECODE_CARD_H
#define SOURCECODE_CARD_H

#include "../../core/enums/cards/CardColor.h"
#include  "../../core/enums/cards/CardValue.h"

/**
* The Card class header is the class responsible for represent a card
* 
* @author YmCris
* @since 2/14/26
*/
class Card
{
    // LIFETIME
public:
    Card(CardColor color, CardValue value);

public:
    virtual ~Card() = default;

    // PUBLIC API
    [[nodiscard]] CardColor color() const;
    [[nodiscard]] CardValue value() const;
    //virtual void setAbstract() = 0;

private:
    // DATA MEMBERS
    CardColor color_;
    CardValue value_;
};

#endif //SOURCECODE_CARD_H
