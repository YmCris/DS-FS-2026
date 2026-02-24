//
// Created by cristian on 2/23/26.
//

#ifndef SOURCECODE_ENGINE_H
#define SOURCECODE_ENGINE_H
#include "../../core/data_input/DataInput.h"
#include "../../infrastructure/game/Game.h"
#include "../../infrastructure/menu/Menu.h"
#include "../../infrastructure/options/Options.h"


/**
* The Engine class header is the class responsible for 
* 
* @author YmCris
* @since 2/23/26
*/
class Engine
{
public:
    // LIFETIME

    // PUBLIC API
    void startApp();
    void startGame();
    void play(std::vector<int> options);

private:
    // DATA MEMBERS
    /* FRONTEND */
    Game game_;
    Menu menu_;
    Options options_;

    /* VALIDATION */
    DataInput input_;
};


#endif //SOURCECODE_ENGINE_H
