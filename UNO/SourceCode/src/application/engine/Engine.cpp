//
// Created by cristian on 2/23/26.
//

#include "../../../include/card_game/application/engine/Engine.h"

#include <iostream>

#include "../../../include/card_game/application/match/Match.h"
#include "../../../include/card_game/application/match/MatchConfig.h"
#include "../../core/exceptions/UserInputException.cpp"

// PUBLIC API
void Engine::startApp()
{
    while (true)
    {
        menu_.showWellcome();
        int option;
        try
        {
            option = input_.requestInteger();
        }
        catch (const UserInputException& exception)
        {
            std::cout << exception.what() << std::endl;
            input_.waitForEnter();
            continue;
        }
        switch (option)
        {
        case 1:
            startGame();
            break;
        case 2:
            std::exit(0);
        default:
            std::cout << "Invalid option, try again" << std::endl;
            input_.waitForEnter();
            break;
        }
    }
}

void Engine::startGame()
{
    utilities_.clearScreen(100);
    options_.showOptions();
    std::string option = input_.requestString();
    try
    {
        std::vector<int> options = input_.requestOptions(option);
        play(options);
    }
    catch (const UserInputException& exception)
    {
        std::cout << exception.what() << std::endl;
        input_.waitForEnter();
    }
}

void Engine::play(std::vector<int> options)
{
    //1. Set the match config
    const MatchConfig config(
        input_.integerToBoolean(options[1]),
        input_.integerToBoolean(options[2]),
        input_.integerToBoolean(options[3]),
        input_.integerToBoolean(options[4]),
        input_.integerToBoolean(options[5]),
        input_.integerToBoolean(options[6])
    );

    // 2. Create the match
    Match match(config, options[0]);

    // 3. Create the cards and add to deck
    match.deck().createCards();

    // 4. Create players and add to the circular list
    createPlayers(options[0], match);

    // 5. Add cards to every player's shuffle
    match.setCardsToPlayers();

    // 6. Define the initial player
    int playerInTurn = utilities_.getRandomInteger(
        0, match.players().getSize() - 1);

    // 7. Set initial rotation
    bool rightRotation = utilities_.rightRotation();

    // 8. Set initial Card
    match.discardDeck().push(match.deck().pop());

    // 9. Set the game over condition
    int lastPlayer = playerInTurn;
    bool gameOver = false;
    bool flip = false;
    while (!gameOver)
    {
        // a) Set the next player (based in the rotation)
        int next = utilities_.getNext(rightRotation, playerInTurn,
                                      match.players().getSize());

        // b) Show the players turn
        game_.showTurn(match.players().getAt(playerInTurn)->value().name());

        // c) Show the game with the info


        // d) catch the user option
        playerOption(match, playerInTurn, rightRotation, flip, gameOver, next,
                     options[1]);
        lastPlayer = playerInTurn;
        // e) Set the new player in turn
        playerInTurn = next;
    }
    std::cout << "Ganador: " << match.players().getAt(lastPlayer)->value().
                                      name() << std::endl;
}

