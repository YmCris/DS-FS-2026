//
// Created by cristian on 2/17/26.
//

#ifndef SOURCECODE_CARDSLIMIT_H
#define SOURCECODE_CARDSLIMIT_H


/**
* The CardsLimit class header is the class responsible for 
* 
* @author YmCris
* @since 2/17/26
*/
enum class CardsLimit
{
    // NUMBERS
    Zero = 4,
    One = 8,
    Two = 8,
    Three = 8,
    Four = 8,
    Five = 8,
    Six = 8,
    Seven = 8,
    Eight = 8,
    Nive = 8,

    // SKIP
    Skip = 8,
    SkipAll = 8,

    // REVERSE
    Reverse = 8,

    // WILDS
    PlusOne = 8,
    PlusTwo = 8,
    PlusFour = 4,
    PlusColor = 4,
    WildColor = 4,

    Flip = 8,
};


#endif //SOURCECODE_CARDSLIMIT_H
