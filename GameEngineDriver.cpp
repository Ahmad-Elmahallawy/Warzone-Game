// GameEngineDriver.cpp
#include "GameEngine.h"
#include "GameEngineDriver.h"
#include <iostream>
#include <string>

// function that runs the game engine
void testGameStates() {
    GameEngine gameEngine;
    //main game loop
    gameEngine.mainGameLoop();



    // keep looping as long as the state is not end
    while (!gameEngine.isGameComplete()) {
        std::cout << "Current state: " << stateToString(gameEngine.getCurrentState()) << std::endl;
        gameEngine.printValidCommands();

        // to take user input
        std::string userInput;
        std::cout << "Enter a command: ";
        std::cin >> userInput;

        // converts command string to command enum value
        Command command;
        if (userInput == "start") {
            command = CMD_START;
        } else if (userInput == "loadmap") {
            command = CMD_LOAD_MAP;
        } else if (userInput == "validatemap") {
            command = CMD_VALIDATE_MAP;
        } else if (userInput == "addplayer") {
            command = CMD_ADD_PLAYER;
        } else if (userInput == "assigncountries") {
            command = CMD_ASSIGN_COUNTRIES;
        } else if (userInput == "issueorder") {
            command = CMD_ISSUE_ORDER;
        } else if (userInput == "endissueorder") {
            command = CMD_END_ISSUE_ORDER;
        } else if (userInput == "executeorders") {
            command = CMD_EXECUTE_ORDERS;
        } else if (userInput == "endexecorders") {
            command = CMD_END_EXEC_ORDERS;
        } else if (userInput == "win") {
            command = CMD_WIN;
        } else if (userInput == "end") {
            command = CMD_END;
        } else if (userInput == "play") {
            command = CMD_PLAY;
        } else if (userInput == "execorder") {
            command = CMD_EXEC_ORDER;
        } else {
            std::cout << "Invalid command. Try again." << std::endl;
            continue;
        }

        // state transition based on the command
        gameEngine.transition(command);
    }

    std::cout << "Game has ended." << std::endl;
}


