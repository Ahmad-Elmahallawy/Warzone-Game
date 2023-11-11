//
// Created by ahmad on 10/6/2023.
//

#ifndef PROJECT_1_GAMEENGINE_H
#define PROJECT_1_GAMEENGINE_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Cards/Cards.h"
#include "Players/Player.h"

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

// Define a struct to represent state transitions
struct Transition {
    Command command;
    State nextState;
};

class GameEngine {
private:
    State currentState; // current game state
    std::map<State, std::vector<Transition>> stateTransitions; // State transition map
    int numPlayers;
    vector<Player *> players;
    Deck *deck;

public:

    GameEngine(); // constructor
    bool isValidTransition(Command command); // check if the transition is valid
    void transition(Command command); // do state transition
    State getCurrentState(); // to get the current game state
    void printValidCommands(); // to print the next commands a user is allowed to enter for the transition
    bool isGameComplete(); // to check if the game is complete

    void setRound(bool round);
    Player* getPlayerByID(int id);
    bool getRound();
    Deck* getDeck();

    //main game loop
    void mainGameLoop();
    void reinforcementPhase();
    void issuingOrdersPhase();
    void ordersExecutionPhase();

};

std::string stateToString(State state);
std::string commandToString(Command command);

#endif //PROJECT_1_GAMEENGINE_H
