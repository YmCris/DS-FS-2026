//
// Created by cristian on 2/18/26.
//

#ifndef SOURCECODE_SKIPCARD_H
#define SOURCECODE_SKIPCARD_H
#include "Card.h"


/**
* The SkipCard class header is the class responsible for 
* 
* @author YmCris
* @since 2/18/26
*/
class SkipCard final : public Card
{
    // LIFETIME
    SkipCard(CardColor color, CardValue value, bool flip);

    ~SkipCard() override = default;

    // PUBLIC API
    CardValue play() const override;
    bool isPlayable(const Card& card) const override;
    void flip() override;
};


#endif //SOURCECODE_SKIPCARD_H