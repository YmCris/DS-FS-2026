//
// Created by cristian on 2/14/26.
//

#ifndef SOURCECODE_CARD_H
#define SOURCECODE_CARD_H

#include <optional>

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
public:
    // STRUCTURES
    struct CardSide
    {
        CardSide(CardColor color, CardValue value);

        CardColor color() const;
        CardValue value() const;

    private:
        CardColor color_;
        CardValue value_;
    };

    // LIFETIME
    Card(bool flip, CardSide front, std::optional<CardSide> back = std::nullopt
    );

    virtual ~Card() = default;

    Card(const Card&) = delete;
    Card& operator=(const Card&) = delete;

    Card(Card&&) noexcept = default;
    Card& operator=(Card&&) noexcept = default;

    // PUBLIC API
    virtual CardValue play() = 0;
    virtual bool isPlayable(const Card& card) const =0;

    [[nodiscard]] bool isFlip() const;
    CardSide front() const;
    std::optional<CardSide> back() const;

private:
    // DATA MEMBERS
    CardSide front_;
    std::optional<CardSide> back_;
    bool flip_ = false;
};

#endif //SOURCECODE_CARD_H
