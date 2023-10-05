// part 2
// this is the Players.cpp file where all the definitions are done
#include <iostream>
#include "Player.h"
using namespace std;
// default constructor
Player::Player() {
    this->hand = new Hand();
    this->territories = vector<Territory *>();
    this->playerName = "no name";
    this->ordersList = new OrderList();
}



// copy constructor
Player::Player(Player &player) {
    hand = new Hand(*player.hand);
    territories = vector<Territory*>(player.territories);
    ordersList = new OrderList(*player.ordersList);
    playerName = player.playerName;

}

Player::~Player() {

}

const vector<Territory *> &Player::getTerritories() const {
    return territories;
}

const string &Player::getPlayerName() const {
    return playerName;
}


OrderList* Player::getOrdersList() const {
    return this->ordersList;
}

Hand* Player::getHand() const
{
    return  this->hand;
    //return *hand;
}

void Player::setHand(Hand *hand) {
    Player::hand = hand;
}

void Player::setTerritories(const vector<Territory *> &territories) {
    Player::territories = territories;
}

void Player::setPlayerName(const string &playerName) {
    Player::playerName = playerName;
}

int Player::getPlayerId() const {
    return playerID;
}

void Player::setPlayerId(int playerId) {
    playerID = playerId;
}


void Player::setOrdersList(OrderList *ordersList) {
    Player::ordersList = ordersList;
}

// creates a new order
void Player::issueOrder() {
    Order *order = new Order(*new Deploy());
cout << "an Issue has been ordered called. The orders are: \n";
    ordersList->add_order_list(order);
    for(int i = 0 ; i < ordersList->get_order_list()->size() ; i++){
        cout << ordersList->get_order_list()->at(i)->get_type() << endl;
        cout<< "";
    }
}

// currently just a static territories to defend
vector<Territory*> Player::toDefend() const{

    Territory *t1, *t2, *t3;
    t1 = new Territory();
    t2 = new Territory();
    t3 = new Territory();
    t1->setTerritoryName("Belgium");
    t2->setTerritoryName("Canada");
    t3->setTerritoryName("Italy");
    cout << t1->getTerritoryName() + ", " + t2->getTerritoryName() + ", " + t3->getTerritoryName();
    return {t1, t2, t3};
}

// currently just a static territories to attack
vector<Territory*> Player::toAttack() const{
    Territory *t1, *t2, *t3;
    t1 = new Territory();
    t2 = new Territory();
    t3 = new Territory();
    t1->setTerritoryName("England");
    t2->setTerritoryName("France");
    t3->setTerritoryName("Mexico");
    cout << t1->getTerritoryName() + ", " + t2->getTerritoryName() + ", " + t3->getTerritoryName();
    return {t1,t2,t3};
}



