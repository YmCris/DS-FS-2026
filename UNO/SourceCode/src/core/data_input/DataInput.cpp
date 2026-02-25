//
// Created by cristian on 2/23/26.
//

#include "../../../include/card_game/core/data_input/DataInput.h"

#include <iostream>
#include <sstream>

#include "../exceptions/UserInputException.cpp"


// PUBLIC API
int DataInput::requestInteger()
{
    int number;

    if (!(std::cin >> number))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw UserInputException("The data entered isn't a number");
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return number;
}

std::string DataInput::requestString()
{
    std::string text;

    if (!std::getline(std::cin, text))
    {
        throw UserInputException("Input error");
    }

    if (text.find_first_not_of(" \t\n\r") == std::string::npos)
    {
        throw UserInputException(
            "The text can't be empty or only white spaces");
    }

    return text;
}

bool DataInput::integerToBoolean(int integer)
{
    return integer == 1;
}

void DataInput::waitForEnter()
{
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string dummy;
    std::getline(std::cin, dummy);
}

std::vector<int> DataInput::requestOptions(std::string input)
{
    std::vector<int> numbers;
    std::stringstream stringStream(input);
    std::string parameter;
    int index = 0;

    while (std::getline(stringStream, parameter, ','))
    {
        if (parameter.empty())
            throw UserInputException("Empty value detected between commas");

        int number;
        try
        {
            number = std::stoi(parameter);
        }
        catch (...)
        {
            throw UserInputException("No numeric value detected: " + parameter);
        }

        if (index == 0)
        {
            if (number <= 2)
                throw UserInputException("First number must be greater than 2");
        }
        else
        {
            if (number != 1 && number != 2)
            {
                throw UserInputException(
                    "All numbers except the first must be 1 or 2");
            }
        }

        numbers.push_back(number);
        ++index;
    }

    if (numbers.empty())
        throw UserInputException("No numbers found in input");

    if (numbers.size() != 7)
        throw UserInputException("You have to ingress 7 parameters");

    return numbers;
}
