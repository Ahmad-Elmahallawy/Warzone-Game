// a file that contains a free function that creates players
// and demonstrates the featurs in Player.cpp file
#include <iostream>
#include "Player.h"
#include "Cards.h";
#include "Order.h"
#include "Map.h"
using namespace std;
void testPlayer() {

    Player player1 = Player();

    cout << "player 1 is issuing an order";
    player1.issueOrder();
    cout << "Player 1 next order is going to be: "<< player1.getOrdersList()->getNextOrder();

    Hand player1Hand = Hand();
    Player p2(&player1Hand);

    cout<<"hand object of player 1 "<<p2.getHand()<<endl;

    // TODO: add toDefend() and toAttack()





}