//
//
//
#include "GameEngine.h"
#include "mainGameLoopDriver.h"
/*demonstrates that (1) a player
receives the correct number of army units in the reinforcement phase (showing different cases); (2) a player will
only issue deploy orders and no other kind of orders if they still have army units in their reinforcement pool; (3) a
player can issue advance orders to either defend or attack, based on the toAttack() and toDefend() lists; (4) a
player can play cards to issue orders; (5) a player that does not control any territory is removed from the game;
(6) the game ends when a single player controls all the territories.

 */

void testMainGameLoop(){

    GameEngine engine;
    engine.mainGameLoop();
    

}

