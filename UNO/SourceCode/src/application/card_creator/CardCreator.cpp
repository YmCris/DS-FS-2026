//
// Created by cristian on 17/02/26.
//

#include "../../../include/card_game/application/card_creator/CardCreator.h"

#include <iostream>

#include "../../../include/card_game/core/enums/cards/CardsLimit.h"


std::ostream& operator<<(std::ostream& os, CardValue value)
{
    switch (value)
    {
    case CardValue::Null: os << "Null";
        break;

    case CardValue::Zero: os << "Zero";
        break;
    case CardValue::TheftColor: os << "TheftColor";
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
    case CardValue::Flip: os << "Flip";
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

CardCreator::CardCreator(LinkedList<Card*>& originalList, int players,
                         std::vector<Card*>& ownedCards) :
    players_(players),
    list_(originalList),
    ownedCards_(ownedCards)
{
}

void CardCreator::printCards()
{
    for (int i = 0; i < list_.getSize(); ++i)
    {
        Card* card = list_.getAt(i)->value();
        CardValue value = card->front().value();
        CardColor color = card->front().color();
        std::cout << "-> Card: " << i << " " << value << " " << color <<
            std::endl;
        if (auto back = card->back())
        {
            CardValue backValue = back->value();
            CardColor backColor = back->color();
            std::cout << "<- Card: " << i << " " << backValue << " " <<
                backColor
                << std::endl;
        }
    }
}

// CREATORS
LinkedList<Card*>& CardCreator::createNormalCards()
{
    int decks = (players_ - 1) / 6 + 1;
    for (int i = 0; i < decks; ++i)
    {
        createNumbersCards(normalColors_);
        createReverseCards(normalColors_, false);
        createNormalSkipCards(normalColors_);
        createNormalTheftCards();
        createColorWildCards();
    }
    list_.disorder();
    return list_;
}

LinkedList<Card*>& CardCreator::createNormalFlipCards()
{
    int decks = (players_ - 1) / 6 + 1;
    for (int i = 0; i < decks; ++i)
    {
        createFlipChangeCards(false);
        createNumbersCards(normalColors_);
        createReverseCards(normalColors_, true);
        createNormalSkipCards(normalColors_);
        createNormalFlipTheftCards();
        createColorWildCards();
    }
    list_.disorder();
    createFlipCards();
    addFlipCards();
    return list_;
}

void CardCreator::createFlipCards()
{
    //1. Create flip cards

    createFlipChangeCards(true); //8

    createFlipTheftCards(); // 8 + 4
    createFlipSkipCards(); //8
    createReverseCards(flipColors_, true); //8
    createFlipWildColorCards(); //4
    createNumbersFlipSides(flipColors_); //4+8(9)

    //2. Save the flip cards into a list "flip"
    //3. Save in a different position
}

void CardCreator::addFlipCards()
{
    flipSides_.disorder();
    std::cout << "Size of list_: " << list_.getSize() << std::endl;
    std::cout << "Size of flipSides_: " << flipSides_.getSize() << std::endl;

    for (int i = 0; i < list_.getSize(); ++i)
    {
        list_.getAt(i)->value()->setBack(flipSides_.getAt(i)->value());
    }
}

// RE UTILIZABLE
void CardCreator::createNumbersCards(CardColor color[])
{
    constexpr CardValue values[9] = {
        CardValue::One, CardValue::Two, CardValue::Three, CardValue::Four,
        CardValue::Five, CardValue::Six, CardValue::Seven, CardValue::Eight,
        CardValue::Nine
    };

    // ZERO CARDS
    for (int i = 0; i < static_cast<int>(CardsLimit::Zero); i++)
    {
        Card::CardSide front(color[i], CardValue::Zero);
        Card* card = new Card(front);
        ownedCards_.push_back(card);
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
            Card::CardSide front(color[colorAccounting], values[value]);
            Card* card = new Card(front);
            ownedCards_.push_back(card);
            list_.addFirst(card);

            colorAccounting++;
            if (colorAccounting == 3) colorAccounting = 0;
        }
        value++;
    }
}

void CardCreator::createNumbersFlipSides(CardColor color[])
{
    constexpr CardValue values[9] = {
        CardValue::One, CardValue::Two, CardValue::Three, CardValue::Four,
        CardValue::Five, CardValue::Six, CardValue::Seven, CardValue::Eight,
        CardValue::Nine
    };

    // ZERO CARDS
    for (int i = 0; i < static_cast<int>(CardsLimit::Zero); i++)
    {
        Card::CardSide front(color[i], CardValue::Zero);
        flipSides_.addFirst(front);
    }

    // OTHER CARDS
    int colorAccounting = 0;
    int value = 0;

    while (value < 9)
    {
        // CREATE 8 CARDS (2 of each Color)
        for (int i = 0; i < static_cast<int>(CardsLimit::Number); i++)
        {
            Card::CardSide front(color[colorAccounting], values[value]);
            flipSides_.addFirst(front);

            colorAccounting++;
            if (colorAccounting == 3) colorAccounting = 0;
        }
        value++;
    }
}

void CardCreator::createReverseCards(CardColor color[], bool flip)
{
    if (flip)
    {
        createColorfulSides(color, CardsLimit::Reverse,
                            CardValue::Revers);
    }
    else
    {
        createColorfulCard(color, CardsLimit::Reverse,
                           CardValue::Revers);
    }
}

// NORMAL
void CardCreator::createColorWildCards()
{
    createBlackCard(CardsLimit::WildColor, CardValue::ColorWildCard);
}

void CardCreator::createNormalTheftCards()
{
    createColorfulCard(normalColors_, CardsLimit::TheftTwo,
                       CardValue::TheftTwo);
    createBlackCard(CardsLimit::TheftFour, CardValue::TheftFour);
}

void CardCreator::createNormalSkipCards(CardColor color[])
{
    createColorfulCard(color, CardsLimit::SkipNext, CardValue::SkipNext);
}

// NORMAL FLIP
void CardCreator::createNormalFlipTheftCards()
{
    createBlackCard(CardsLimit::TheftOne, CardValue::TheftOne);
    createBlackCard(CardsLimit::TheftTwo, CardValue::TheftTwo);
}

void CardCreator::createFlipChangeCards(bool flip)
{
    if (flip)
    {
        createBlackSides(CardsLimit::Flip, CardValue::Flip);
    }
    else
    {
        createBlackCard(CardsLimit::Flip, CardValue::Flip);
    }
}

// FLIP
void CardCreator::createFlipTheftCards()
{
    createBlackSides(CardsLimit::TheftThree, CardValue::TheftThree);
    createBlackSides(CardsLimit::TheftSix, CardValue::TheftSix);
}

void CardCreator::createFlipSkipCards()
{
    createBlackSides(CardsLimit::SkipAll, CardValue::SkipAll);
}

void CardCreator::createFlipWildColorCards()
{
    createBlackSides(CardsLimit::TheftColor, CardValue::TheftColor);
}

// AUXILIAR NORMAL
void CardCreator::createColorfulCard(CardColor colors[], CardsLimit cardLimit,
                                     CardValue cardValue)
{
    int colorAccounting = 0;

    // CREATE 8 CARDS (2 of each Color)
    for (int i = 0; i < static_cast<int>(cardLimit); i++)
    {
        Card::CardSide front(colors[colorAccounting], cardValue);
        Card* card = new Card(front);
        ownedCards_.push_back(card);
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
        ownedCards_.push_back(card);
        list_.addFirst(card);
    }
}

// AUXILIAR FLIP
void CardCreator::createColorfulSides(CardColor colors[], CardsLimit cardLimit,
                                      CardValue cardValue)
{
    int colorAccounting = 0;

    // CREATE 8 CARDS (2 of each Color)
    for (int i = 0; i < static_cast<int>(cardLimit); i++)
    {
        Card::CardSide front(colors[colorAccounting], cardValue);
        flipSides_.addFirst(front);

        colorAccounting++;
        if (colorAccounting == 4) colorAccounting = 0;
    }
}

void CardCreator::createBlackSides(CardsLimit cardLimit, CardValue cardValue)
{
    for (int i = 0; i < static_cast<int>(cardLimit); i++)
    {
        Card::CardSide front(CardColor::Black, cardValue);
        flipSides_.addFirst(front);
    }
}
