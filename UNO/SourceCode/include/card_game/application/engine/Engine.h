//
// Created by cristian on 2/23/26.
//

#ifndef SOURCECODE_ENGINE_H
#define SOURCECODE_ENGINE_H
#include "../../core/data_input/DataInput.h"
#include "../../core/utilities/Utilities.h"
#include "../../infrastructure/cards/CardsView.h"
#include "../../infrastructure/game/Game.h"
#include "../../infrastructure/menu/Menu.h"
#include "../../infrastructure/options/Options.h"
#include "../match/Match.h"


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
    void playerOption(Match& match, int playerInTurn, bool& rightRotation,
                      bool flip, bool& gameOver);
    void createPlayers(int players, Match& match);
    bool playerHadMoreCards(Player& player, Card& card, bool flip);
    void useUserFLipCards(Player& player, Match& match);
    void useUserNormalCards(Player& player, Match& match);
    bool cardsAreCompatible(Card::CardSide currentSide,
                            Card::CardSide selectedSide);
    void useUserBlackCard(Card::CardSide selectedSide, bool flip);
    void requestNewColor(bool flip);
    std::string getCurrentCardColor(Match& match, bool flip);
    std::string getCurrentCardValue(Match& match, bool flip);

private:
    // DATA MEMBERS
    int accumulation_ = 0;
    std::optional<CardColor> color_ = std::nullopt;

    /* FRONTEND */
    Game game_;
    Menu menu_;
    Options options_;
    CardsView view_;

    /* VALIDATION */
    DataInput input_;

    /* UTILITIES */
    Utilities utilities_;
};


#endif //SOURCECODE_ENGINE_H