void Engine::playerOption(Match& match, int playerInTurn, bool& rightRotation,
                          bool& flip, bool& gameOver, int& next, int option)
{
    Player& player = match.players().getAt(playerInTurn)->value();
    bool success = false;
    do
    {
        game_.showGameScreen(
            match.players().getAt(playerInTurn)->value().name(),
            match.players().getAt(next)->value().name(),
            getCurrentCardValue(match, flip),
            getCurrentCardColor(match, flip),
            std::to_string(option), std::to_string(match.deck().size()),
            std::to_string(match.discardDeck().size())
        );

        switch (input_.requestInteger())
        {
        case 1: // Put card
            {
                view_.showRoof();
                // a) is flip mode active?
                if (flip)
                {
                    // b) Use flip cards
                    useUserFLipCards(player, match, success);
                    setCardsFunction(match, playerInTurn, next,
                                     *match.discardDeck().peek(), flip,
                                     rightRotation);
                    if (accumulation_ > 0)
                    {
                        Player& nextPlayer = match.players().getAt(next)->
                                                   value();

                        for (int i = 0; i < accumulation_; ++i)
                        {
                            nextPlayer.shuffle().addCard(match.deck().pop());
                        }

                        accumulation_ = 0;
                        success = true;
                        return;
                    }
                }
                else
                {
                    // b) Use normal cards (Normal and normal flip)
                    useUserNormalCards(player, match, success);
                    setCardsFunction(match, playerInTurn, next,
                                     *match.discardDeck().peek(), flip,
                                     rightRotation);
                    if (accumulation_ > 0)
                    {
                        Player& nextPlayer = match.players().getAt(next)->
                                                   value();

                        for (int i = 0; i < accumulation_; ++i)
                        {
                            nextPlayer.shuffle().addCard(match.deck().pop());
                        }

                        accumulation_ = 0;
                        success = true;
                        return;
                    }
                }

                // d) player has cards?
                if (player.shuffle().cards().getSize() == 0) gameOver = true;

                break;
            }
        case 2:
            {
                if (match.config().challenge())
                {
                    if (accumulation_ == 4)
                    {
                        int prev = utilities_.getPrevious(
                            rightRotation, playerInTurn,
                            match.players().getSize());
                        std::cout << "Reto" << std::endl;

                        if (playerHadMoreCards(
                            match.players().getAt(prev)->value(),
                            *match.discardDeck().peek(), flip))
                        {
                            std::cout << "The user had another card, theft +4";
                            match.players().getAt(prev)->value().shuffle().
                                  addCard(
                                      match.deck().pop());
                            match.players().getAt(prev)->value().shuffle().
                                  addCard(
                                      match.deck().pop());
                            match.players().getAt(prev)->value().shuffle().
                                  addCard(
                                      match.deck().pop());
                            match.players().getAt(prev)->value().shuffle().
                                  addCard(
                                      match.deck().pop());
                        }
                        else
                        {
                            std::cout <<
                                "The usern't had another card, you theft +6";
                            match.players().getAt(playerInTurn)->value().
                                  shuffle().
                                  addCard(
                                      match.deck().pop());
                            match.players().getAt(playerInTurn)->value().
                                  shuffle().
                                  addCard(
                                      match.deck().pop());
                            match.players().getAt(playerInTurn)->value().
                                  shuffle().
                                  addCard(
                                      match.deck().pop());
                            match.players().getAt(playerInTurn)->value().
                                  shuffle().
                                  addCard(
                                      match.deck().pop());
                            match.players().getAt(playerInTurn)->value().
                                  shuffle().
                                  addCard(
                                      match.deck().pop());
                            match.players().getAt(playerInTurn)->value().
                                  shuffle().
                                  addCard(
                                      match.deck().pop());
                        }
                    }
                    else
                    {
                        std::cout <<
                            "No puedes retar, no te han tirado ningun +4"
                            << std::endl;
                    }
                }
                else
                {
                    std::cout << "No puedes retar, no habilitaste la opción"
                        << std::endl;
                }

                break;
            } // RETAR
        case 3:
            {
                if (player.shuffle().cards().getSize() == 1)
                {
                    std::cout << "Has anunciado que tienes una carta " <<
                        std::endl;
                    player.setSayUno(true);
                    break;
                }
                std::cout <<
                    "Tienes que tener únicamente una carta para decir uno" <<
                    std::endl;
                break;
            } // UNO
        case 4:
            {
                std::cout << "¿A quién quieres reportar?" << std::endl;
                int option = input_.requestInteger();
                if (match.players().getAt(option)->value().shuffle().cards().
                          getSize() == 1 && !match.players().getAt(option)->
                                                   value().sayUno())
                {
                    std::cout <<
                        "Que observador, si tenía solo una carta y no dijo uno"
                        <<
                        std::endl;
                    match.players().getAt(option)->value().shuffle().addCard(
                        match.deck().pop());
                    match.players().getAt(option)->value().shuffle().addCard(
                        match.deck().pop());
                }
                else
                {
                    std::cout << "Reportaste erroneamente" << std::endl;
                    std::cout << "Robas 2" << std::endl;
                    match.players().getAt(playerInTurn)->value().shuffle().
                          addCard(
                              match.deck().pop());
                    match.players().getAt(playerInTurn)->value().shuffle().
                          addCard(
                              match.deck().pop());
                }


                break;
            } // REPORT
        case 5:
            {
                if (match.config().multiSteal())
                {
                    player.shuffle().addCard(match.deck().pop());
                    std::cout << "Se ha añadido una carta a tu bajara" <<
                        std::endl;
                }
                else
                {
                    player.shuffle().addCard(match.deck().pop());
                    std::cout << "Se ha añadido una carta a tu bajara" <<
                        std::endl;
                    success = true;
                }

                break;
            } // JALAR
        case 6:
            {
                std::exit(0);
            }
        default:
            {
                std::cout << "Invalid option" << std::endl;
                success = false;
                break;
            }
        }
        input_.waitForEnter();
    }
    while (!success);
}

void Engine::useUserFLipCards(Player& player, Match& match, bool& succes)
{
    player.shuffle().printBack();
    view_.showFloor();

    const int selectedCard = input_.requestInteger();

    Card::CardSide currentSide = match.discardDeck().peek()->back().value();
    Card::CardSide selectedSide = player.shuffle().cards().getAt(selectedCard)->
                                         value()->back().value();

    if (cardsAreCompatible(currentSide, selectedSide))
    {
        if (selectedSide.color() == CardColor::Black)
        {
            useUserBlackCard(selectedSide, true);
        }
        match.discardDeck().push(
            player.shuffle().useCard(
                selectedCard));
        std::cout << "Are compatible" << std::endl;
        succes = true;
        return;
    }
    succes = false;
    std::cout << " NO Are compatible" << std::endl;
}

