//
// Created by cristian on 2/22/26.
//

#ifndef SOURCECODE_PLAYER_H
#define SOURCECODE_PLAYER_H
#include <string>

#include "../../application/shuffle/Shuffle.h"


/**
* The Player class header is the class responsible for 
* 
* @author YmCris
* @since 2/22/26
*/
class Player
{
public:
    // LIFETIME
    explicit Player(const std::string& name);

    // PUBLIC API
    [[nodiscard]] bool blocked() const;
    [[nodiscard]] bool hadCards() const;

    void setSayUno(bool say);
    bool sayUno();

    Shuffle& shuffle();
    std::string name();

private:
    // DATA MEMBERS
    bool blocked_;
    bool hasCards_;
    bool sayUno_ = false;

    Shuffle shuffle_;
    std::string name_;
};


#endif //SOURCECODE_PLAYER_H
