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

        [[nodiscard]] CardColor color() const;
        [[nodiscard]] CardValue value() const;

    private:
        CardColor color_;
        CardValue value_;
    };

    // LIFETIME
    Card(CardSide front, std::optional<CardSide> back = std::nullopt);

    ~Card() = default;

    Card(const Card&) = delete;
    Card& operator=(const Card&) = delete;

    Card(Card&&) noexcept = default;
    Card& operator=(Card&&) noexcept = default;

    // PUBLIC API
    [[nodiscard]] CardSide front() const;
    [[nodiscard]] std::optional<CardSide> back() const;

    // SETTERS
    void setBack(CardSide back);

private:
    // DATA MEMBERS
    CardSide front_;
    std::optional<CardSide> back_;
};

#endif //SOURCECODE_CARD_H
