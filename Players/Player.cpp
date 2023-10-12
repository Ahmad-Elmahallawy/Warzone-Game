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
    this->ordersList = new OrdersList();
}



// copy constructor
Player::Player(Player &player) {
    hand = new Hand(*player.hand);
    territories = vector<Territory*>(player.territories);
    ordersList = new OrdersList(*player.ordersList);
    playerName = player.playerName;

}


Player::~Player() {
    delete this->hand;
    delete this->ordersList;
}

// returns player's territories
const vector<Territory *> &Player::getTerritories() const {
    return territories;
}

// returns player name
const string &Player::getPlayerName() const {
    return playerName;
}

// return's user's orderlist
OrdersList *Player::getOrdersList(){
    std::cout << "\n the orderlist contains :" << std::endl;
   // std::cout << ordersList  << std::endl;
    return this->ordersList;
}

// returns player hand
Hand* Player::getHand() const
{
    return  this->hand;
}

// sets player's hand
void Player::setHand(Hand *hand) {
    Player::hand = hand;
}

// setsTerritories
void Player::setTerritories(const vector<Territory *> &territories) {
    Player::territories = territories;
}

// sets Player's name
void Player::setPlayerName(const string &playerName) {
    Player::playerName = playerName;
}

// creates a new order
void Player::issueOrder() {
    Order *order = new Order(*new Deploy());
    cout << "player 1 player has issued an order";
    ordersList->addOrder(order);
    cout << "player 1 player has issued an order";
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

ostream &operator<<(ostream &os, const Player &player) {
    os << "hand: " << player.hand << " playerName: " << player.playerName
       << " playerID: " << player.playerID << " ordersList: " << player.ordersList;
    for (int i = 0; i < player.territories.size(); i++) {
        os << player.territories[i];
        if (i < player.territories.size() - 1) {
            os << ", "; // Add a comma and space for elements other than the last one
        }

        return os;
    }
}

    bool Player::operator==(const Player &rhs) const {
        return hand == rhs.hand &&
               territories == rhs.territories &&
               playerName == rhs.playerName &&
               playerID == rhs.playerID &&
               ordersList == rhs.ordersList;
    }