void Engine::useUserNormalCards(Player& player, Match& match, bool& success)
{
    player.shuffle().printFront();
    view_.showFloor();

    const int selectedCard = input_.requestInteger();

    Card::CardSide currentSide = match.discardDeck().peek()->front();
    Card::CardSide selectedSide = player.shuffle().cards().getAt(selectedCard)->
                                         value()->front();

    if (cardsAreCompatible(currentSide, selectedSide))
    {
        if (selectedSide.color() == CardColor::Black)
        {
            useUserBlackCard(selectedSide, false);
        }
        match.discardDeck().push(
            player.shuffle().useCard(
                selectedCard));
        std::cout << "Are compatible" << std::endl;
        success = true;
        return;
    }
    success = false;
    std::cout << " Are not compatible" << std::endl;
}

void Engine::useUserBlackCard(Card::CardSide selectedSide, bool flip)
{
    if (selectedSide.value() == CardValue::TheftOne) accumulation_ = 1;
    if (selectedSide.value() == CardValue::TheftTwo) accumulation_ = 2;
    if (selectedSide.value() == CardValue::TheftThree) accumulation_ = 3;
    if (selectedSide.value() == CardValue::TheftFour) accumulation_ = 4;
    if (selectedSide.value() == CardValue::TheftSix) accumulation_ = 6;
    requestNewColor(flip);
}

bool Engine::cardsAreCompatible(Card::CardSide currentSide,
                                Card::CardSide selectedSide)
{
    return currentSide.value() == selectedSide.value()
        || currentSide.color() == selectedSide.color()
        || selectedSide.color() == CardColor::Black;
}


void Engine::requestNewColor(bool flip)
{
    std::cout << "Ingresa el nuevo color:" << std::endl;
    if (!flip)
    {
        std::cout << "Colores disponibles:  [Red] [Yellow] [Blue] [Green]" <<
            std::endl;
    }
    else
    {
        std::cout <<
            "Colores disponibles:  [Pink] [Turquoise] [Orange] [Violet]" <<
            std::endl;
    }
    std::string newColor = input_.requestString();
    color_ = utilities_.stringToColor(newColor);
}

std::string Engine::getCurrentCardColor(Match& match, bool flip)
{
    if (flip)
    {
        return utilities_.colorToString(
            match.discardDeck().peek()->back()->color());
    }
    return utilities_.colorToString(
        match.discardDeck().peek()->front().color());
}

std::string Engine::getCurrentCardValue(Match& match, bool flip)
{
    if (flip)
    {
        return utilities_.valueToString(
            match.discardDeck().peek()->back()->value());
    }
    return utilities_.
        valueToString(match.discardDeck().peek()->front().value());
}

void Engine::createPlayers(int players, Match& match)
{
    utilities_.clearScreen(100);
    for (int i = 0; i < players; ++i)
    {
        std::cout << "Ingresa el nombre del jugador " << (i + 1) << ":" <<
            std::endl;
        std::string name = input_.requestString();
        match.createPlayer(name);
    }
}

bool Engine::playerHadMoreCards(Player& player, Card& card, bool flip)
{
    for (int i = 0; i < player.shuffle().cards().getSize(); ++i)
    {
        if (!flip)
        {
            if (player.shuffle().cards().getAt(i)->value()->front().value() ==
                card.front().value() || player.
                                        shuffle().cards().getAt(i)->value()->
                                        front().color() == card.front().color())
            {
                return true;
            }
        }
        else
        {
            if (player.shuffle().cards().getAt(i)->value()->back().value().
                       value() == card.back()->value() || player.shuffle().
                cards().
                getAt(i)->value()->back()->color() == card.back()->color())
            {
                return true;
            }
        }
    }
    return false;
}


void Engine::setCardsFunction(Match& match, int playerInTurn, int& newNext,
                              Card& card,
                              bool& flip, bool& rightRotation)
{
    if (!flip)
    {
        switch (card.front().value())
        {
        case CardValue::SkipNext:
            {
                int next = utilities_.getNext(rightRotation, playerInTurn,
                                              match.players().getSize());
                newNext = utilities_.getNext(rightRotation, next,
                                             match.players().getSize());
                break;
            }
        case CardValue::Revers:
            {
                rightRotation = !rightRotation;
                break;
            }
        case CardValue::Flip:
            {
                flip = !flip;
                break;
            }
        }
    }
    else
    {
        switch (card.back().value().value())
        {
        case CardValue::SkipAll:
            {
                newNext = playerInTurn;
                break;
            }
        case CardValue::EternalColor:
            {
                // Joder, no lo sé
                break;
            }
        case CardValue::Revers:
            {
                rightRotation = !rightRotation;
                break;
            }
        case CardValue::Flip:
            {
                flip = !flip;
                break;
            }
        }
    }
}
