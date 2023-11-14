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
    Territory* territory4 = new Territory();


    // Set territory names
    territory1->setTerritoryName("Territory1");
    territory2->setTerritoryName("Territory2");
    territory3->setTerritoryName("Territory3");
    territory4->setTerritoryName("Territory4");

    // Add territories to the map
    gameMap.addEdge(*territory1, *territory2);
    territory1->adjacentTerritories.push_back(*territory2);
    gameMap.addEdge(*territory2, *territory1);
    territory2->adjacentTerritories.push_back(*territory1);
    gameMap.addEdge(*territory2, *territory3);
    gameMap.addEdge(*territory2,*territory4);
    gameMap.addEdge(*territory4,*territory2);
    territory2->adjacentTerritories.push_back(*territory4);
    territory4->adjacentTerritories.push_back(*territory2);

    // Add territories to players
    p1->addTerritory(territory1);
    p2->addTerritory(territory2);
    p1->addTerritory(territory3);
    p1->addTerritory(territory4);

    std::cout << "Adding 50 units to p1 and p2" << std::endl;

    p1->setReinforcementPool(100);
    p2->setReinforcementPool(100);
    territory1->setNumberOfArmies(25);
    territory2->setNumberOfArmies(10);
    territory4->setNumberOfArmies(20);
    cout << "Testing Deployment Execution" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Successful Deployment: " << endl;
    Deploy d1(p1, p1, 20, territory3, territory1);
    d1.execute();
    for(int i = 0; i < p1->getTerritories().size() ; i++)
    {
        cout << p1->getTerritories()[i]->getNumberOfArmies() << endl;
    }
    cout << "Unsuccessful Deployment: " << endl;
    Deploy d2(p1,p1,20,territory2,territory1);
    d2.execute();

    cout<< "Testing Advance Execution" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Successful Advance Execution" << endl;
    Advance a(p1,p2,30,territory1,territory2);
    a.execute();
    cout << "Player 2 now has the following territories and number of army:" << endl;
    for(int i = 0; i < p2->getTerritories().size() ; i++)
    {
        cout << p2->getTerritories()[i]->getTerritoryName() << " " << p2->getTerritories()[i]->getNumberOfArmies()<< endl;
    }
    cout << "Player 1 now has the following territories and number of army:" << endl;
    for(int i = 0; i < p1->getTerritories().size() ; i++)
    {
        cout << p1->getTerritories()[i]->getTerritoryName() << " " << p1->getTerritories()[i]->getNumberOfArmies()<< endl;
    }
    cout << p2->getHand()->getHandSize();
    cout << "Unsuccessful Advance Execution" <<  endl;
    Advance a1(p1,p2,30,territory3,territory2);
    a1.execute();
    cout << "Testing Bomb Execution" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Successful Bomb Execution" << endl;
    Bomb b(p1,p2,30,territory4,territory2);
    b.execute();
    cout << "Territory 4 went from 20 to " << territory4->getNumberOfArmies() << " Army units" << endl;
    cout << "Unsuccessful Bomb Execution" << endl;
    Bomb b2(p1,p2,30,territory3,territory2);
    b2.execute();
    cout << "Another Unsuccessful Bomb Execution" << endl;
    Bomb b3(p2,p2,30,territory1,territory2);
    b3.execute();
    Player* neutralP = new Player("Neutral");
    cout << "Successful Blockade Execution" << endl;
    cout << "Territory 2 army count before: " << territory2->getNumberOfArmies() << endl;
    cout << "Testing Blockade Execution" << endl;
    cout << "------------------------------------------------" << endl;
    Blockade bl(neutralP,p2,30,territory2,territory2);
    bl.execute();
    cout << "Territory 2 army count after: " << territory2->getNumberOfArmies() << endl;
    cout << "Unsuccessful Blockade Execution" << endl;
    Blockade bl2(neutralP,p2,30,territory3,territory2);
    bl2.execute();
    cout << "Testing Airlift Execution" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Successful Airlift Execution" << endl;
    cout << "Territory 3 army count before: " << territory3->getNumberOfArmies() << endl;
    Airlift al(p1,p1,10,territory3,territory4);
    al.execute();
    cout << "Territory 3 army count after: " << territory3->getNumberOfArmies() << endl;
    cout << "Territory 4 army count now: " << territory4->getNumberOfArmies() << endl;
    cout << "Unsuccessful Airlift Execution" << endl;
    Airlift al2(p1,p1,30,territory4,territory4);
    cout << "Another Unsuccessful Airlift Execution" << endl;
    Airlift al3(p1,p1,10,territory2,territory3);
    al3.execute();
    cout<< "Testing Negotiate Execution" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Successful Negotiate Execution" << endl;
    Negotiate n1(p1,p1,20,territory2,territory1);
    n1.execute();
    cout << "Unsuccessful Negotiate Execution" << endl;
    Negotiate n2(p1,p1,20,territory3,territory1);
    n2.execute();
    cout << "Checking if player 1 can bomb player 2, Territory: 2" << endl;
    Bomb bNegotiate(p2,p1,20,territory2,territory1);
    bNegotiate.execute();









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
    delete territory4;



//
//
}