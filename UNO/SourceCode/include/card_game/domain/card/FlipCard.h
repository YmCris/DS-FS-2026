//
// Created by cristian on 2/18/26.
//

#ifndef SOURCECODE_FLIPCARD_H
#define SOURCECODE_FLIPCARD_H
#include "Card.h"


/**
* The FlipCard class header is the class responsible for 
* 
* @author YmCris
* @since 2/18/26
*/
class FlipCard final : public Card
{
public:
    // LIFETIME
    FlipCard(CardColor color, CardValue value, bool flip);

    ~FlipCard() override = default;

    // PUBLIC API
    CardValue play() const override;
    bool isPlayable(const Card& card) const override;
    void flip() override;
};


#endif //SOURCECODE_FLIPCARD_H
