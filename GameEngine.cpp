// GameEngine.cpp
#include "GameEngine.h"



// Definition and initialization of the static member
std::map<State, std::vector<Transition>> GameEngine::stateTransitions = {
        {State::START, {
                               {CMD_START, State::MAP_LOADED}
                       }},
        {State::MAP_LOADED, {
                               {CMD_LOAD_MAP, State::MAP_LOADED},
                               {CMD_VALIDATE_MAP, State::MAP_VALIDATED}
                       }},
        {State::MAP_VALIDATED, {
                               {CMD_ADD_PLAYER, State::PLAYERS_ADDED}
                       }},
        {State::PLAYERS_ADDED, {
                               {CMD_ADD_PLAYER, State::PLAYERS_ADDED},
                               {CMD_ASSIGN_COUNTRIES, State::ASSIGN_REINFORCEMENTS}
                       }},
        {State::ASSIGN_REINFORCEMENTS, {
                               {CMD_ISSUE_ORDER, State::ISSUE_ORDERS}
                       }},
        {State::ISSUE_ORDERS, {
                               {CMD_ISSUE_ORDER, State::ISSUE_ORDERS},
                               {CMD_END_ISSUE_ORDER, State::EXECUTE_ORDERS}
                       }},
        {State::EXECUTE_ORDERS, {
                               {CMD_EXEC_ORDER, State::EXECUTE_ORDERS},
                               {CMD_END_EXEC_ORDERS, State::ASSIGN_REINFORCEMENTS},
                               {CMD_WIN, State::WIN}
                       }},
        {State::WIN, {
                               {CMD_PLAY, State::START},
                               {CMD_END, State::END}
                       }},
};






GameEngine::GameEngine() {
    // current state when the game runs
    currentState = START;
}

// function definition to check if the command is valid to transition to the next state
bool GameEngine::isValidTransition(Commands command) {
    for (const auto &transition : stateTransitions[currentState]) {
        if (transition.command == command) {
            return true;
        }
    }
    return false;
}


// transition to the next state if the command is valid
void GameEngine::transition(Commands command) {
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
std::string commandToString(Commands command) {
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
