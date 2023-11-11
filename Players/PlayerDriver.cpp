#include "Player.h"
using namespace std;

void testPlayers()
{

    Hand* playerHand = new Hand();
    Territory* t1 = new Territory();
    t1->setTerritoryName("t1");
    std::vector<Territory *> playerTerritories = {t1}; // Initialize with territories
    string playerName = "John Doe"; // Specify the player's name
    int playerID = 1;
    OrdersList* playerOrdersList = new OrdersList(/* Initialize the OrdersList object as needed */);

    Player* p1 = new Player(playerHand, playerTerritories, playerName, playerID, playerOrdersList);
    cout << p1->getPlayerName() << " has landed!";
    cout << endl;

    // issuing orders by player created
    cout << "PLAYER 1'S COMMANDS:" << endl;
//    p1->issueOrder();
//    p1->issueOrder();
//    p1->issueOrder();

    //getting Orderlistsofar
    cout<< p1->getOrdersList()<<endl;

    // testing the toAttack method
    cout << "PLAYER 1'S ATTACK LIST" << endl;
    p1->toAttack();
    cout << endl;

    // testing the toDefend method
    cout << "PLAYER 1'S DEFEND LIST" << endl;
    p1->toDefend();

    // Copy constructor demo
    Player p3(*p1);

    // Assignment operator demo
    Player p4 = *p1;


    //Stream insertion operator demo
    cout << p4;


    delete p1;
    p1 = nullptr;

}
