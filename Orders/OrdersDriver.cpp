
/*
contains a free function named testOrdersLists() that creates a list of orders and demonstrates that the OrdersList implemented
Here : remove, move of the orderlist will be tested, expected result shown commented

*/
#include "../Map/Map.h"
#include "../Orders/Orders.h"
#include "../Players/Player.h"
#include "Orders.h"
#include <iostream>
// OrdersDriver.cpp

void testOrderExecution() {
    // Assuming you have a Map object
    Map *gameMap;

    // Assuming you have two players
    Player player1((Player &) "Player1");
    Player player2((Player &) "Player2");

    // Assuming you have some territories on the map
    Territory territory1(1, 2, "Territory1", "Continent1");
    Territory territory2(2, 3, "Territory2", "Continent2");

    // Assign territories to players
    player1.addTerriorty(&territory1);
    player2.addTerriorty(&territory2);

    // Create orders
    deploy deployOrder(5, territory1, &player1);
    advancee myAdvanceeObject(3, territory1, territory2, &player1);
    bomb bombOrder(territory2, &player2);
    airlift airliftOrder(4, territory1, territory2, &player1);
    negotiate negotiateOrder(&player2, &player1);
    blockade blockadeOrder(territory1, &player1, nullptr);

    // Create order list
    orderlist orderList;

    // Add orders to the list
    orderList.addOrder(&deployOrder);
    orderList.addOrder(&myAdvanceeObject);
    orderList.addOrder(&bombOrder);
    orderList.addOrder(&airliftOrder);
    orderList.addOrder(&negotiateOrder);
    orderList.addOrder(&blockadeOrder);

    // Display map and players before execution
    std::cout << "-- Map (Before Execution) --\n";
   // gameMap.printMap();

    std::cout << "-- Players (Before Execution) --\n";
    std::cout << "Player1 Territories: " << player1.getTerritoriesString() << "\n";
    std::cout << "Player2 Territories: " << player2.getTerritoriesString() << "\n";

    // Validate and execute orders
    //orderList.validateAndExecute(gameMap);

    // Display map and players after execution
    //std::cout << "-- Map (After Execution) --\n";
    //gameMap.printMap();

    std::cout << "-- Players (After Execution) --\n";
    std::cout << "Player1 Territories: " << player1.getTerritoriesString() << "\n";
    std::cout << "Player2 Territories: " << player2.getTerritoriesString() << "\n";
}