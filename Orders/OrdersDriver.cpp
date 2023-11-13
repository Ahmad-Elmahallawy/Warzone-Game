//
///*
//contains a free function named testOrdersLists() that creates a list of orders and demonstrates that the OrdersList implemented
//Here : remove, move of the orderlist will be tested, expected result shown commented
//


#include "Orders.h"
#include "../Players/Player.h"
#include "../Map/Map.h"


void testOrderExecution()
{
    Map gameMap(5); // Assuming a map with 5 territories


    cout << "Creating 2 players" << endl;
    Player* p1 = new Player("Player 1");
    Player* p2 = new Player("Player 2");

    Territory* territory1 = new Territory();
    Territory* territory2 = new Territory();
    Territory* territory3 = new Territory();

    // Set territory names
    territory1->setTerritoryName("Territory1");
    territory2->setTerritoryName("Territory2");
    territory3->setTerritoryName("Territory3");

    // Add territories to the map
    gameMap.addEdge(*territory1, *territory2);
    gameMap.addEdge(*territory2, *territory3);

    // Add territories to players
    p1->addTerritory(territory1);
    p2->addTerritory(territory2);
    p1->addTerritory(territory3);

    std::cout << "Adding 50 units to p1 and p2" << std::endl;

    p1->setReinforcementPool(50);
    p2->setReinforcementPool(50);
    cout << "Testing Deployment Execution" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Successful Deployment: " << endl;
    Deploy d(p1,p1,20,territory3,territory1);
    d.execute();
    cout << "Unsuccessful Deployment: " << endl;
    Deploy d2(p1,p1,20,territory2,territory1);
    d2.execute();
    cout<< "Testing Advance Execution" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Successful Advance Execution" << endl;
    Advance a(p1,p2,30,territory1,territory2);
    a.execute();



//
//
//

//
//
//
//    // Execution phase
//    // 1. Test each order and its validation
//    std::cout << "Testing Order Execution and Validation:" << std::endl;
//
//    // Deploy order
//    Deploy deployOrder( &p1, territory1,5);
//    deployOrder.targetTerritory = territory1;
//    // Check if the target territory belongs to the player issuing the order
//
//        deployOrder.execute();
//        std::cout << "Deploy Order Executed" << std::endl;
//
//
////    // Advance order with territory conquest
//    Advance advanceOrder(&p2, territory1, territory2,3);
//    advanceOrder.execute();
//    std::cout << "Advance Order Executed (Conquest)" << std::endl;
//
//    // Negotiate order
//    Negotiate negotiateOrder;
//    negotiateOrder.execute();
//    std::cout << "Negotiate Order Executed" << std::endl;
//
//    // Blockade order
//    Blockade blockadeOrder;
//    blockadeOrder.execute();
//    std::cout << "Blockade Order Executed" << std::endl;
//
//
//// Bomb order
//    Bomb bombOrder; // Assuming bombOrder targets territory1 and is issued by player2
//    bombOrder.execute();
//    std::cout << "Bomb Order Executed: Half of the army units removed from " << territory1->getTerritoryName() << std::endl;
//    std::cout << "Remaining armies in " << territory1->getTerritoryName() << ": " << territory1->getTerritoryName() << std::endl;
//
//
    delete territory1;
    delete territory2;
    delete territory3;
//
//
}