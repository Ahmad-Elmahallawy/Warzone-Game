// GameEngineDriver.cpp
#include "GameEngine.h"
#include "GameEngineDriver.h"
#include <iostream>
#include <string>

// function that runs the game engine
int main() {
    GameEngine gameEngine;
    gameEngine.startupPhase();
    gameEngine.mainGameLoop();

    return 0;
}


