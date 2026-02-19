//
// Created by cristian on 2/18/26.
//

#ifndef SOURCECODE_THEFTCARD_H
#define SOURCECODE_THEFTCARD_H
#include "Card.h"


/**
* The TheftCard class header is the class responsible for 
* 
* @author YmCris
* @since 2/18/26
*/
class TheftCard final : public Card
{
    // LIFETIME
    TheftCard(CardColor color, CardValue value, bool flip);

    ~TheftCard() override = default;

    // PUBLIC API
    CardValue play() const override;
    bool isPlayable(const Card& card) const override;
    void flip() override;
};


#endif //SOURCECODE_THEFTCARD_H