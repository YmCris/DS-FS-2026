//
// Created by cristian on 17/02/26.
//

#include "../../../include/card_game/application/card_creator/CardCreator.h"

#include <iostream>

#include "../../../include/card_game/core/enums/cards/CardsLimit.h"

CardCreator::CardCreator(int players) :
    players_(players)
{
}

std::ostream& operator<<(std::ostream& os, CardValue value)
{
    switch (value)
    {
    case CardValue::Null: os << "Null";
        break;

    case CardValue::Zero: os << "Zero";
        break;
    case CardValue::One: os << "One";
        break;
    case CardValue::Two: os << "Two";
        break;
    case CardValue::Three: os << "Three";
        break;
    case CardValue::Four: os << "Four";
        break;
    case CardValue::Five: os << "Five";
        break;
    case CardValue::Six: os << "Six";
        break;
    case CardValue::Seven: os << "Seven";
        break;
    case CardValue::Eight: os << "Eight";
        break;
    case CardValue::Nine: os << "Nine";
        break;

    case CardValue::TheftTwo: os << "TheftTwo";
        break;
    case CardValue::TheftFour: os << "TheftFour";
        break;
    case CardValue::TheftOne: os << "TheftOne";
        break;
    case CardValue::TheftThree: os << "TheftThree";
        break;
    case CardValue::TheftSix: os << "TheftSix";
        break;

    case CardValue::SkipNext: os << "SkipNext";
        break;
    case CardValue::SkipAll: os << "SkipAll";
        break;

    case CardValue::Revers: os << "Revers";
        break;

    case CardValue::ColorWildCard: os << "ColorWildCard";
        break;
    case CardValue::EternalColor: os << "EternalColor";
        break;

    default: os << "Unknown";
    }

    return os;
}


std::ostream& operator<<(std::ostream& os, CardColor color)
{
    switch (color)
    {
    case CardColor::Null: os << "Null";
        break;
    case CardColor::Red: os << "Red";
        break;
    case CardColor::Yellow: os << "Yellow";
        break;
    case CardColor::Blue: os << "Blue";
        break;
    case CardColor::Green: os << "Green";
        break;
    case CardColor::Black: os << "Black";
        break;
    case CardColor::Pink: os << "Pink";
        break;
    case CardColor::Turquoise: os << "Turquoise";
        break;
    case CardColor::Orange: os << "Orange";
        break;
    case CardColor::Violet: os << "Violet";
        break;
    default: os << "Unknown";
    }

    return os;
}


void CardCreator::printCards()
{
    for (int i = 0; i < list_.getSize(); ++i)
    {
        CardValue value = list_.getAt(i)->value()->front().value();
        CardColor color = list_.getAt(i)->value()->front().color();
        std::cout << "Card: " << i << " " << value << " " << color << std::endl;
    }
}

// CREATORS

void CardCreator::createNormalCards()
{
    createNumbersCards();
    createReverseCards();
    createNormalTheftCards();
    createColorWildCards();
    createNormalSkipCards();
}

void CardCreator::createNormalFlipCards()
{
}

void CardCreator::createFlipCards()
{
}

// RE UTILIZABLE
void CardCreator::createNumbersCards()
{
    constexpr CardValue values[9] = {
        CardValue::One, CardValue::Two, CardValue::Three, CardValue::Four,
        CardValue::Five, CardValue::Six, CardValue::Seven, CardValue::Eight,
        CardValue::Nine
    };

    // ZERO CARDS
    for (int i = 0; i < static_cast<int>(CardsLimit::Zero); i++)
    {
        Card::CardSide front(colors[i], CardValue::Zero);
        Card* card = new Card(front);
        list_.addFirst(card);
    }

    // OTHER CARDS
    int colorAccounting = 0;
    int value = 0;

    while (value < 9)
    {
        // CREATE 8 CARDS (2 of each Color)
        for (int i = 0; i < static_cast<int>(CardsLimit::Number); i++)
        {
            Card::CardSide front(colors[colorAccounting], values[value]);
            Card* card = new Card(front);
            list_.addFirst(card);

            colorAccounting++;
            if (colorAccounting == 3) colorAccounting = 0;
        }
        value++;
    }
}

void CardCreator::createReverseCards()
{
    createColorfulCard(CardsLimit::Reverse, CardValue::Revers);
}

// NORMAL
void CardCreator::createColorWildCards()
{
    createBlackCard(CardsLimit::WildColor, CardValue::ColorWildCard);
}

void CardCreator::createNormalTheftCards()
{
    createColorfulCard(CardsLimit::TheftTwo, CardValue::TheftTwo);
    createBlackCard(CardsLimit::TheftFour, CardValue::TheftFour);
}

void CardCreator::createNormalSkipCards()
{
    createColorfulCard(CardsLimit::SkipNext, CardValue::SkipNext);
}

// NORMAL FLIP
void CardCreator::createNormalFlipTheftCards()
{
}

// FLIP
void CardCreator::createFlipTheftCards()
{
}

void CardCreator::createFlipSkipCards()
{
}

void CardCreator::createFlipWildColorCards()
{
}

void CardCreator::createColorfulCard(CardsLimit cardLimit, CardValue cardValue)
{
    int colorAccounting = 0;

    // CREATE 8 CARDS (2 of each Color)
    for (int i = 0; i < static_cast<int>(cardLimit); i++)
    {
        Card::CardSide front(colors[colorAccounting], cardValue);
        Card* card = new Card(front);
        list_.addFirst(card);

        colorAccounting++;
        if (colorAccounting == 4) colorAccounting = 0;
    }
}

void CardCreator::createBlackCard(CardsLimit cardLimit, CardValue cardValue)
{
    for (int i = 0; i < static_cast<int>(cardLimit); i++)
    {
        Card::CardSide front(CardColor::Black, cardValue);
        Card* card = new Card(front);
        list_.addFirst(card);
    }
}
