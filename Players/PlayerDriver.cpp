#include "Player.h"
using namespace std;

void testPlayers()
{
    // creating a player object
    cout << "SETTING UP PLAYER'S" << endl;
    cout << "***********************************************************\n" << endl;
    cout << "PLAYER 1" << endl;
    Player* p1 = new Player();
    cout << endl;



    // issuing orders by player created
    cout << "PLAYER 1'S COMMANDS" << endl;
    cout << "***********************************************************" << endl;
    p1->issueOrder();
    p1->issueOrder();
    p1->issueOrder();

    //getting Orderlistsofar
    cout<<"Player 1'S next order: "<< p1->getOrdersList()<<endl;
    cout << endl;

    // testing the toAttack method
    cout << "PLAYER 1'S ATTACK LIST" << endl;
    cout << "***********************************************************" << endl;
    p1->toAttack();
    cout << endl;

    // testing the toDefend method
    cout << "PLAYER 1'S DEFEND LIST" << endl;
    cout << "***********************************************************" << endl;
    p1->toDefend();

}
