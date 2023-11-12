// GameEngineDriver.cpp
#include "GameEngine.h"
#include "GameEngineDriver.h"
#include <iostream>
#include <string>

// function that runs the game engine
void testStartupPhase() {
    GameEngine gameEngine;
    gameEngine.startupPhase();
    gameEngine.mainGameLoop();
}


