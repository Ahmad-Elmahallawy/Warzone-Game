//
// Created by ahmad on 10/6/2023.
//

#ifndef PROJECT_1_GAMEENGINE_H
#define PROJECT_1_GAMEENGINE_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

// Define the possible game states as an enum
enum State {
    START,
    MAP_LOADED,
    MAP_VALIDATED,
    PLAYERS_ADDED,
    ASSIGN_REINFORCEMENTS,
    ISSUE_ORDERS,
    EXECUTE_ORDERS,
    WIN,
    END
};

// Define the possible commands as an enum
enum Commands {
    CMD_START,
    CMD_LOAD_MAP,
    CMD_VALIDATE_MAP,
    CMD_ADD_PLAYER,
    CMD_ASSIGN_COUNTRIES,
    CMD_ISSUE_ORDER,
    CMD_END_ISSUE_ORDER,
    CMD_EXECUTE_ORDERS,
    CMD_END_EXEC_ORDERS,
    CMD_WIN,
    CMD_END,
    CMD_PLAY,
    CMD_EXEC_ORDER
};

// Define a struct to represent state transitions
struct Transition {
    Commands command;
    State nextState;
};

class GameEngine {
private:
    State currentState; // current game state
    std::map<State, std::vector<Transition>> stateTransitions; // State transition map

public:
    GameEngine(); // constructor
    bool isValidTransition(Commands command); // check if the transition is valid
    void transition(Commands command); // do state transition
    State getCurrentState(); // to get the current game state
    void printValidCommands(); // to print the next commands a user is allowed to enter for the transition
    bool isGameComplete(); // to check if the game is complete
};

std::string stateToString(State state);
std::string commandToString(Commands command);

#endif //PROJECT_1_GAMEENGINE_H
