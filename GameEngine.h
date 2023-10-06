//
// Created by ahmad on 10/6/2023.
//

#ifndef PROJECT_1_GAMEENGINE_H
#define PROJECT_1_GAMEENGINE_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

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

enum Command {
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

struct Transition {
    Command command;
    State nextState;
};

class GameEngine {
private:
    State currentState;
    std::map<State, std::vector<Transition>> stateTransitions;

public:
    GameEngine();
    bool isValidTransition(Command command);
    void transition(Command command);
    State getCurrentState();
    void printValidCommands();
    bool isGameComplete();
};

std::string stateToString(State state);
std::string commandToString(Command command);

#endif //PROJECT_1_GAMEENGINE_H
