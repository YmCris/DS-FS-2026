//
// Created by cristian on 2/18/26.
//

#ifndef SOURCECODE_NUMBERCARD_H
#define SOURCECODE_NUMBERCARD_H
#include "Card.h"


/**
* The NumberCard class header is the class responsible for 
* 
* @author YmCris
* @since 2/18/26
*/
class NumberCard final : public Card
{
public:
    // LIFETIME
    NumberCard(CardColor color, CardValue value, bool flip);

    ~NumberCard() override = default;

    // PUBLIC API
    CardValue play() const override;
    bool isPlayable(const Card& card) const override;
    void flip() override;
};


#endif //SOURCECODE_NUMBERCARD_H
