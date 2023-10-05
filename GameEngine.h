/*
All the classes/functions that you
implement for this component must all reside in a single .cpp/.h file duo named
GameEngine.cpp/GameEngine.h. You must deliver a file named GameEngineDriver.cpp file that contains a free
function named testGameStates() that allows the user to type command strings on the console, whose result is
to trigger some state transitions as depicted in the state transition diagram presented below. Any command string
entered that does not correspond to an outgoing edge of the current state should be rejected.

*/
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <functional>

#include "Map/Map.h"
#include "Orders/Orders.h"
#include "Cards/Cards.h"
#include "Orders/Orders.h"
#include "Players/Player.h"



enum GameState
{
    // Start states
    START,
    MAP_LOADED,
    MAP_VALIDATED,
    PLAYERS_ADDED,
    // Play states
    ASSIGN_REINFORCEMENTS,
    ISSUE_ORDERS,
    EXECUTE_ORDERS,
    WIN,
    END
};

/**
 * A command consists of:
 * 1. The command string taken from user input
 * 2. The function call from the command
 * 3. resulting state after command
*/
class Command
{
public:
    std::string *cmdName;
    void (*action)();
    GameState *nextState;

    //Constructor
    Command(std::string *cmdName,  void (*action)(), GameState *nextState);
    Command(const Command &command);
};

class GameEngine
{
private:
    std::map<GameState, std::list<Command>> stateTransitions;

public:
    GameState *currentState;
    // Constructors
    GameEngine(GameState *currentState, std::map<GameState, std::list<Command>> *stateTransitions);
    GameEngine(const GameEngine &gameEngine);

    void executeCommand(std::string command);


};