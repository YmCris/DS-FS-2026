//
// Created by cristian on 2/18/26.
//

#ifndef SOURCECODE_COLORWILDCARD_H
#define SOURCECODE_COLORWILDCARD_H
#include "Card.h"


/**
* The ColorWildCard class header is the class responsible for 
* 
* @author YmCris
* @since 2/18/26
*/
class ColorWildCard final : public Card
{
public:
    // LIFETIME
    ColorWildCard(CardColor color, CardValue value, bool flip);

    ~ColorWildCard() override = default;

    // PUBLIC API
    CardValue play() const override;
    bool isPlayable(const Card& card) const override;
    void flip() override;
};


#endif //SOURCECODE_COLORWILDCARD_H