//
// Created by cristian on 2/23/26.
//

#ifndef SOURCECODE_GAME_H
#define SOURCECODE_GAME_H
#include <string>

#include "../../core/data_input/DataInput.h"
#include "../../core/utilities/Utilities.h"


/**
* The Game class header is the class responsible for 
* 
* @author YmCris
* @since 2/23/26
*/
class Game
{
public:
    // PUBLIC API
    void showTurn(const std::string name);
    void showGameScreen(const std::string& playerTurn, const std::string& next,
                        const std::string& cardValue,
                        const std::string& cardColor,
                        const std::string& mode, const std::string& cardsInDeck,
                        const std::string& cardsInDiscard);

private:
    Utilities utilities_;
    DataInput input_;
};


#endif //SOURCECODE_GAME_H
