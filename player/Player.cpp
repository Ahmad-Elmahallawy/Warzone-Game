// part 2
// this is the player.cpp file where all the definitions are done
#include <iostream>
#include "Player.h"

// default constructor
Player::Player() {
    this->hand = new Hand();
    this->territories = vector<Territory *>();
    this->playerName = "no name";
    this->ordersList = new ordersList();
}

// non-default constructor
Player::Player(Hand *hand, const vector<Territory *> &territories, const string &playerName, OrdersList *ordersList)
        : hand(hand), territories(territories), playerName(playerName), ordersList(ordersList) {}

// copy constructor
Player::Player(Player &player) {
    hand = new Hand(player.hand);
    territories = vector<Territory*>(player.territories);
    ordersList = new OrdersList(*player.ordersList);
    playerName = player.playerName;

}

Player::~Player() {

}

Player &Player::operator=(const Player &player) {
    return <#initializer#>;
}

const vector<Territory *> &Player::getTerritories() const {
    return territories;
}

const string &Player::getPlayerName() const {
    return playerName;
}


OrdersList *Player::getOrdersList1() const {
    return ordersList;
}

Hand Player::getHand() const
{
    return *hand;
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

// creates a new order
void Player::issueOrder() {
    Order *order = new Order();

    Order -> addOrder(order);

    cout << "an new order is added";
}

// currently just a static territories to defend
vector<Territory*> Player::toDefend(){
    return {new Territory(), new Territory())};
}

// currently just a static territories to attack
vector<Territory*> Player::toAttack(){
    return {new Territory(), new Territory(), new Territory()};
}

// Assignment operator overload
void Player::operator=(Player &player)
{
    cout << "Player assignment operator called." << endl;
    hand = player.hand;
    ordersList = player.ordersList;
    ownedTerritories = player.ownedTerritories;
}



