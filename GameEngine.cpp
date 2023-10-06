// GameEngine.cpp
#include "GameEngine.h"

GameEngine::GameEngine() {
    // current state when the game runs
    currentState = START;

    // Initialize the state transition map
    stateTransitions[START] = {{CMD_START, MAP_LOADED}};
    stateTransitions[MAP_LOADED] = {{CMD_LOAD_MAP, MAP_LOADED}, {CMD_VALIDATE_MAP, MAP_VALIDATED}};
    stateTransitions[MAP_VALIDATED] = {{CMD_ADD_PLAYER, PLAYERS_ADDED}};
    stateTransitions[PLAYERS_ADDED] = {{CMD_ADD_PLAYER, PLAYERS_ADDED}, {CMD_ASSIGN_COUNTRIES, ASSIGN_REINFORCEMENTS}};
    stateTransitions[ASSIGN_REINFORCEMENTS] = {{CMD_ISSUE_ORDER, ISSUE_ORDERS}};
    stateTransitions[ISSUE_ORDERS] = {{CMD_ISSUE_ORDER, ISSUE_ORDERS}, {CMD_END_ISSUE_ORDER, EXECUTE_ORDERS}};
    stateTransitions[EXECUTE_ORDERS] = {{CMD_EXEC_ORDER, EXECUTE_ORDERS}, {CMD_END_EXEC_ORDERS, ASSIGN_REINFORCEMENTS}, {CMD_WIN, WIN}};
    stateTransitions[WIN] = {{CMD_PLAY, START}, {CMD_END, END}};
}

// function definition to check if the command is valid to transition to the next state
bool GameEngine::isValidTransition(Command command) {
    for (const auto &transition : stateTransitions[currentState]) {
        if (transition.command == command) {
            return true;
        }
    }
    return false;
}


// transition to the next state if the command is valid
void GameEngine::transition(Command command) {
    if (isValidTransition(command)) {
        for (const auto &transition : stateTransitions[currentState]) {
            if (transition.command == command) {
                currentState = transition.nextState;
                break;
            }
        }
    } else {
        std::cout << "Invalid state transition." << std::endl;
    }
}

// returns the current state of the game
State GameEngine::getCurrentState() {
    return currentState;
}

// display the valid commands user can enter
void GameEngine::printValidCommands() {
    std::cout << "Valid commands for state " << stateToString(currentState) << ":" << std::endl;
    for (const auto &transition : stateTransitions[currentState]) {
        std::cout << commandToString(transition.command) << std::endl;
    }
}

// returns true if the state is equal to end
bool GameEngine::isGameComplete() {
    return currentState == END;
}

// converts state enum value to string
std::string stateToString(State state) {
    switch (state) {
        case START: return "start";
        case MAP_LOADED: return "map loaded";
        case MAP_VALIDATED: return "map validated";
        case PLAYERS_ADDED: return "players added";
        case ASSIGN_REINFORCEMENTS: return "assign reinforcement";
        case ISSUE_ORDERS: return "issue orders";
        case EXECUTE_ORDERS: return "execute orders";
        case WIN: return "win";
        case END: return "end";
        default: return "UNKNOWN_STATE";
    }
}

// converts command to string
std::string commandToString(Command command) {
    switch (command) {
        case CMD_START: return "start";
        case CMD_LOAD_MAP: return "loadmap";
        case CMD_VALIDATE_MAP: return "validatemap";
        case CMD_ADD_PLAYER: return "addplayer";
        case CMD_ASSIGN_COUNTRIES: return "assigncountries";
        case CMD_ISSUE_ORDER: return "issueorder";
        case CMD_END_ISSUE_ORDER: return "endissueorder";
        case CMD_EXECUTE_ORDERS: return "executeorders";
        case CMD_END_EXEC_ORDERS: return "endexecorders";
        case CMD_WIN: return "win";
        case CMD_END: return "end";
        case CMD_PLAY: return "play";
        case CMD_EXEC_ORDER: return "execorder";
        default: return "UNKNOWN_COMMAND";
    }
}
