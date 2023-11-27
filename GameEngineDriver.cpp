// GameEngineDriver.cpp
#include "GameEngine.h"
#include "GameEngineDriver.h"
#include <iostream>
#include <string>

// function that runs the game engine
void testStartupPhase() {
    GameEngine gameEngine;
    GameEngine gameEngine2;
    GameEngine gameEngine3;
    GameEngine gameEngine4;
    GameEngine gameEngine5;
    std::vector<GameEngine> gameEngines;
    gameEngines.push_back(gameEngine);
    gameEngines.push_back(gameEngine2);
    gameEngines.push_back(gameEngine3);
    gameEngines.push_back(gameEngine4);
    gameEngines.push_back(gameEngine5);
    for(int i = 0;i<gameEngines.size();i++){
        gameEngines[i].startupPhase();
        gameEngines[i].mainGameLoop();
    }
}





