#include <iostream>
#include "Map/Map.h"
#include "GameEngine.h"
#include "Players/Player.h"

int main() {
    std::cout << "Hello hello! test" << std::endl;
    testLoadMaps();
//    testPlayer();
    return 0;
}

//command constructor
Command::Command(std::string *cmdName, void (*action)(), GameState *nextState):
        cmdName(cmdName),
        action(action),
        nextState(nextState) {}

        

Command::Command(const Command &command) :
        cmdName(command.cmdName),
        action(command.action),
        nextState(command.nextState) {}

