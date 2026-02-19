//
// Created by cristian on 2/18/26.
//

#ifndef SOURCECODE_REVERSECARD_H
#define SOURCECODE_REVERSECARD_H
#include "Card.h"


/**
* The ReverseCard class header is the class responsible for 
* 
* @author YmCris
* @since 2/18/26
*/
class ReverseCard final : public Card
{
    // LIFETIME
    ReverseCard(CardColor color, CardValue value, bool flip);

    ~ReverseCard() override = default;

    // PUBLIC API
    CardValue play() const override;
    bool isPlayable(const Card& card) const override;
    void flip() override;
};


#endif //SOURCECODE_REVERSECARD_H