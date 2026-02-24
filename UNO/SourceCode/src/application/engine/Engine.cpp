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
            break;
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
    MatchConfig config(
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
    utilities_.clearScreen(100);
    for (int i = 0; i < options[0]; ++i)
    {
        std::cout << "Ingresa el nombre del jugador " << (i + 1) << ":" <<
            std::endl;
        std::string name = input_.requestString();
        match.createPlayer(name);
    }
    // 5. Add cards to every player's shuffle
    match.setCardsToPlayers();

    // 6. Define the initial player and the rotation
    int playerInTurn = utilities_.getRandomInteger(
        0, match.players().getSize() - 1);
    bool rightRotation = utilities_.rightRotation();

    // 7.
    match.discardDeck().push(match.deck().pop());
    Card* card = match.seeTurnCard();

    // 8. Set the game over condition
    int next;
    bool gameOver = false;
    while (!gameOver)
    {
        game_.showTurn(
            match.players().getAt(playerInTurn)->value().name());

        if (rightRotation)
        {
            playerInTurn++;
            next = playerInTurn++;
        }
        else
        {
            playerInTurn--;
            next = playerInTurn--;
        }

        game_.showGameScreen(
            match.players().getAt(playerInTurn)->value().name()
            , match.players().getAt(next)->value().name(),
            utilities_.valueToString(card->front().value()),
            utilities_.colorToString(card->front().color()),
            "flip"
        );
        int option = input_.requestInteger();
        switch (option)
        {
        case 1:
            {
                match.players().getAt(playerInTurn)->value().shuffle().printFront();
            }
        case 2:
            {
            }
        case 3:
            {
            }
        case 4:
            {
            }
        default:
            {
            }
        }
    }
}

void Engine::playerOption(int option)
{
    switch (option)
    {
    case 1:
        {
        }
    case 2:
        {
        }
    case 3:
        {
        }
    case 4:
        {
        }
    default:
        {
        }
    }
}
