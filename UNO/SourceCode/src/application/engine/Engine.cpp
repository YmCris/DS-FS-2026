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
        game_.showGameScreen(
            match.players().getAt(playerInTurn)->value().name(),
            match.players().getAt(next)->value().name(),
            getCurrentCardValue(match, flip),
            getCurrentCardColor(match, flip),
            std::to_string(options[1]), std::to_string(match.deck().size()),
            std::to_string(match.discardDeck().size())
        );

        // d) catch the user option
        playerOption(match, playerInTurn, rightRotation, flip, gameOver);
        lastPlayer = playerInTurn;
        // e) Set the new player in turn
        playerInTurn = next;
    }
    std::cout << "Ganador: " << match.players().getAt(lastPlayer)->value().
                                      name() << std::endl;
}

void Engine::playerOption(Match& match, int playerInTurn, bool& rightRotation,
                          bool flip, bool& gameOver)
{
    Player& player = match.players().getAt(playerInTurn)->value();
    switch (input_.requestInteger())
    {
    case 1: // Put card
        {
            view_.showRoof();
            // a) is flip mode active?
            if (flip)
            {
                // b) Use flip cards
                useUserFLipCards(player, match);
            }
            else
            {
                // b) Use normal cards (Normal and normal flip)
                useUserNormalCards(player, match);
            }

            // d) player has cards?
            if (player.shuffle().cards().getSize() == 0) gameOver = true;

            break;
        }
    case 2:
        {
            rightRotation = !rightRotation;
            break;
        }
    case 3:
        {
            std::cout << std::endl;
            break;
        }
    case 4:
        {
            break;
        }
    case 5:
        {
            std::exit(0);
        }
    default:
        {
            std::cout << "Invalid option" << std::endl;
            break;
        }
    }
}

void Engine::useUserFLipCards(Player& player, Match& match)
{
    player.shuffle().printBack();
    view_.showFloor();

    const int selectedCard = input_.requestInteger();

    if (cardsAreCompatible(match.discardDeck().peek()->back().value(),
                           player.shuffle().cards().getAt(selectedCard)->value()
                                 ->back().value()))
    {
        match.discardDeck().push(
            player.shuffle().useCard(
                selectedCard));
        std::cout << "Are compatible" << std::endl;
        return;
    }

    std::cout << " NO Are compatible" << std::endl;
}

void Engine::useUserNormalCards(Player& player, Match& match)
{
    player.shuffle().printFront();
    view_.showFloor();

    const int selectedCard = input_.requestInteger();

    if (cardsAreCompatible(match.discardDeck().peek()->front(),
                           player.shuffle().cards().getAt(selectedCard)->value()
                                 ->front()))
    {
        match.discardDeck().push(
            player.shuffle().useCard(
                selectedCard));
        std::cout << "Are compatible" << std::endl;
        return;
    }
    std::cout << " NO Are compatible" << std::endl;
}

bool Engine::cardsAreCompatible(Card::CardSide currentSide,
                                Card::CardSide selectedSide)
{
    return currentSide.value() == selectedSide.value()
        || currentSide.color() == selectedSide.color();
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
