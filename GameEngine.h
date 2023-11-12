//
// Created by ahmad on 10/6/2023.
//

#ifndef PROJECT_1_GAMEENGINE_H
#define PROJECT_1_GAMEENGINE_H




#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Players/Player.h"
#include "Map/Map.h"
#include "Cards/Cards.h"




class CommandProcessing;
// Define the possible commands as an enum
enum Commands {
    CMD_START,
    CMD_LOAD_MAP,
    CMD_VALIDATE_MAP,
    CMD_ADD_PLAYER,
    CMD_GAME_START,
    CMD_ASSIGN_COUNTRIES,
    CMD_ISSUE_ORDER,
    CMD_END_ISSUE_ORDER,
    CMD_EXECUTE_ORDERS,
    CMD_END_EXEC_ORDERS,
    CMD_WIN,
    CMD_END,
    CMD_PLAY,
    CMD_EXEC_ORDER,
};

class GameEngine {


public:
    // Define the possible game states as an enum inside the GameEngine class
    enum State {
        START,
        MAP_LOADED,
        MAP_VALIDATED,
        PLAYERS_ADDED,
        ASSIGN_REINFORCEMENTS,
        GAME_STARTED,
        ISSUE_ORDERS,
        EXECUTE_ORDERS,
        WIN,
        END,

    };


    GameEngine();


    // constructor
    ~GameEngine(); // Destructor to clean up the dynamically allocated CommandProcessing
    bool isValidTransition(Commands command); // check if the transition is valid
    GameEngine::State transition(Commands command); // do state transition
    GameEngine::State getCurrentState(); // to get the current game state
    void printValidCommands(); // to print the next commands a user is allowed to enter for the transition
    bool isGameComplete(); // to check if the game is complete
    bool addPlayer(string playerName);
    void gameStart();
    void startupPhase();



    // Define a struct to represent state transitions
    struct Transition {
        Commands command;
        State nextState;
    };
    static std::map<State, std::vector<Transition>> stateTransitions; // State transition map
    State stringToState(string stateStr);

private:
    GameEngine::State currentState; // current game state
    CommandProcessing* commandProcessor;  // Member variable as a pointer to store the CommandProcessing
    vector<Player*> AddedPlayerList; // Holds the players added to keep track of how many players are added;
    Map* currentMap;


};







std::string stateToString(GameEngine::State state);
std::string commandToString(Commands command);
Commands commandToEnum(std::string command);

#endif //PROJECT_1_GAMEENGINE_H