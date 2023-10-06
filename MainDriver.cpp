#include "Map/Map.h"
#include "Players/Player.h"
#include "Orders/Orders.h"
#include "Cards/Cards.h"
#include "GameEngineDriver.h"

// the main function of the program
// This project executes all the test*() functions for Assignment 1
int main() {
    // Part 1
    testLoadMaps();

    // Part 2
    testPlayers();

    // Part 3
    testOrdersLists();

    // Part 4
    testCards();

    // Part 5
    testGameStates();

    return 0;
}