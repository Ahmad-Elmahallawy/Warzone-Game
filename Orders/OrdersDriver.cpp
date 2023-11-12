
/*
contains a free function named testOrdersLists() that creates a list of orders and demonstrates that the OrdersList implemented
Here : remove, move of the orderlist will be tested, expected result shown commented
*/
#include "../Map/Map.h"
#include "../Orders/Orders.h"
#include "../Players/Player.h"
#include "../Cards/Cards.h"
#include <iostream>

void testOrderExecution() {
    // Setup phase
    Map gameMap(5); // Assuming a map with 5 territories
    Player player1, player2, neutralPlayer;
    Territory territory1, territory2, territory3;

    // Initialize territories and players
    // Note: Adjust these setups as per your game's initialization logic
    territory1.setName("Territory1");
    territory2.setName("Territory2");
    territory3.setName("Territory3");

    gameMap.addEdge(territory1, territory2);
    gameMap.addEdge(territory2, territory3);

    player1.addTerriorty(&territory1);
    player2.addTerriorty(&territory2);
    neutralPlayer.addTerriorty(&territory3);
// Assuming territory1 and territory2 are instances of Territory
    territory1.addAdjacentTerritory(&territory2);
    territory2.addAdjacentTerritory(&territory1);

// Now, territory1 and territory2 are adjacent to each other.

    player1.setArmyUnits(10);
    player2.setArmyUnits(10);



    // Execution phase
    // 1. Test each order and its validation
    std::cout << "Testing Order Execution and Validation:" << std::endl;

    // Deploy order
    deploy deployOrder(5, territory1, &player1);
    deployOrder.execute();
    std::cout << "Deploy Order Executed" << std::endl;

    // Advance order with territory conquest
    advancee advanceOrder(3, territory1, territory2, &player1);
    advanceOrder.execute();
    std::cout << "Advance Order Executed (Conquest)" << std::endl;

    // Test card giving for territory conquest
    // Assuming a function in player class that handles card giving
    player1.receiveRandomCard();
    // Negotiate order
    negotiate negotiateOrder(&player1, &player2);
    negotiateOrder.execute();
    std::cout << "Negotiate Order Executed" << std::endl;

    // Blockade order
    blockade blockadeOrder(territory2, &player2, &neutralPlayer);
    blockadeOrder.execute();
    std::cout << "Blockade Order Executed" << std::endl;

    std::cout << "\nChecking Adjacency between territories:" << std::endl;
    if (gameMap.isAdjacent(territory1, territory2)) {
        std::cout << "Territory1 and Territory2 are adjacent." << std::endl;
    } else {
        std::cout << "Territory1 and Territory2 are not adjacent." << std::endl;
    }

// Bomb order
    bomb bombOrder(territory1, &player2); // Assuming bombOrder targets territory1 and is issued by player2
    if (bombOrder.validate()) {
        bombOrder.execute();
        std::cout << "Bomb Order Executed: Half of the army units removed from " << territory1.getName() << std::endl;
        std::cout << "Remaining armies in " << territory1.getName() << ": " << territory1.getNumOfArmies() << std::endl;
    } else {
        std::cout << "Bomb Order Invalid: Target territory is either owned by the player or not adjacent." << std::endl;
    }

}
int main() {
    testOrderExecution();
    return 0;
}


