//
// Created by cristian on 2/23/26.
//

#include "../../../include/card_game/application/engine/Engine.h"

#include <iostream>

#include "../../../include/card_game/application/match/Match.h"
#include "../../../include/card_game/application/match/MatchConfig.h"
#include "../../core/exceptions/UserInputException.cpp"

// LIFETIME


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
            break;
        default:
            std::cout << "Option not allowed" << std::endl;
            input_.waitForEnter();
            break;
        }
    }
}

void Engine::startGame()
{
    options_.showOptions();
    std::string option = input_.requestString();
    std::vector<int> options;
    try
    {
        options = input_.requestOptions(option);
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
    MatchConfig config(
        input_.integerToBoolean(options[1]),
        input_.integerToBoolean(options[2]),
        input_.integerToBoolean(options[3]),
        input_.integerToBoolean(options[4]),
        input_.integerToBoolean(options[5]),
        input_.integerToBoolean(options[6])
    );

    Match match(config, options[0]);
    match.deck().createCards();
    match.deck().printCards();

    //
    for (int i = 0; i < options[0]; ++i)
    {
        std::cout << "Ingresa el nombre del jugador "<< (i + 1) << ":" << std::endl;
        std::string name = input_.requestString();
        match.createPlayer(name);
    }
    match.setCardsToPlayers();
}
