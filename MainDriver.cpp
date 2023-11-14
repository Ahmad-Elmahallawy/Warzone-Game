#include "Map/Map.h"
#include "Players/Player.h"
#include "Orders/Orders.h"
#include "Cards/Cards.h"
#include "GameEngineDriver.h"
#include "Command/CommandProcessing.h"
#include <iostream>
// the main function of the program
// This project executes all the test*() functions for Assignment 1
int main() {
//
//    cout << "===========================" << endl;
//    cout << "           Part 1          " << endl;
//    cout << "===========================" << endl;
    testCommandProcessor();
//    cout << "End of Part 1" << endl;
    cout << "===========================" << endl;
    cout << "           Part 2 and 3         " << endl;
    cout << "===========================" << endl;
    testStartupPhase();
//    cout << "End of Part 2 and 3" << endl;
//    cout << "===========================" << endl;
//    cout << "           Part 4         " << endl;
//    cout << "===========================" << endl;
//    testOrderExecution();
//    cout << "End of Part 2 and 3" << endl;
//    cout << "===========================" << endl;
//    cout << "           Part 5         " << endl;
//    cout << "===========================" << endl;
//    testLoggingObserver();


}