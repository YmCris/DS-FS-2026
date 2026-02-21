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
    Number = 8,
    One = 8,
    Two = 8,
    Three = 8,
    Four = 8,
    Five = 8,
    Six = 8,
    Seven = 8,
    Eight = 8,
    Nine = 8,

    // SKIP
    SkipNext = 8,
    SkipAll = 4,

    // REVERSE
    Reverse = 8,

    // WILDS
    TheftOne = 12,
    TheftTwo = 8,
    TheftThree = 4,
    TheftFour = 4,
    TheftSix = 4,
    TheftColor = 4,
    // WILD CARD
    WildColor = 4,

    Flip = 8,
};


#endif //SOURCECODE_CARDSLIMIT_H
