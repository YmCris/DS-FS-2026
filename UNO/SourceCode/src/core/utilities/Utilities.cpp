//
// Created by cristian on 2/24/26.
//

#include "../../../include/card_game/core/utilities/Utilities.h"

#include <iostream>
#include <random>

// PUBLIC API

int Utilities::getRandomInteger(int lowerLimit, int upperLimit)
{
    std::random_device random;
    std::mt19937 generator(random());

    std::uniform_int_distribution<int> dist(lowerLimit, upperLimit);

    return dist(generator);
}

void Utilities::clearScreen(int lines = 100)
{
    std::cout << std::string(lines, '\n') << std::flush;
}

bool Utilities::rightRotation()
{
    return getRandomInteger(0, 1);
}

int Utilities::getNext(bool rightRotation, int current, int listSize)
{
    if (rightRotation)
    {
        if (current == listSize - 1)
        {
            return 0;
        }
        return ++current;
    }
    // Left Rotation
    if (current == 0)
    {
        return listSize - 1;
    }
    return --current;
}

int Utilities::getPrevious(bool rightRotation, int current, int listSize)
{
    int previousIndex;

    if (rightRotation)
    {
        if (current == 0)
        {
            previousIndex = listSize - 1;
        }
        else
        {
            previousIndex = current - 1;
        }
    }
    else
    {
        if (current == listSize - 1)
        {
            previousIndex = 0;
        }
        else
        {
            previousIndex = current + 1;
        }
    }

    return previousIndex;
}

std::optional<CardColor> Utilities::stringToColor(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    if (str == "red") return CardColor::Red;
    if (str == "yellow") return CardColor::Yellow;
    if (str == "blue") return CardColor::Blue;
    if (str == "green") return CardColor::Green;
    if (str == "black") return CardColor::Black;
    if (str == "pink") return CardColor::Pink;
    if (str == "turquoise") return CardColor::Turquoise;
    if (str == "orange") return CardColor::Orange;
    if (str == "violet") return CardColor::Violet;

    return std::nullopt;
}

std::string Utilities::colorToString(CardColor color)
{
    switch (color)
    {
    case CardColor::Null: return "Null";
    // Normal
    case CardColor::Red: return "Red";
    case CardColor::Yellow: return "Yellow";
    case CardColor::Blue: return "Blue";
    case CardColor::Green: return "Green";
    case CardColor::Black: return "Black";
    // Flikp
    case CardColor::Pink: return "Pink";
    case CardColor::Turquoise: return "Turquoise";
    case CardColor::Orange: return "Orange";
    case CardColor::Violet: return "Violet";
    default: return "Unknown Color";
    }
}

std::string Utilities::valueToString(CardValue value)
{
    switch (value)
    {
    case CardValue::Null: return "Null";
    // Numbers
    case CardValue::Zero: return "0";
    case CardValue::One: return "1";
    case CardValue::Two: return "2";
    case CardValue::Three: return "3";
    case CardValue::Four: return "4";
    case CardValue::Five: return "5";
    case CardValue::Six: return "6";
    case CardValue::Seven: return "7";
    case CardValue::Eight: return "8";
    case CardValue::Nine: return "9";
    // Theft
    case CardValue::TheftOne: return "Draw 1";
    case CardValue::TheftTwo: return "Draw 2";
    case CardValue::TheftThree: return "Draw 3";
    case CardValue::TheftFour: return "Draw 4";
    case CardValue::TheftSix: return "Draw 6";
    case CardValue::TheftColor: return "Draw Until Color";
    // Skip
    case CardValue::SkipNext: return "Skip Next";
    case CardValue::SkipAll: return "Skip Everyone";
    // Reverse
    case CardValue::Revers: return "Reverse";
    // WildCard
    case CardValue::ColorWildCard: return "Wild Card";
    case CardValue::EternalColor: return "Eternal Wild Card";
    case CardValue::Flip: return "FLIP!";
    default: return "Unknown Value";
    }
}
