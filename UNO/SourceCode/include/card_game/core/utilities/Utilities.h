//
// Created by cristian on 2/24/26.
//

#ifndef SOURCECODE_UTILITIES_H
#define SOURCECODE_UTILITIES_H
#include <string>

#include "../../domain/card/Card.h"


/**
* The Utilities class header is the class responsible for 
* 
* @author YmCris
* @since 2/24/26
*/
class Utilities
{
public:
    // PUBLIC API
    /**
     * Contains the limits
     * @param lowerLimit
     * @param upperLimit
     * @return
     */
    int getRandomInteger(int lowerLimit, int upperLimit);
    void clearScreen(int lines);
    bool rightRotation();
    int getNext(bool rightRotation, int current, int listSize);
    std::string colorToString(CardColor color);
    std::string valueToString(CardValue value);
};


#endif //SOURCECODE_UTILITIES_H
